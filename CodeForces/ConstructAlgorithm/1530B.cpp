#include <iostream>
#include <cstring>

// Created by Simonhancrew on 2021/11/21

using namespace std;

const int N = 25;

int g[N][N];
int t,h,w;

int main(){
    cin >> t;
    while(t--){
        cin >> h >> w;
        memset(g,0,sizeof g);
        for(int i = 0;i < w;i += 2){
            g[0][i] = 1,g[h - 1][i] = 1;
        }
        for(int i = 2;i < h - 2;i+=2){
            g[i][0] = 1,g[i][w - 1] = 1;
        }
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                cout << g[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}