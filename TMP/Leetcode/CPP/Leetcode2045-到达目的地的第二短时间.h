/*
    最短路问题
*/
class Solution {
public:
    typedef pair<int,int> PII;
    #define x first
    #define y second 
    const int INF = 0x3f3f3f3f;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for(auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> d1(n + 1,INF),d2(n + 1,INF);
        d1[1] = 0;
        queue<PII> q;
        q.push({0,1});
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int node = t.y,d = t.x;
            for(auto ne : graph[node]) {
                if(d1[ne] > d + 1) {
                    d2[ne] = d1[ne];
                    d1[ne] = d + 1;
                    q.push({d + 1,ne});
                } else if(d1[ne] < d + 1 && d2[ne] > d + 1) {
                    d2[ne] = d + 1;
                    q.push({d + 1,ne});
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < d2[n];i++) {
            int a = ans / change,b = ans % change;
            int wait = a % 2 == 0 ? 0 : change - b; 
            ans += time + wait;
        }
        return ans;
    }
};