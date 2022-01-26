#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_set<int>st[34][34];
    int scoreOfStudents(string s, vector<int>& b) {
        int goal=0,n=s.size();
        vector<int>pl;
        pl.push_back(-1);
        for(int i=1;i<n;i+=2)
            if(s[i]=='+') pl.push_back(i);
        pl.push_back(n);
        for(int i=0;i+1<pl.size();i++){
            int l=pl[i]+1,r=pl[i+1]-1;
            int tmp=1;
            for(int j=l;j<=r;j+=2)  tmp*=s[j]-'0';
            goal+=tmp;
        }
        printf("goal=%d\n",goal);
        for(int i=0;i<n;i+=2) st[i][i].insert(s[i]-'0');
        for(int k=3;k<=n;k+=2){
            for(int l=0;l+k-1<n;l+=2){
                int r=l+k-1;
                for(int j=l+1;j<r;j+=2){
                    for(int x:st[l][j-1]){
                        for(int y:st[j+1][r]){
                            if(s[j]=='+'&&x+y<=1000) st[l][r].insert(x+y);
                            else if(s[j]=='*'&&x*y<=1000) st[l][r].insert(x*y); 
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int x:b){
            if(x==goal) ans+=5;
            else if(st[0][n-1].count(x)) ans+=2;
        } 
        return ans;
    }
};