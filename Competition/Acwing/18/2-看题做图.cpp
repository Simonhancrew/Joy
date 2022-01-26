#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 18267;

#ifdef ORIGINSUBMIT
int get(int n){
    if(n == 1) return 1;
    return (n - 1) * 12 + get(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << get(n) << endl; 
}

#endif