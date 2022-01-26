#include <iostream>
#include <algorithm>

using namespace std;

int t,n;
const int N = 110;
int a[N];

// 脑筋急转弯，分奇偶，偶数直接pair互换就可以，奇数因为最少3个，直接操作前3个之后
// 对后面的偶数还是选择pair互换

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++) a[i] = i;
        if(n & 1) {
            a[1] = 3,a[2] = 1,a[3] = 2;
            for(int i = 4;i <= n;i+=2){
                swap(a[i],a[i + 1]);
            }
        }else{
            for(int i = 1;i <= n;i += 2){
                swap(a[i],a[i + 1]);
            }
        }
        for(int i = 1;i <= n;i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}