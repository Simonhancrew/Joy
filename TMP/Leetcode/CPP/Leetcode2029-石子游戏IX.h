#include <cmath>
#include <vector>
using namespace std;

/*
    等价变换成一堆mod3的余数，在不考虑0的时候
    开始选1的序列就只能是：1 1 2 1 2 1 2 1 2 1 
    开始选2的序列就只能是：2 2 1 2 1 2 1 2 1 2
    
    考虑0下，偶数个的时候，等价于换手偶数次，对于必胜态没有影响
    此时先选1的话：
    1只有一个，2至少一个，Alice赢
    1至少两个：
        1比2多1个的话，选完2之后没得选了，Bob获胜
        1比2多2个的话，同样能移除所有的石子，Bob依然赢
        1比2多至少两个的话，2都移除完了，还有1，Bob胜
        
        1和2一样多，或者2的更多，最后剩下的是2,Bob不能选，Alice胜    
    此时，Alice只要选择较少一堆的开始，一定必胜，但两堆一定都不能等于0

    奇数次下，能够换手，则Alice能赢的话等价于Bob能赢，且石子没有移除完
        等价于上述的Bob胜情况的反转
*/

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for(auto st : stones) cnt[st % 3]++;
        return cnt[0] & 1 ? !(abs(cnt[1] - cnt[2]) <= 2) : !(cnt[1] == 0 || cnt[2] == 0);
    }
};