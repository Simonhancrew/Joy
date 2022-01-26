// 又是忘记开long long下WA了一把
#ifdef ORIGIN

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;

LL a[N],b[N];
int n,m;

bool check(int r){
    for(int i = 0,j = 0;i < m;i++){
        int lhs = b[i] - r,rhs = b[i] + r;
        while(j < n && (a[j] <= rhs && a[j] >= lhs)) j++;
        if(j == n) return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];
    LL l = 0,r = 2e9;
    // cout << r << endl;
    while(l < r){
        LL mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}

#endif

