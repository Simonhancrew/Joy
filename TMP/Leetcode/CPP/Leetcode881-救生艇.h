#include <vector>
#include <algorithm>

using namespace std;

// 首先排序，之后最后最重的人看看能不能带一个较轻的人坐船。
// 可以的话i++,不行的话只能自己坐

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0;
        sort(people.begin(),people.end());
        for(int i = 0,j = people.size() - 1;i <= j;j--){
            if(people[i] + people[j] <= limit) i++;
            res++;
        }
        return res;
    }
};