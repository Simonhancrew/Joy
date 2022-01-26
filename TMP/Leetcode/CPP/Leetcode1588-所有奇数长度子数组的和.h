#include <vector>

using namespace std;

// 前缀和枚举

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        arr.insert(arr.begin(),0);
        for(int i = 1;i <= n;i++) arr[i] += arr[i - 1];
        int res = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                if(i == j) res += arr[j] - arr[j - 1];
                else if((i - j + 1) & 1){
                    res += arr[j] - arr[i - 1];
                }
            }
        }
        return res;
    }
};