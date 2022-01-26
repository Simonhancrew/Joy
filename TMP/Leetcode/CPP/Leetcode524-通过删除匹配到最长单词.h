#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res;
        sort(dictionary.begin(),dictionary.end());
        for(auto x : dictionary){
            int i = 0,j = 0;
            while(i < s.size() && j < x.size()){
                if(s[i] == x[j]) i++,j++;
                else i++;
            }
            if(j == x.size() && x.size() > res.size()) res = x;
        }
        return res;
    }
};