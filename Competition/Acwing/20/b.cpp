#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 1e3 + 10;
int a[N];
int n,k1,k2;

int main(){
    cin >> n >> k1 >> k2;
    priority_queue<LL> heap; 
    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0;i < n;i++){
        int t;
        cin >> t;
        t = abs(a[i] - t);
        if(t) heap.push(t);
    }
    int k = k1 + k2;
    while(heap.size() && k){
        auto t = heap.top();
        heap.pop();
        t--,k--;
        if(!t) continue;
        else heap.emplace(t);
    }
    LL res = 0;
    if(heap.size()) {
        while(heap.size()){
            auto t = heap.top();
            heap.pop();
            res += (t * t);
        }
    }else if(k&1){
        res = 1;
    }
    cout << res << endl;
}