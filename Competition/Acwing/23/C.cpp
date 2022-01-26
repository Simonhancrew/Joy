#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
int n,k;

// 此类问题首先有博弈论的相关知识，其次想不到的话就先选一个爆搜看看规律
// 然后dp类的有规律问题也可以试试找规律的方法

int main()
{
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k % 3 == 0){
            n %= k + 1;
            if (n == k){
                cout << "Alice" <<endl;
                continue;
            }
        }
        if (n % 3 > 0){
            cout << "Alice" <<endl;
        }else{
            cout << "Bob" <<endl;
        }
    }
    return 0;
}