#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> mp;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int cur = root->val;
        if (root->left)
        {
            cur += dfs(root->left);
        }
        if (root->right)
        {
            cur += dfs(root->right);
        }
        mp[cur]++;
        return cur;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        dfs(root);
        vector<int> ans;
        int mx = -1;
        for (auto [k, v] : mp)
        {
            if (v > mx)
            {
                mx = v;
                ans.clear();
                ans.push_back(k);
            }
            else if (v == mx)
            {
                ans.push_back(k);
            }
        }
        return ans;
    }
};