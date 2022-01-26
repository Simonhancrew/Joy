// 拒绝采样的思路
// 大均匀下，范围超出了预期的感兴趣部分，对于超出的那一部分不感兴趣就抛弃那部分

class Solution {
public:
    int rand10() {
        int t = (rand7() - 1) * 7 + rand7();
        return t <= 40 ? t % 10 + 1 : rand10();
    }
};