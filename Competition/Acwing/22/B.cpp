#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n,m;
int a[N],b[N],cnt[N];

// 判断多少比展示小且关系不和的就行
// 二分的找到有多少比当前战士的战斗力小

int main(){
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1,b + n + 1);
    while(m--){
        int x,y;
        cin >> x >> y;
        if(a[x] > a[y]) cnt[x]++;
        else if(a[x] < a[y]) cnt[y]++;
    }
    for(int i = 1;i <= n;i++){
        int l = 1,r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(a[i] <= b[mid]) r = mid;
            else l = mid + 1;
        }
        cout << r - 1 - cnt[i] << ' ';
    }
    return 0;
}