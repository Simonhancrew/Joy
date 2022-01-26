#include <iostream>
#include <algorithm>
#include <cstring>

/*
    排序s之后分情况讨论，p != abc和s中没有[a,b,c]的时候可以直接输出
    否则的话先输出所有的a,再c，再b，再其余字母字典序
*/

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int t;
string s,p;
int word[26];


int main(){
    fast_cin();
    cin >> t;
    while(t--){
        cin >> s >> p;
        memset(word,0,sizeof word);
        sort(s.begin(),s.end());
        for(auto& ch : s){
            word[ch - 'a']++;
        }
        if(p != "abc" || !word[0] || !word[1] || !word[2]) cout << s << '\n';
        else{
            while(word[0]--)cout<<"a";
            while(word[2]--)cout<<"c";
            while(word[1]--)cout<<"b";
            for(int i = 3;i < 26; ++i){
                while(word[i]--)cout<<char('a' + i);
            }
            cout << "\n";
        }
    }
    return 0;
}