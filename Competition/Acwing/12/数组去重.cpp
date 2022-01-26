#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 60;
int a[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_set<int> mp;
        vector<int> res;
        for(int i = 0;i < n;i++) cin >> a[i];
        for(int i = n - 1;i >= 0;i--){
            if(mp.count(a[i])) continue;
            mp.insert(a[i]);
            res.push_back(a[i]);
        }
        cout << res.size() << endl;
        for(int i = res.size() - 1;i >= 0;i--) cout << res[i] << ' ';
        cout << endl;
    }
}