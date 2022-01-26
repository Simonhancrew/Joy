#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int n = secret.size();
        int st[26] = {0},f = 0,s = 0;
        for(int i = 0;i < n;i++){
            if(secret[i] == guess[i]) f++; 
            else st[secret[i] - '0']++;
        }
        for(int i = 0;i < n;i++){
            if(guess[i] != secret[i] && st[guess[i] - '0']) {
                s++;
                st[guess[i] - '0']--;
            }
        }
        res = to_string(f) + "A" + to_string(s) + "B";
        return res;
    }
};