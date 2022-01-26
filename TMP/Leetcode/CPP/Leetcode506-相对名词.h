#include <vector>

using namespace std;

class Solution {
public:
    typedef pair<int,int> PII;
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<PII> help;
        for(int i = 0;i < score.size();i++){
            help.push_back({score[i],i});
        }
        sort(help.begin(),help.end());
        vector<string> res(score.size());
        int cnt = 1;
        for(int i = score.size() - 1;i >= 0;i--){
            if(cnt == 1) res[help[i].second] = "Gold Medal";
            else if(cnt == 2) res[help[i].second] = "Silver Medal";
            else if(cnt == 3) res[help[i].second] = "Bronze Medal";
            else res[help[i].second] = to_string(cnt);
            cnt++;
        }
        return res;
    }
};