#include <iostream>
#include <algorithm>

// Created by Simonhancrew on 2021/11/25
 
using namespace std;

const int N = 110;
 
char g[N][N];
 
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) cin >> g[i];
    int res = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - 1;j++){
            if(g[i][j] == '.') continue;
            for(int k = j + 1;k < n;k++){
                if(g[i][k] == 'C') ++res;
            }
        }
        for(int j = 0;j < n - 1;j++){
            if(g[j][i] == '.') continue;
            for(int k = j + 1;k < n;k++){
                if(g[k][i] == 'C') ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}