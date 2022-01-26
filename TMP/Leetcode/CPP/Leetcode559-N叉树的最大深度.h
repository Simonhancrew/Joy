#include "ADT.hpp"
#include <queue>
using namespace std;

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int t = 0;
        for(auto node : root->children){
            t = max(t,maxDepth(node));
        }
        return 1 + t;
    }
};

//层序遍历.拿到队列中一层的全部，然后对每个节点的孩子入队列
class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            ++depth;
            for(int i =0;i<size;++i){
                auto tmp = que.front();
                que.pop();
                int chiledNum = tmp->children.size();
                for(int j =0;j<chiledNum;++j){
                    if(tmp->children[j]) que.push(tmp->children[j]);
                }
            }
        }
        return depth;
    }
};