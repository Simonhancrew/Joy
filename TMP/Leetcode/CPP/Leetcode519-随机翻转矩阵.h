#include <vector>
#include <unordered_map>

using namespace std;

/* 
    扩展成一维的情况。开始每个位置对应的都是自己,每次随机选择一个数删除
    删除的数和末尾的数替换，用一个哈希表记录每个位置的真实值
*/
class Solution {
public:
    Solution(int m, int n) {
        _m = m,_n= n;
        k = m * n;
    }
    
    vector<int> flip() {
        int idx = rand() % k;
        int real = idx;
        if(hash.count(idx)) real = hash[idx];
        if(hash.count(k - 1)) {
            hash[idx] = hash[k - 1];
            hash.erase(k - 1);
        }else{
            hash[idx] = k - 1;
        }
        k--;
        return {real / _n,real % _n};
    }
    
    void reset() {
        k = _m * _n;
        hash.clear();
    }
private:
    int _m,_n,k;
    unordered_map<int,int> hash;
};