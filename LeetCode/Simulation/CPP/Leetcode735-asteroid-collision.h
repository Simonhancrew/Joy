/*
    栈模拟比较好想到，如何判断asteroid并且不做复杂的边界判断的
    技巧，可以给asteroid一个alive的tag，看是否被销毁了。
*/
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> stk;
        for (const auto &ast : asteroids)
        {
            bool flag = true;
            while (flag && !stk.empty() && stk.back() > 0 && ast < 0)
            {
                flag = -ast > stk.back();
                if (-ast >= stk.back())
                    stk.pop_back();
            }
            if (flag)
                stk.push_back(ast);
        }
        return stk;
    }
};