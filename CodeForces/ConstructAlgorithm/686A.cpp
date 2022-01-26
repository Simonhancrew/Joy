#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int n,b;
LL x;
char a;

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> n >> x;
    int res = 0;
    while(n--){
        cin >> a >> b;
        if(a == '+') x += b;
        else{
            if(x >= b) x -= b;
            else res++;
        }
    }
    cout << x << ' ' << res; 
    return 0;
}