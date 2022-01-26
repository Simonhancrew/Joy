#include <iostream>
#include <cstring>

// Created by Simonhancrew on 2021/11/13

using namespace std;

const int N = 110;

int t,n,k;
int a[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        memset(a,0,sizeof a);
        if(2 * k + 1 > n) cout << -1 << endl;
        else{
            int num = n;
            for(int i = 2;i < n && k;i += 2){
                a[i] = num--;
                k--;                
            }
            int cur = 1;
            for(int i = 1;i <= n;i++){
                if(!a[i]) a[i] = cur++;
            }
            for(int i = 1;i <= n;i++) cout << a[i] << ' ';
            cout << endl;
        } 
    }
    return 0;
}