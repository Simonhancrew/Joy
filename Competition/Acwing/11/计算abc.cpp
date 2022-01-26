#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int num[4];
    for(int i = 0;i < 4;i++) cin >> num[i];
    sort(num,num + 4);
    int mm = num[3];
    vector<int> res;
    for(int i = 2;i >= 0;i--){
        res.push_back(mm - num[i]);
    }
    for(auto val:res) cout << val << ' ';
}