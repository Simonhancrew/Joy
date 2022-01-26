class Solution {
public:
    string name[10] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    string originalDigits(string s) {
        // 找唯一单词，然后去除
        int idx[] = {0,8,3,2,6,4,5,1,7,9};
        unordered_map<char,int> mp;
        for(auto ch : s) mp[ch]++;
        string res;
        for(auto num : idx){
            bool flag = true;
            while(flag) {
                for(auto ch : name[num]){
                    if(!mp[ch]){
                        flag = false;
                        break;
                    } 
                }
                if(flag) {
                    res += to_string(num);
                    for(auto ch : name[num]) mp[ch]--;
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};