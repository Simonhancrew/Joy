#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string,int> f;
    unordered_map<char,int> cnt;
 
    int findMinStep(string& board, string& hand) {
        for(char c : hand) cnt[c]++;
        f[board] = 0;
        dfs(board);
        if(f.count("")) return f[""];
        return -1;
    }
    
    string clean(string s){
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0;i < s.size();i++){
                int j = i + 1;
                while(j < s.size() && s[i] == s[j]) j++;
                if(j - i >= 3) {
                    s = s.substr(0,i) + s.substr(j);
                    flag = true;
                    break;
                }
            }
        }
        return s;
    }

    void dfs(string board){
        for(auto [x,c] : cnt){
            if(c){
                cnt[x]--;
                for(int i = 0;i <= board.size();i++){
                    auto s = clean(board.substr(0,i) + x + board.substr(i));
                    if(f.count(s) == 0 || f[s] > f[board] + 1){
                        f[s] = f[board] + 1;
                        dfs(s);
                    } 
                }
                cnt[x]++;
            }
        }
    }
};
