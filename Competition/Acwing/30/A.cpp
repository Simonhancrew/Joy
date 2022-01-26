#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 10;

int n,h;
int a[N];


int main(){
    cin >> n >> h;
    int res = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] > h) res += 2;
        else if(a[i] <= h) res++;
    }
    cout << res << endl;
}