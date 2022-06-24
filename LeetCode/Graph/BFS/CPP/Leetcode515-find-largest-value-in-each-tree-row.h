class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (q.size())
        {
            int cur = INT_MIN, n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto t = q.front();
                cur = max(cur, t->val);
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};