#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    typedef unordered_map<string, int> MPSI;
    int evaluate(string expression)
    {
        int k = 0;
        return dfs(expression, k, MPSI());
    }

    int get_value(string &str, int &k, MPSI vars)
    {
        int value;
        if (str[k] == '-' || isdigit(str[k]))
        {
            int i = k + 1;
            while (isdigit(str[i]))
                i++;
            value = stoi(str.substr(k, i - k));
            k = i;
        }
        else if (str[k] != '(')
        {
            string name;
            while (str[k] != ' ' && str[k] != ')')
                name += str[k++];
            value = vars[name];
        }
        else
        {
            value = dfs(str, k, vars);
        }
        return value;
    }

    int dfs(string &s, int &k, MPSI mp)
    {
        int value;
        k++; // 跳过space
        auto str = s.substr(k, 3);
        if (str == "let")
        {
            k += 4;
            while (s[k] != ')')
            {
                if (s[k] == '(' || s[k] == '-' || isdigit(s[k]))
                {
                    value = get_value(s, k, mp);
                    break;
                }
                string name;
                while (s[k] != ' ' && s[k] != ')')
                    name += s[k++];
                if (s[k] == ')')
                {
                    value = mp[name];
                    break;
                }
                k++;
                mp[name] = get_value(s, k, mp);
                k++;
            }
        }
        else if (str == "add")
        {
            k += 4; // 跳过“add ”
            int a = get_value(s, k, mp);
            k++; // 跳过space
            int b = get_value(s, k, mp);
            value = a + b;
        }
        else
        {
            // 乘法
            k += 5;
            int a = get_value(s, k, mp);
            k++;
            int b = get_value(s, k, mp);
            value = a * b;
        }
        k++; // 跳过)
        return value;
    }
};