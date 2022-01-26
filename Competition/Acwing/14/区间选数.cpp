#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int l1,r1,l2,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int a = l1,b = l2;
        while(b <= r2 && a==b){
            b++;
        }
        cout << a << ' ' << b << endl;
    }
}