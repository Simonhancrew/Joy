#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int p1,p2,p3,p4,a,b;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    int p = min({p1,p2,p3,p4}) - 1;
    if(p < a) {
        cout << 0 << endl;
        return 0;
    }
    cout << min(p,b) - a + 1 << endl;
    return 0;
}