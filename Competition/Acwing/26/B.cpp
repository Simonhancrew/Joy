#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

string s;
int ch[26];

// 看数据范围nlogn可以过就直接2分了，然后双指针O(n)去判断就行了

bool check(int len){
    for(int i = 0;i < 26;i++){
        if(!ch[i] || ch[i] < s.size() / len) continue;
        char t = ('a' + i);
        int cnt = 0;
        for(int i = 0,j = 0;j < s.size();j++){
            if(s[j] == t) cnt++;
            if(j - i + 1 == len){
                if(cnt == 0) break;
                if(s[i++] == t) cnt--;
            }
            if(j == s.size() - 1) return true;
        }
    }
    return false;
}

int main(){
    cin >> s;
    for(auto c : s) {
        ch[c - 'a'] += 1;
    }
    int l = 1,r = s.size();
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
