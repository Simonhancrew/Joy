#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        int res = 0;
        for(int i = a;i < n;i++){
            if(n - i - 1 <= b) res++;
        }
        cout << res << endl;
    }
}