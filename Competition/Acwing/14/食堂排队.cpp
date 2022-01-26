#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;

PII a[N];

int n;

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            int l,r;
            cin >> l >> r;
            a[i] = {l,r};
        }
        sort(a + 1, a + n,[](auto& lhs,auto& rhs) {
            return lhs.first < rhs.first;
        });

        for(int i = 1,wait = 1;i <= n;i++){
            if(wait == 1 || wait <= a[i].second){
                cout << wait << ' ';
                wait++;
            }else{
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}