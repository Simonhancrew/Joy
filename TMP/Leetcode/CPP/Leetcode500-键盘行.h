#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> st = {
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'}
        };
        vector<string> res;
        for(auto word : words){
            auto bk = word;
            transform(word.begin(),word.end(),word.begin(),::tolower);
            for(int i = 0;i < 3;i++){
                bool flag = true;
                for(auto ch : word){
                    if(!st[i].count(ch)){
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    res.push_back(bk);
                    break;
                }
            }
        }
        return res;
    }
};