#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 能做到O(n)的枚举就可以，实际过程中，只关心这个大小的长度的串能否完整匹配
// 一个技巧就是用哈希记录所有的单词，然后当前满足的元素能不能满足哈希中记录的元素个数
// 记得右增左减

/*
    for(int i = 0,j = 0,...;j < n;j++){
        update(j);
        if(j - i + 1 == size){
            check(i,j);
            erase(i);
            i++;
        }
    }
*/

class Solution {
public:
    vector<int> findAnagrams(const string &s,const string &p) {
        unordered_map<char, int> cnt;
        size_t n = s.size(),m = p.size();
        for (auto c: p) cnt[c] ++ ;
        vector<int> res;
        size_t tot = cnt.size();
        for(int i = 0,j = 0,sa = 0;j < n;j++){
            if(cnt.count(s[j])) {
                cnt[s[j]]--;
                if(cnt[s[j]] == 0) sa++;
            }
            if(j - i + 1 == m){
                if(sa == tot) res.push_back(i);
                if(cnt.count(s[i])){
                    if(cnt[s[i]] == 0) sa--;
                    cnt[s[i]]++;
                }
                i++;
            }

        }
        return res;
    }
};
