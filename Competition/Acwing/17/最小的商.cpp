#include <iostream>

using namespace std;

const int N = 110;
int a[N];


int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int res = 1e9;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = 0;i < n;i++){
            if(k % a[i] == 0){
                res = min(res,k / a[i]);
            }
        }
        cout << res << endl;
    }
}