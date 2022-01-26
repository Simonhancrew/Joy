#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int n;

// 画图就行了，有序的话是一条直线。

int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i < n - 1;i++){
        if((a[i] < a[0] && a[i] < a[i + 1])|| (a[i] > a[0] && a[i] > a[i + 1])){
            cout << 3 << endl;
            cout << 1 << ' ' << i + 1 << ' ' << i + 2 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}

// 想不到就用下面的这种

#if 0


int a[N],lmax[N],lmin[N],rmin[N],rmax[N];
int n;


int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    lmax[1] = 1,lmin[1] = 1;

    // 前缀最大最小
    for(int i = 2;i <= n;i++){
        lmax[i] = i,lmin[i] = i;
        if(a[lmax[i - 1]] > a[i]) lmax[i] = lmin[i - 1];
        if(a[lmin[i - 1]] < a[i]) lmin[i] = lmax[i - 1];
    }
    rmax[n] = n,rmin[n] = n;
    for(int i = n - 1;i >= 1;i--){
        rmax[i] = i,rmin[i] = i;
        if(a[rmax[i + 1]] > a[i]) rmax[i] = rmax[i + 1];
        if(a[rmin[i + 1]] < a[i]) rmin[i] = rmin[i + 1];
    }
    
    // 找山峰山谷
    for(int i = 2;i < n;i++){
        // 山谷
        if(a[i] < a[lmax[i - 1]] && a[i]< a[rmax[i + 1]]){
            cout << 3 << endl;
            cout << lmax[i - 1] << ' ' << i << ' ' << rmax[i + 1] << endl;
            return 0;
        }else if(a[i] > a[lmin[i - 1]] && a[i] > a[rmin[i + 1]]){ // 找山峰
            cout << 3 << endl;
            cout << lmin[i - 1] << ' ' << i << ' ' << rmin[i + 1] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}



#endif