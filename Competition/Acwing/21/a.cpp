#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

// 可以使用倍增的思路，但是没有必要

int main()
{
    int t;
    cin >> t;
    while(t--){
        int k,l;
        cin >> k >> l;
        bool flag = false;
        for(int i = 0;i <= 31;i++){
            if(pow(k,i) == l) flag = true;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}