#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
    建树看合法性的问题，首先根比较好想，都是祖先和子孙的关系
    成为跟的节点一定出现n - 1次。假设有毗邻关系adj,adj[root].size() == n - 1
    其次就是看构造树能不能合法，其中假设子节点的度是a，父节点的度是b，则a <= b
    并且，adj是存在关系的，其中父节点的毗邻点是要完全包含子节点的
    因为子节点的父辈都和父节点相关，子节点的子辈都和父节点相关
    但是子节点的兄弟节点不一定和子节点相关但一定和前辈节点相关
    所以是一个包含的关系
*/

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int,unordered_set<int>> adj;
        for(auto &p : pairs){
            adj[p[0]].insert(p[1]);
            adj[p[1]].insert(p[0]);
        }
        // 找根节点，一定是n - 1的，和其余的都有关系
        int root = -1;
        for(auto &[node,nei] : adj){
            if(nei.size() == adj.size() - 1) {
                root = node;
                break;
            }
        }
        if(root == -1) return 0;
        // 尝试构造树，看看合法性
        int res = 1;
        // 找到祖先点中最小deg的节点，父节点
        for(auto &[node,nei] : adj) {
            if(node == root) continue;
            int curD = nei.size();
            int parent = -1;
            int paD = INT_MAX;
            for(auto &p : nei) {
                if(adj[p].size() < paD && adj[p].size() >= curD){
                    parent = p;
                    paD = adj[p].size();
                }
            }
            if(parent == -1) return 0;

            // parent应该是完全包含cur node的全部邻居的
            for(auto &ne : nei) {
                if(ne == parent) continue;
                if(!adj[parent].count(ne)) return 0;
            }
            if(paD == curD) res = 2;
        }
        return res;
    }
};