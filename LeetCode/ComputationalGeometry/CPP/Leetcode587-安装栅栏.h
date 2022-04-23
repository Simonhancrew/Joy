/*
    pre:
    1. 向量点乘
    2. 顺时针 < 0 ,逆时针大于0，直线等于0

    凸包andrew
        1. 按照先x后y排序
        2. 将点先放入栈中，先上部分后下部分的求凸包 => (先[1,n]后[n,1])
        3. （栈内大于2个元素）如果新加入的点同top - 1的连边在top和top-1连边的上方
        需要弹出前一个点，否则直接加入，然后将相应元素做标记或取消标记
        4. 将首元素重新标记为没找到，然后从最后一个元素开始重新做一次找外边
        5. 最后记得将栈内多加的一个首元素排除
*/
class Solution
{
public:
    int cross(int x1, int y1, int x2, int y2)
    {
        return x1 * y2 - x2 * y1;
    }

    int area(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        return cross(b[0] - a[0], b[1] - a[1], c[0] - a[0], c[1] - a[1]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        int n = trees.size();
        vector<int> used(n + 1), pt(n + 2);
        sort(trees.begin(), trees.end());
        int top = 0;
        for (int i = 0; i < n; i++)
        {
            while (top >= 2 && area(trees[pt[top - 1]], trees[pt[top]], trees[i]) > 0)
            {
                used[pt[top]] = false;
                top--;
            }
            used[i] = true;
            pt[++top] = i;
        }
        used[0] = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (used[i])
                continue;
            while (top >= 2 && area(trees[pt[top - 1]], trees[pt[top]], trees[i]) > 0)
            {
                used[pt[top]] = false;
                top--;
            }
            pt[++top] = i;
        }
        top--;
        vector<vector<int>> res;
        for (int i = 1; i <= top; i++)
            res.push_back(trees[pt[i]]);
        return res;
    }
};