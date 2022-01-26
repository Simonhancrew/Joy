#include <iostream>

// Created by Simonhancrew on 2021/11/17

using namespace std;

int t,l,r;

int main(){
    cin >> t;
    while(t--){
        cin >> l >> r;
        // 如果能floor除掉且 l / a < r / a ，则[l,r]之间一定有ka可以完成取整
        // 则a要超出r的范围，a / 2 <= l mod a <= r mod a < a
        // 等价于最大化 a / 2 = l
        // r < a == r < 2l  
        cout << ((2 * l > r) ? "YES" : "NO") << endl;
    }    
    return 0;
}