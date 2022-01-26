#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int a[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    int mx = a[0];
    for(int i = 1;i < n;i++) mx = max(a[i],mx);
    cout << (mx ^ a[n - 1]) << endl;
}