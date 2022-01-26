#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitmask(n);
        for(int i = 0;i < n;i++){
            for(auto ch : words[i]){
                int t = ch - 'a';
                bitmask[i] |= 1 << t;
            }
        }
        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if((bitmask[i] & bitmask[j]) == 0) res = max(res,(int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};