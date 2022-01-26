#include <unordered_set>
#include <vector>

using namespace std;

// 此类问题可以看成是编辑距离的变种
// dp[i][j][k]前i个s1和前j个s2能够成功匹配，因为可以选择压缩字符成数字，不一定能恰好完全匹配到（看作通配符），此时s1多了k个字符可以在后续扩充的时候匹配掉（k为负则s2的字符更多）
// 对于i，分两种情况，是一个数的话，往前扩充这个数，s[i2:i]，只要dp[i2][j]能匹配就行，然后处理多出的字符
// 如果是一个字母的话，则只要dp[i2][j][v]中v是负数就能匹配
// 对于j同理
// 最后还要考虑i,j都是字母且相等的时候的匹配情况


class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        vector<vector<unordered_set<int>>> f(s1.size()+1,vector<unordered_set<int>>(s2.size() + 1,unordered_set<int>()));
        for(int i = 0;i <= s1.size();i++){
            for(int j = 0;j <= s2.size();j++){
                if(i == 0 && j == 0) f[i][j].insert(0);
                else{
                    if(i > 0) {
                        int i2 = i - 1;
                        if(s1[i2] >= '0' && s1[i2] <='9'){ // 当前的i是一个数字,只要f[i2][j][v - n2]能够匹配
                            int n2 = 0;
                            while(i2 >= 0 && s1[i2] >= '0' && s1[i2] <= '9'){
                                n2 += (s1[i2] - '0') * pow(10,i - i2 - 1);
                                if(n2 != 0 && s1[i2] != '0'){
                                    for(auto v : f[i2][j]){
                                        f[i][j].insert(v + n2);
                                    }
                                }
                                i2--;
                            }
                        }else{
                            for(auto v : f[i2][j]){
                                if(v < 0){
                                    f[i][j].insert(v + 1);
                                }
                            }
                        }
                    }
                    if(j > 0){
                        int j2 = j - 1;
                        if(s2[j2] >= '0' && s2[j2] <= '9'){
                            int n2 = 0;
                            while(j2 >= 0 && s2[j2] >= '0' && s2[j2] <= '9'){
                                n2 += (s2[j2]-'0') * pow(10,j - j2 - 1);
                                // cout << n2 << endl;
                                if(n2 != 0 && s2[j2] != '0'){
                                    for(auto v : f[i][j2]){
                                        f[i][j].insert(v - n2);
                                    }
                                }
                                j2--;
                            }
                        }else{
                            for(auto v : f[i][j2]){
                                if(v > 0){
                                    f[i][j].insert(v - 1);
                                }
                            }
                        }
                    }
                    if(i > 0 && j > 0 && s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i - 1] == s2[j - 1]){
                        if(f[i - 1][j - 1].count(0)){
                            f[i][j].insert(0);
                        }
                    }
                }
            }
        }
        return f[s1.size()][s2.size()].count(0);
    }
};