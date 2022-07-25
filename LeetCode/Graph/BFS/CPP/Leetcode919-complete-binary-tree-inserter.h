/*
  如何记录一颗满树的应用。开个数组从下标1开始记录的话，左儿子就是1 * 2 ，右儿子就是1 * 2 + 1
  建树的时候BFS做一次就可以了。
最后找的时候最后一个加入的点的下标是整体的length - 1
*/
class CBTInserter {
public:
    vector<TreeNode*> rec;
    TreeNode* root_;
    CBTInserter(TreeNode* root) {
        root_ = root;
        rec = vector<TreeNode*>(1);
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            rec.push_back(t);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
    }
    
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        rec.push_back(node);
        int k = rec.size() - 1;
        int p = k / 2;
        if(p * 2 == k) rec[p]->left = node;
        else rec[p]->right = node;
        return rec[p]->val;
    }
    
    TreeNode* get_root() {
        return root_;
    }
};
