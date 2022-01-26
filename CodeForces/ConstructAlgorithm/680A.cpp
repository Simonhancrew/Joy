#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
 
// Created by Simonhancrew on 2021/11/25
 
using namespace std;
 
typedef long long LL;
typedef pair<int,int> PII;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
const int N = 5;
 
int t[N];
 
int main(){
    // #define _DEBUG
    #ifdef _DEBUG
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    fast_cin();
    unordered_map<int,int> mp;
    int sum = 0;
    for(int i = 0;i < 5;i++){
        cin >> t[i];
        mp[t[i]]++;
        sum += t[i];
    }
    int target = 0;
    for(auto [k,v] : mp){
        if(v >= 2) {
            target = max(k * min(3,v),target);
        }
    }
    cout << sum - target << endl;
    return 0;
}