#include<vector>
#include <string>
#include <unordered_set>

// trie维护出现过的单词，之后去深搜就可以了

using namespace std;

class Solution {
public:
    vector<vector<char>> g;
    struct Node{
        int id;
        Node* son[26];
        Node():id(-1){
            for(int i = 0;i < 26;i++) son[i] = nullptr;
        }
    };
    Node* root;
    int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
    unordered_set<int> idx;
    void insert(string& s,int id){
        auto node = root;
        for(auto ch:s){
            int t = ch - 'a';
            if(!node->son[t]){
                node->son[t] = new Node();
            }
            node = node->son[t];
        }
        node->id = id;
    }
    void dfs(int a,int b,Node* p){
        if(p->id != -1) idx.insert(p->id);
        auto t = g[a][b];
        g[a][b] = '.';
        for(int i = 0;i < 4;i++){
            int x = a + dx[i],y = b + dy[i];
            if(x >= 0 && y >= 0 && x < g.size() && y < g[0].size() && g[x][y] != '.'){
                int u = g[x][y] - 'a';
                if(p->son[u]) dfs(x,y,p->son[u]);
            }
        }
        g[a][b] = t;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        g = board;
        root = new Node();
        for(int i = 0;i < words.size();i++) insert(words[i],i);

        auto p = root;
        for(int i = 0;i < g.size();i++){
            for(int j = 0;j < g[i].size();j++){
                int t = g[i][j] - 'a';
                if(p->son[t]){
                    dfs(i,j,p->son[t]);
                }
            }
        }
        vector<string> res;
        for(auto id:idx) res.push_back(words[id]);
        return res;
    }
};