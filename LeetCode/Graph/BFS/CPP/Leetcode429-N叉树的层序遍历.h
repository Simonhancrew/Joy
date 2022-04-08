class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<Node *> q;
        q.push(root);
        while (q.size())
        {
            int n = q.size();
            vector<int> cur;
            for (int i = 0; i < n; i++)
            {
                auto t = q.front();
                q.pop();
                cur.push_back(t->val);
                for (auto ne : t->children)
                    q.push(ne);
            }
            res.push_back(cur);
        }
        return res;
    }
};