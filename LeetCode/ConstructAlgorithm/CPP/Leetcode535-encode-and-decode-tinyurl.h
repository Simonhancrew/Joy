class Solution
{
public:
    unordered_map<string, string> mp;
    string pa = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string getRandom(int n)
    {
        string res;
        while (n--)
        {
            res += pa[rand() % 62];
        }
        return res;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        while (true)
        {
            string short_url = getRandom(6);
            if (mp.count(short_url))
                continue;
            mp[short_url] = longUrl;
            return "http://hh.com/" + short_url;
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return mp[shortUrl.substr(14)];
    }
};
