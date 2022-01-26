#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int ne[N];
char s[N];
bool st[N];

// kmp做最长前后缀匹配
// 有几个结论，最长的就是ne[n],次场ne[ne[n]].
// 其次就是看有没有在中间出现过，可以参考bool数组st的部分，只要有前缀k的在1-n存在，就可以找到。

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> s + 1;
        int n = strlen(s + 1);
        for(int i = 2,j = 0;i <= n;i++){
            while(j && s[i] != s[j + 1]) j = ne[j];
            if(s[i] == s[j + 1]) j++;
            ne[i] = j;
        }
        
        for(int i = 0;i <= n;i++) st[i] = false;
        for(int i = 1;i < n;i++) st[ne[i]] = true;
        
        int ans = 0;
        for(int i = ne[n];i;i = ne[i]){
            if(st[i]){
                ans = i;
                break;
            }
        }
        if(!ans) puts("not exist");
        else {
            s[ans + 1] = 0;
            cout << s + 1 << endl; 
        }
    }
}