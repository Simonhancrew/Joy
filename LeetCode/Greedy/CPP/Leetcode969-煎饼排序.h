#include <vector>
using namespace std;
#if 0
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int len = A.size();
        if(len == 0|| len == 1){
            return {};
        }
        int a[110];
        for(int i = 0;i<len;i++){
            a[A[i]] = i+1;
        }
        int max_A = len;//当前最大值
        vector<int> result;
        while(max_A){//max_A为当前需要翻转的最大位置
            int max_A_place = a[max_A];//当前最大值的位置
            result.push_back(max_A_place);//最大值及之前部分反转
            result.push_back(max_A);//全体反转
            for(int i = 0;i<len;i++){
                if(A[i]>max_A){
                    continue;//已经排好的部分index不用更新
                }
                if(a[A[i]]>max_A_place){
                    a[A[i]] = max_A-a[A[i]]+1;//当前最大值之后的部分更新位置
                }
                else{
                    a[A[i]] = max_A-max_A_place+a[A[i]];//当前最大值之前的位置更新
                }
            }
        }
        return result;
    }
};
#endif
/*
    每次找到最大的，反转到头部然后翻转到相应位置
    如果已经在最佳位置就什么都不做
*/
class Solution {
 public:
  vector<int> pancakeSort(vector<int>& arr) {
    vector<int> res;
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) {
      int mx = 0;
      for (int j = 0; j <= i; j++)
        if (arr[j] > arr[mx]) mx = j;
      if (mx == i) continue;
      reverse(arr.begin(), arr.begin() + mx + 1);
      res.push_back(mx + 1);
      reverse(arr.begin(), arr.begin() + i + 1);
      res.push_back(i + 1);
    }
    return res;
  }
};