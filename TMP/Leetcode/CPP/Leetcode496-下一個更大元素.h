#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//单调栈
#if 0
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> aMap;
        stack<int> aStack;

        // 输出第一个比x大的数 
        for (auto num2 : nums2) {
            while (!aStack.empty() && num2 > aStack.top()) {
                aMap[aStack.top()] = num2;
                aStack.pop();
            }
            aStack.emplace(num2);
        }

        // 没有更大的数
        while (!aStack.empty()) {
            aMap[aStack.top()] = -1;
            aStack.pop();
        }

        vector<int> ans;
        for (auto num1 : nums1)
            ans.emplace_back(aMap[num1]);

        return ans;
    }
};
#endif
// 先用单调栈建立每个数右边比他大的第一个数之后哈希映射
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> lb(nums2.size());
        stack<int> stk;
        for(int i = nums2.size() - 1;i >= 0;i--){
            int t = nums2[i];
            while(stk.size() && t >= stk.top()) stk.pop();
            if(stk.empty()) lb[i] = -1;
            else lb[i] = stk.top();
            stk.push(t);
        }
        unordered_map<int,int> mp;
        for(int i = 0;i < nums2.size();i++){
            mp[nums2[i]] = i;
        }
        vector<int> ans(nums1.size());
        for(int i = 0;i < nums1.size();i++){
            ans[i] = lb[mp[nums1[i]]];
        }
        return ans;
    }
};