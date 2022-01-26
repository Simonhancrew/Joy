#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2e3 + 10;

int t,n;
int a[N];

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int l = 1,r = n;
        while(l < r){
            while(a[l] & 1) l++;
            while(!(a[r] & 1)) r--;
            if(l < r) swap(a[l++],a[r--]);
        }
        for(int i = 1;i <= n;i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}