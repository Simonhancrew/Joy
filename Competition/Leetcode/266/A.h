#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        int res = 0,n = word.size();
        unordered_set<char> st{'a','e','i','o','u'};
        for(int i = 0;i <= n - 5;i++){
            if(!st.count(word[i])) continue;
            int j = i;
            unordered_set<char> cur;
            while(j < n && st.count(word[j]) && cur.size() <= 5){
                cur.insert(word[j]);
                if(cur.size() == 5) res++;
                j++;
            }
        }
        return res;
    }
};