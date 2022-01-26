#include <unordered_map>
#include <string>
#include <vector>

using namespace std;


// 入度和出度

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> in,out;
        string ans;
        for(auto path : paths){
            in[path[1]]++;
            out[path[0]]++;
        }
        for(auto [k,v] : in){
            if(out[k] == 0) ans = k;
        }
        return ans;
    }
};