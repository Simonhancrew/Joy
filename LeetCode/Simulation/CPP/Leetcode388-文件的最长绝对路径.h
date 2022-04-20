/*
    文件树上的查找
    针对每一行，判断当前到那一层，然后看栈中的层数是否匹配
    随后如果是文件则针对当前行做一个判断
    因为路径之间有\号，所以实际的路径中需要加上一个值
    因为只需要长度，所以栈中存长度就可以了
*/
class Solution
{
public:
    int lengthLongestPath(string input)
    {
        int res = 0;
        stack<int> stk;
        for (int i = 0, sum = 0; i < input.size(); i++)
        {
            int k = 0;
            while (i < input.size() && input[i] == '\t')
                i++, k++;
            while (stk.size() > k)
                sum -= stk.top(), stk.pop();
            int j = i;
            while (j < input.size() && input[j] != '\n')
                j++;
            int len = j - i;
            stk.push(len), sum += len;
            if (input.substr(i, len).find('.') != -1)
            {
                res = max(res, sum + (int)stk.size() - 1);
            }
            i = j;
        }
        return res;
    }
};