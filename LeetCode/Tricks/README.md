## 数据范围指南

一般C++的复杂度控制在10^7左右是比较稳的，前提是数据范围不卡常

1. n ≤ 30 => 指数级别
    > fs+剪枝，状态压缩dp
2. n ≤ 100 => O($ n^3 $)
    > floyd，dp，高斯消元
3. n ≤ 1000 => O($n^2$)或者O($ n^2logn $)
    > dp，二分，朴素版Dijkstra、朴素版Prim、Bellman-Ford
4. n ≤ $ 1e4 $ => O(n∗$\sqrt(n)$)或者O(n)
    > 块状链表、分块、莫队
5. n ≤ $ 1e5 $ => O($n * logn$)
    > 各种sort，线段树、树状数组、set/map、heap、拓扑排序、dijkstra+heap、prim+heap、Kruskal、spfa、求凸包、求半平面交、二分、CDQ分治、整体二分、后缀数组、树链剖分、动态树
6. n≤ $ 1e6 $ => O(n), 以及常数较小的 O($nlogn$)
    > 单调队列、 hash、双指针扫描、并查集，kmp、AC自动机，常数比较小的 O(nlogn)O(nlogn) 的做法：sort、树状数组、heap、dijkstra、spfa
7. n ≤ 1e7 => O(n)
    > 双指针扫描、kmp、AC自动机、线性筛素数
8. n≤ 1e9 => O(n$\sqrt(n)$)，
    > 判断质数
9. n ≤ 1e18 => O(logn)
    > 最大公约数，快速幂，数位DP
10. n ≤ 1e1000 => O($(logn)^2$)，
    > 高精度加减乘除
11. n ≤ 1e100000 => O($logk×loglogk$)，k表示位数，
    > 高精度加减,FFT/NTT
