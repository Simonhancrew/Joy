#include <vector>
#include <numeric>
using namespace std;

#if 0
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        // for(auto num:chalk) sum += num;
        int sum = accumulate(chalk.begin(),chalk.end(),0);
        while(sum <= k) k -= sum; 
        for(int i = 0;;i++){
            int tr = i % chalk.size();
            if(k < chalk[tr]) return tr;
            else{
                k -= chalk[tr];
            }
        }
        return 0;
    }
};
#endif

#define BINARYSEARCH
#ifndef BINARYSEARCH
// 求和total，取模得到一次遍历的k
class Solution {
public:
    typedef long long LL;
    int chalkReplacer(vector<int>& chalk, int k) {
        LL sum = accumulate(chalk.begin(),chalk.end(),0ll);
        k = k % sum;
        int res = -1,n = chalk.size();
        for(int i = 0;i < n;i++){
            if(chalk[i] > k) {
                res = i;
                break;
            }
            else k -= chalk[i];
        }
        return res;
    }
};
#endif


#ifdef  BINARYSEARCH 
#include <algorithm>

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        if(chalk[0] > k) return 0;
        for(int i = 1;i < n;i++){
            chalk[i] += chalk[i - 1];
            if(chalk[i] > k) return i;
        }
        k %= chalk.back();
        return upper_bound(chalk.begin(),chalk.end(),k) - chalk.begin();
    }
};
#endif