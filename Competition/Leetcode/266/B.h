class Solution {
public:
    typedef long long LL;
    long long countVowels(string word) {
        LL res = 0;
        int n = word.size();
        vector<int> a(n + 1);
        unordered_set<char> st{'a','e','i','o','u'};
        for(int i = 0;i < n;i++){
            if(st.count(word[i])) res += (LL)(n - i) * (i + 1);
        }
        return res;
    }
};