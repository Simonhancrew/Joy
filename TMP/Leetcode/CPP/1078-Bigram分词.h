class Solution {
public:
    vector<string> findOcurrences(string s, string first, string second) {
        vector<string> res,rec;
        int n = s.size();
        for(int i = 0;i < n;i++){
            int j = i;
            while(s[j] != ' ' && j < n) j++;
            rec.push_back(s.substr(i,j - i));
            i = j;
        }
        for(int i = 0;i < rec.size();i++){
            if(rec[i] == first && i + 2 < rec.size()){
                if(rec[i + 1] == second) {
                    res.push_back(rec[i + 2]);
                }
            }
        }
        return res;
    }
};
