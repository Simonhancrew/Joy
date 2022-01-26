#include <iostream>
#include <algorithm>

// Created by Simonhancrew on 2021/10/30

using namespace std;

const int N = 110;
int t,n;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        sort(a,a + n);
        int mini = a[0];
        int l = 0,r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid] <= mini) l = mid;
            else r = mid - 1;
        }
        cout << n - (l + 1) << endl;
    }
    return 0;
}