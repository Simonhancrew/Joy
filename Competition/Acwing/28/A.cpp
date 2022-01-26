#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s;

int main(){
    cin >> s;
    int res = 0,n = s.size();
    for(int i = 0;i <= n - 3;i++){
        if(s[i] != 'Q') continue;
        for(int j = i + 1;j <= n - 2;j++){
            if(s[j] != 'A') continue;
            for(int k = j + 1;k < n;k++) {
                if(s[k] != 'Q') continue;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}