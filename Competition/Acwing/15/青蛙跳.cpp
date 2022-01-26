#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a,b,k;

typedef long long LL;

// 推公式上取取整就可以了

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        LL it = 0;
        int od = (k + 2 - 1) / 2;
        int ev = k / 2;
        it = (LL)od * a - (LL)ev * b;
        cout << it << endl;
    }
}