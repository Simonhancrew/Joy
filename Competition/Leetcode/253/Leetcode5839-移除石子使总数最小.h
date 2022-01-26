#include <vector>
#include <queue>

using namespace std;

// 类似于huffman tree

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(auto pile:piles){
            q.push(pile);
        }
        while(k--){
            int t = q.top();
            q.pop();
            if(t == 0) return 0;
            t -= t / 2;
            q.push(t);
        }
        int res = 0;
        while(q.size()){
            int t = q.top();
            q.pop();
            res += t;
        }
        return res;
    }
};