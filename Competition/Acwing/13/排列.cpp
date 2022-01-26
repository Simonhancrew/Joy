#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 错开一位

const int N = 110;

int a[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0,j = 2;i < n;i++,j++){
            if(j > n) j %= n;
            a[i] = j;
        }
        for(int i = 0;i < n;i++) cout << a[i] << ' ';
        cout << endl;
    }
}

