#include <vector>

using namespace std;

// 大模拟

class LockingTree {
public:
    vector<int> p;
    vector<vector<int>> g;
    vector<int> usr;
    int n;
    LockingTree(vector<int>& parent) {
        p = parent;
        n = parent.size();
        g.resize(n);
        usr.resize(n,-1);
        for(int i = 1;i < n;i++){
            g[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(usr[num] != -1) return false;
        usr[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(usr[num] != user) return false;
        usr[num] = -1;
        return true;
    }
    
    int dfs(int u){
        int res = 0;
        if(usr[u] != -1) {
            res++;
            usr[u] = -1;
        }
        for(auto x : g[u]){
            res += dfs(x);
        }
        return res;
    }

    bool upgrade(int num, int user) {
        if(usr[num] != -1) return false;
        for(int i = p[num];i != -1;i = p[i]){
            if(usr[i] != -1) return false;
        }
        int cnt = dfs(num);
        if(cnt){
            usr[num] = user;
            return true;
        }
        return false;
    }
};