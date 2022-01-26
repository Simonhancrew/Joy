#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int,int> PII;

int x1,y1,x2,y2;

set<PII> st;

int d1[2] = {1,-1},d2[2] = {2,-2};

bool check(int x,int y){
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            int nx = x + d1[i],ny = y + d2[j];
            if(st.count({nx,ny})) return false;
            nx = x + d2[i],ny = y + d1[j];
            if(st.count({nx,ny})) return false;
        }
    }
    return true;
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    x1 = s1[0] - 'a',y1 = s1[1] - '1';
    x2 = s2[0] - 'a',y2 = s2[1] - '1';
    st.insert({x1,y1});
    st.insert({x2,y2});
    int res = 0;
    for(int i = 0;i < 8;i++){
        if(i == x1) continue;
        for(int j = 0;j < 8;j++){
            if(j == y1) continue;
            if(check(i,j)) res++;
        }
    }
    cout << res - 1 << endl;
}