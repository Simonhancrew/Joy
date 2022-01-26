#include <iostream>

using namespace std;


int t,n;
string s;

int main(){
    // freopen("input.txt","r",stdin);
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 0;i < n;i++) cout << s[n - 1];
        cout << endl;
    }
    return 0;
}