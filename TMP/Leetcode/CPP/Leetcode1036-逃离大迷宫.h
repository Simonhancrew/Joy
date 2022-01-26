/*  
    可以搜索的空间太大了，直接看联通性可能超时
    直接判断两个格子是否都被包围就可以了
    被包围的格子能搜索到的范围应该在[1,m * (m - 1) / 2]之间
    最大值来自利用自带的边界围城一个三角形包围当前初始点
*/
class Solution {
public:
    int n,m;
    unordered_set<string> s;
    int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1}; 
    string get(vector<int> const &t){
        return to_string(t[0]) + ' ' + to_string(t[1]);
    }
    bool bfs(vector<int> const &source,vector<int> const &target){
        auto st = s;
        queue<vector<int>> q;
        int cnt = 1;
        st.insert(get(source));
        q.push(source);
        while(q.size()){
            auto t = q.front();
            q.pop();
            for(int i = 0;i < 4;i++){
                int x = t[0] + dx[i],y = t[1] + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < n && !st.count(get({x,y}))) {
                    cnt++;
                    if(target[0] == x && target[1] == y) return true;
                    if(cnt > m * (m - 1) / 2) return true;
                    q.push({x,y});
                    st.insert(get({x,y}));
                }
            }
        }
        return false;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        for(auto block : blocked) s.insert(get(block));
        n = 1e6,m = blocked.size();
        return bfs(source,target) && bfs(target,source);
    }
};