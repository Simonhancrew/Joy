class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        vector<string> rec;
        unordered_set<string> ban;
        for (auto &word : banned)
            ban.insert(word);
        int n = paragraph.size();
        for (int i = 0; i < n; i++)
        {
            if (paragraph[i] == ' ')
                continue;
            int j = i;
            while (j < n && isalpha(paragraph[j]))
                j++;
            string cur = paragraph.substr(i, j - i);
            for (auto &x : cur)
                x = tolower(x);
            if (ban.count(cur))
            {
                i = j;
                continue;
            }
            rec.push_back(cur);
            i = j;
        }
        unordered_map<string, int> mp;
        string res;
        int cnt = 0;
        for (auto &word : rec)
        {
            mp[word]++;
            if (mp[word] > cnt)
            {
                cnt = mp[word];
                res = word;
            }
        }
        return res;
    }
};