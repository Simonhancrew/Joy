#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,res;

#if DFS
void dfs(int u){
    if(u > n) return;
    dfs(u * 10);
    dfs(u * 10 + 1);
    res++;
}

int main(){
    int n;
    cin >> n;
    dfs(1);
    cout << res << endl;
    return 0;
}
#endif  

//二进制枚举

int n;

int main(){
    cin >> n;
    int res = 0;
    for(int i = 1;i < 1 << 10;i++){
        int x = 0;
        for(int j = 0;j < 10;j++){
            x = x * 10 + ((i >> j) & 1);
        }
        if(x <= n) res++;
    }
    cout << res << endl;
    return 0;
}