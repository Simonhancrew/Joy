/*
    多路归并
    b[0]a[0],b[1]a[0],.....b[n-1]a[0]
    b[0]a[1]...............b[n-1]a[1]
    ...
    b[0]a[n-1].............b[n-1]a[n-1]
    用堆存储遍历所得值，然后每次插入下一个遍历需要的值
*/
class Solution {
public:
    using VI = vector<int>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<VI,vector<VI>,greater<VI>> heap; 
        int n = nums1.size(),m = nums2.size();
        for(int i = 0;i < m;i++) heap.push({nums1[0] + nums2[i],0,i});
        while(k-- && heap.size()){
            auto t = heap.top();
            heap.pop();
            ans.push_back({nums1[t[1]],nums2[t[2]]});
            if(t[1] + 1 < n) heap.push({nums1[t[1] + 1] + nums2[t[2]],t[1] + 1,t[2]});
        }
        return ans;
    }
};