#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        string op;
        int n = s.size();
        int i = 0,j = n - 1;
        while(i < j){
            while(i < j && !st.count(s[i])) i++;
            while(i < j && !st.count(s[j])) j--;
            if(i < j) swap(s[i++],s[j--]);
        }
        return s;
    }
};