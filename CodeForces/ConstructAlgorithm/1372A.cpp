#include <iostream>

using namespace std;

int t,n;

int main(){
    // freopen("input.txt","r",stdin);
    // make all ele equal 1
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++) cout << 1 << ' ';
        cout << endl;
    }
    return 0;
}