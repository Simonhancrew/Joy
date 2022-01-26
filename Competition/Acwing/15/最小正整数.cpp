#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

// 这种末尾有多少个0的题目的思路就是分解

/*
    k个0，分解成(2 ** k) * (5 ** k)
    对于本题，分析以下，只要分解完之后后面加k个0就可以了
*/

int n,k;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0;i < k;i++){
            if(n % 2 == 0) n /= 2;
            if(n % 5 == 0) n /= 5;
        }
        cout << (LL)n * (int)pow(10,k) << endl;
    }
}