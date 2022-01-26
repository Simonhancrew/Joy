#include <iostream>
#include <algorithm>
#include <cstring>

// Created by Simonhancrew on 2021/11/30

using namespace std;

const int N = 110;

int t,n;
int a[N],b[N],c[N];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++) cin >> b[i];
        for(int i = 0;i < n;i++) cin >> c[i];
        int pre;
        for(int i = 0;i < n;i++){
            if(i == 0) cout << a[i] << ' ',pre = a[i];
            else if(i != n - 1){
                if(a[i] != pre) cout << a[i] << ' ',pre = a[i];
                else if(b[i] != pre) cout << b[i] << ' ',pre = b[i];
                else cout << c[i] << ' ',pre = c[i]; 
            }else{
                if(a[i] != pre && a[i] != a[0]) cout << a[i];
                else if(b[i] != pre && b[i] != a[0]) cout << b[i];
                else cout << c[i];
            }
        }
        cout << endl;
    }
    return 0;
}