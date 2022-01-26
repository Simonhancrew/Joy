#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e3 + 10;

int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a,a + n);
    for(int i = n - 1;i >= 0;i--){
        int t  = sqrt(a[i]);
        // sqrt负数是不报错的，看编译器
        if(a[i] < 0){
            cout << a[i] <<endl;
            return 0;
        }
        if(t * t != a[i]){
            cout << a[i] << endl;
            return 0;
        }
    }
}