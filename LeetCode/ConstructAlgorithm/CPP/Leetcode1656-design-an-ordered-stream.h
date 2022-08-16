class OrderedStream
{
public:
    unordered_map<int, string> mp;
    int ptr = 1, sz = 0;
    OrderedStream(int n) : ptr(1), sz(n) {}

    vector<string> insert(int idKey, string value)
    {
        vector<string> ans;
        mp.insert({idKey, value});
        if (!mp.count(ptr))
        {
            return ans;
        }
        while (mp.count(ptr))
        {
            ans.push_back(mp[ptr++]);
        }
        return ans;
    }
};