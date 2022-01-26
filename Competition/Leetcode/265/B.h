#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        auto t = head;
        while(t){
            nums.push_back(t->val);
            t = t->next;
        }
        int n = nums.size();
        if(n <= 2) return vector<int> {-1,-1};
        vector<int> all;
        for(int i = 1;i < n - 1;i++){
            if(check(i)) all.push_back(i);
        }
        if(all.size() < 2) return vector<int> {-1,-1};  
        sort(all.begin(),all.end());
        int mx = all.back() - all[0],mn = int(1e9);
        for(int i = 0;i < all.size() - 1;i++){
            mn = min(mn,all[i + 1] - all[i]);
        }
        return vector<int> {mn,mx};
    }
    
    bool check(int u){
        if(nums[u] > nums[u - 1] && nums[u] > nums[u + 1]) return true;
        if(nums[u] < nums[u - 1] && nums[u] < nums[u + 1]) return true;
        return false;
    }
};