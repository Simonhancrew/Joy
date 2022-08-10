class Solution
{
public:
    using PII = pair<int, int>;

    PII get(string s)
    {
        int a = 0, b = 0;
        if (s[0] != '+' && s[0] != '-')
            s = "+" + s;

        for (int i = 0; i < s.size(); i++)
        {
            int j = i + 1;
            while (j < s.size() && isdigit(s[j]))
                ++j;
            int c = 1;
            if (i + 1 <= j - 1)
                c = stoi(s.substr(i + 1, j - i - 1));
            if (s[i] == '-')
                c = -c;
            if (j < s.size() && s[j] == 'x')
            {
                a += c;
                i = j;
            }
            else
            {
                b += c;
                i = j - 1;
            }
        }
        return {a, b};
    }

    string solveEquation(string equation)
    {
        int idx = equation.find('=');
        auto lhs = get(equation.substr(0, idx)), rhs = get(equation.substr(idx + 1));
        int a = lhs.first - rhs.first, b = rhs.second - lhs.second;
        cout << lhs.first << ' ' << lhs.second << endl;
        if (!a)
        {
            if (!b)
                return "Infinite solutions";
            else
                return "No solution";
        }
        return "x=" + to_string(b / a);
    }
};