#include <vector>
#include <algorithm>

using namespace std;

// 最开始的思路来自最长上升子序列，但是数据范围1e5,n*n的复杂度肯定过不掉
// 从定长的思路来考虑优化，
#if 0
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int> f(n,1);
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(arr[j] - arr[i] == difference) {
                    f[j] = max(f[j],f[i] + 1);
                }
            }
        } 
        return *max_element(f.begin(),f.end());
    }
};
#endif

#include <unordered_map>

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> f;
        int ans = 1;
        for(auto a : arr){
            f[a] = f[a - difference] + 1;
            ans = max(ans,f[a]);
        }
        return ans;
    }
};