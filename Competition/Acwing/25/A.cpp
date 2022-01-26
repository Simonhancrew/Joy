#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        if(i & 1) {
            cout << "I hate ";
            if(i == n) cout << "it";
            else cout << "that ";
        }else{
            cout << "I love ";
            if(i == n) cout << "it";
            else cout << "that ";
        }
    }
    return 0;
}
