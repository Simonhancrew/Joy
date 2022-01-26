#include <vector>
using namespace std;

/*
    可以转化成一个多路归并的问题，但是在此处的数组是严格按照升序排列的
    可以考虑一个二分的操作，当前是第K小的元素，值为x
    则>=x的元素应该有k个，所以二分[0,1)区间中的值，看看当前有多少个arr[j] / arr[i]的值是小于当前值mid的
    如果恰好为k个的时候就找到了解

    在求当前满足mid条件下的所有可能组数的时候，可以用一个双指针算法动态的维护最大可以到达的j
    然后对于每个i前进，此时能够加入到res中的就是j+1个可能值
    实际的计算过程中，可以在全局记录一个解，当满足情况的时候就直接将这个解记录
    确定情况下，最后一定能够执行到可行解
*/ 

class Solution {
public:
    static constexpr double eps = 1e-8;
    int a,b;
    int get(vector<int> &arr,double mid){
        int res = 0;
        int n = arr.size();
        for(int i = 0,j = 0;i < arr.size();i++){
            while(j + 1 < n && (double)arr[j + 1] / arr[i] <= mid) j++;
            if((double)arr[j] / arr[i] <= mid) res += j + 1;
            if(fabs((double)arr[j] /arr[i] - mid) < eps) {
                a = arr[j],b = arr[i];
            }
        }
        return res;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double l = 0,r = 1;
        while(r - l > eps){
            double mid = (l + r) / 2.0;
            if(get(arr,mid) >= k) r = mid;
            else l = mid;
        }
        get(arr,r);// 前面其实已经能够执行到
        return {a,b};
    }
};