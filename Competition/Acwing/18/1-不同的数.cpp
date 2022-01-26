#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 110;

int a[N];

int k,n;

#ifdef ORIGINSUBMIT
int main(){
    cin >> n >> k;
    unordered_set<int> mp;
    vector<int> res;
    bool flag = false;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(mp.size() == k) {
            flag = true;
            break;
        }
        if(mp.count(a[i])) continue;
        else {
            mp.insert(a[i]);
            res.push_back(i + 1);
        }
    }
    if(flag || res.size() == k){
        cout << "YES" << endl;
        for(int i = 0;i < res.size();i++) cout << res[i] << ' ';
    }else{
        cout << "NO" <<endl;
    }
    return 0;
}
#endif