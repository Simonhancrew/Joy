#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int> q;
        q.push(start);
        int op = 0;
        unordered_set<int> st;
        st.insert(start);
        while(q.size()){
            int n = q.size();
            op++;
            for(int i = 0;i < n;i++){   
                int cur = q.front();
                q.pop();
                for(auto x : nums){
                    int t1 = cur + x,t2 = cur - x,t3 = cur ^ x;
                    if(t1 == goal || t2 == goal || t3 == goal) return op;
                    if(t1 >= 0 && t1 <= 1000){
                        if(!st.count(t1)) q.push(t1),st.insert(t1);
                    } 
                    if(t2 >= 0 && t2 <= 1000){
                        if(!st.count(t2)) q.push(t2),st.insert(t2);
                    }
                    if(t3 >= 0 && t3 <= 1000){
                        if(!st.count(t3)) q.push(t3),st.insert(t3);
                    }
                }
            }
        }
        return -1;
    }
};