#include <vector>

// 直接bellmanford最短路模型就可以

using namespace std;

class Solution {
public:
    vector<int> dist;
    int bellman_ford(int n,vector<vector<int>>& flights, int src, int dst, int k){
        dist[src] = 0;
        for(int i = 0;i < k + 1;i++){
            auto backup = dist;
            for(int j = 0;j < flights.size();j++){
                int a = flights[j][0],b = flights[j][1],w = flights[j][2];
                dist[b] = min(dist[b],backup[a] + w);
            }
        }
        if(dist[dst] > 0x3f3f3f3f / 2) return -1;
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        dist.resize(n,0x3f3f3f3f);
        if(bellman_ford(n,flights,src,dst,k) == -1) return -1;
        else return dist[dst];
    }
};