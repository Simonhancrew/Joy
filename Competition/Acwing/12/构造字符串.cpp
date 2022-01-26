#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 一道贪心的题目，k大于n和k小于n分类讨论
// k小于n的时候，从最后一个位置开始比较，能变大就变大，不能变大就最小。

const int N = 1e5 + 10;

char s[N],tmp[N];
bool st[26];


char get_min(){
    for(int i = 0;i < 26;i++){
        if(st[i]){
            return i + 'a';
        }
    }
    return -1;
}

char get_next(int idx){
    for(int i = idx + 1;i < 26;i++){
        if(st[i]){
            return i + 'a';
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        cin >> s;
        memset(st,0,sizeof st);
        for(int i = 0;i < n;i++) st[s[i] - 'a'] = true;
        if(k > n){
            cout << s;
            for(int i = n;i < k;i++) cout << get_min();
            puts("");
        }else{
            tmp[k] = 0;
            for(int i = k - 1;i >= 0;i--){
                char cur = get_next(s[i]-'a');
                if(cur != -1){
                    tmp[i] = cur;
                    for(int j = 0;j < i;j++) tmp[j] = s[j];
                    break;
                }
                tmp[i] = get_min();
            }
            puts(tmp);
        }
    }
}