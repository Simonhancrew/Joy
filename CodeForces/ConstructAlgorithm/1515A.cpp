#include <iostream>
#include <algorithm>
#include <numeric>

// Created by Simonhancrew on 2021/11/08

using namespace std;
const int N = 110;

int t,n,x;
int w[N];

/* 
    一个贪心的问题，总和是sum的话分三种情况
    1. 总和刚好是x，一定WA
    2. 总和小于x,原位输出
    3. 总和大于val,排序之后求和，正好等于x的话就要交换一下了
*/
int main(){
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i = 0;i < n;i++) cin >> w[i];
        int tot = accumulate(w,w + n,0);
        if(tot == x) cout << "NO" <<endl;
        else if(tot < x){
            cout << "YES" << endl;
            for(int i = 0;i < n;i++) {
                cout << w[i] << ' ';
            }
            cout << endl;
        }else{
            cout << "YES" << endl;
            sort(w,w + n);
            int cur = 0;
            for(int i = 0;i < n;i++){
                cur += w[i];
                if(x == cur) {
                    // 因为tot > x，所以等于x的时候后面一定有东西
                    swap(w[i],w[i + 1]);
                    break;
                }
            }
            for(int i = 0;i < n;i++) cout << w[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}