class Solution
{
public:
    vector<string> rec;

    void split(string const &ip, char tar)
    {
        int n = ip.length();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && ip[j] != tar)
                j++;
            rec.push_back(ip.substr(i, j - i));
            i = j;
            if (i == n - 1)
                rec.push_back("");
        }
    }

    string check4(string const &ip)
    {
        split(ip, '.');
        if (rec.size() != 4)
            return "Neither";
        for (const string &s : rec)
        {
            if (s.size() > 3 || s.empty())
                return "Neither";
            if (s.size() > 1 && s[0] == '0')
                return "Neither";
            for (const char &t : s)
            {
                if (t < '0' || t > '9')
                    return "Neither";
            }
            int num = stoi(s);
            if (num > 255)
                return "Neither";
        }
        return "IPv4";
    }

    string check6(string const &ip)
    {
        split(ip, ':');
        if (rec.size() != 8)
            return "Neither";
        for (string const &s : rec)
        {
            if (s.empty() || s.size() > 4)
                return "Neither";
            for (char const &c : s)
            {
                if (!check(c))
                    return "Neither";
            }
        }
        return "IPv6";
    }

    bool check(const char c)
    {
        if (c >= '0' && c <= '9')
            return true;
        if (c >= 'a' && c <= 'f')
            return true;
        if (c >= 'A' && c <= 'F')
            return true;
        return false;
    }

    string validIPAddress(string queryIP)
    {
        if (queryIP.find('.') != -1 && queryIP.find(':') != -1)
            return "Neither";
        int n = queryIP.length();
        if (queryIP.find('.') != -1)
            return check4(queryIP);
        if (queryIP.find(':') != -1)
            return check6(queryIP);
        return "Neither";
    }
};