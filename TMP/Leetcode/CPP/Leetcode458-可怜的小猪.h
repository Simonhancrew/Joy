#include <cmath>

/*
    信息论的题目
    n桶水中有一桶水是毒药的信息熵H(A) = -log(1 / n)
    最多能尝试的轮次是t / d = k,则一只猪喝完之后可能会有k + 1种状态
    第一轮完了死掉，。。。。。第k + 1轮完了死掉
    则假设x只猪，这些猪k轮之后的状态就是alpha = pow(k + 1,x)
    其信息熵就是H(B) = -log(1 / alpha)
    后者的信息要能推出前者的信息，必然是后者的信息熵要大
    则不难得到最后的结果
*/

class Solution {
public:
    int poorPigs(int n, int d, int t) {
        int rd = t / d;
        return ceil(log(n) / log(rd + 1));
    }
};