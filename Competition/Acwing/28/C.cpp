#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110;

int a[N],d[N],p[N];
int n;
vector<int> A[N],B[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a,int b){
    if(a < 1 || a > n) return;
    p[find(a)] = find(b);
}

/*
    左右d的一堆点等价于一个连通区域
    并查集合并这些区域，然后看这些区域是否出现的数都一样就ok了
*/ 

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++) p[i] = i;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> d[i];
    for(int i = 1;i <= n;i++) {
        merge(i + d[i],i);
        merge(i - d[i],i);
    }
    for(int i = 1;i <= n;i++){
        A[find(i)].push_back(i);
        B[find(i)].push_back(a[i]);
    }
    bool flag = true;
    for(int i = 1;i <= n;i++){
        sort(B[i].begin(),B[i].end());
        if(A[i] != B[i]) {
            flag = false;
            break;
        }
    }
    if(flag) cout << "YES" <<endl;
    else cout << "NO" <<endl;
    return 0;
}
