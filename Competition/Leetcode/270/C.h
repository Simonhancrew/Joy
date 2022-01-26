#if 0 
class Solution {
public:
    string rec;
    string getDirections(TreeNode* root, int st, int dt) {
        string shs,dhs;
        string res;
        dfs(root,st,shs);
        auto cp = rec;
        dfs(root,dt,dhs);
        int bg = -1;
        for(int i = 0;i < cp.size();i++){
            if(cp[i] != rec[i]) break;
            bg = i;
        }
        // cout << bg << endl;
        for(int i = bg + 1;i < cp.size();i++) res += 'U';
        for(int i = bg + 1;i < rec.size();i++) res += rec[i];
        return res;
    }
    void dfs(TreeNode* root,int value,string& path){
        if(!root) return;
        // cout << path << endl;
        if(root->val == value) {
            rec = path;
            return;
        }
        path += "R";
        dfs(root->right,value,path);
        path.pop_back();
        path += "L";
        dfs(root->left,value,path);    
        path.pop_back();
    }
};
#endif 

#ifdef BETTER 
class Solution {
public:
    string path, paths, pathd;
    void dfs(TreeNode* root, int s, int d) {
        if(root->val == s) paths = path;
        if(root->val == d) pathd = path;
        if(root->right) path += 'R', dfs(root->right, s, d), path.pop_back();
        if(root->left) path += 'L', dfs(root->left, s, d), path.pop_back();
    }
    string getDirections(TreeNode* root, int s, int d) {
        dfs(root, s, d);
        int i = 0, j = 0;
        while(paths[i] == pathd[j]) i++, j++;
        return string(paths.size() - i, 'U') + pathd.substr(j);
    }
};
#endif 