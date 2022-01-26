#include <vector>
#include <string>

using namespace std;
#define MAX_CHAR 26

struct Node{
    bool isend;
    vector<Node*> child;
    Node():isend(false),child(MAX_CHAR){
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }
    void addWord(string word) {
        auto p = root;
        for(int i = 0;i < word.size();i++){
            int cur = word[i] - 'a';
            if(p->child[cur] == nullptr) p->child[cur] = new Node();
            p = p->child[cur]; 
        }
        p->isend = true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }
    
    bool dfs(Node* root,string& word,int idx){
        if(idx == word.size()) return root->isend;
        if(word[idx] == '.'){
            for(int i = 0;i < MAX_CHAR;i++){
                // 任意一个能找到就是true
                if(root->child[i] && dfs(root->child[i],word,idx+1)) {
                    return true;
                }
            }
        }else{
            int u = word[idx] - 'a';
            if(root->child[u]){
                return dfs(root->child[u],word,idx+1);
            }
           
        }
        return false;
    } 
private:
    Node* root;
};