#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/10/28

using namespace std;

const int N = 2e5 + 10;

int t,n;
int a[N];

int main(){
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        int t = (n >> 1);
        if(t & 1) cout << "NO" <<endl;
        else{
            cout << "YES" <<endl;
            int s1 = 0,s2 = 0; 
            for(int i = 0,j = 2;i < t;i++,j += 2){
                a[i] = j;
                s1 += j;
            }
            for(int i = t,j = 1;i < n - 1;i++,j += 2){
                a[i] = j;
                s2 += j;
            }
            a[n - 1] = s1 - s2;
            for(int i = 0;i < n;i++) cout << a[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}