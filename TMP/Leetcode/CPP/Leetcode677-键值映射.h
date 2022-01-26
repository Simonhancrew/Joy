#include <unordered_map>

using namespace std;

class MapSum {
public:
    MapSum() {
        mp.clear();
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for(auto [k,v] : mp){
            bool flag = true;
            for(int i = 0;i < prefix.size();i++){
                if(prefix[i] != k[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) res += v;
        }
        return res;
    }
private:
    unordered_map<string,int> mp;
};
