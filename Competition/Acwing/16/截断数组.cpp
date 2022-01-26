#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;

// 枚举第一刀和第二刀切在哪里

LL a[N];
int n;

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) a[i] += a[i - 1];
    if(n <= 2 || a[n - 1] % 3) cout << 0 << endl;
    else{
        LL cnt = 0,cnt1 = 0,sum = a[n - 1] / 3;
        for(int i = 0;i < n - 1;i++){
            if(a[i] == sum * 2) cnt1 += cnt;    
            if(a[i] == sum) cnt++;
        }
        cout << cnt1 << endl;
    }
    return 0;
}