#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        for(int i = sqrt(area);;i--){
            if(area % i == 0){
                return vector<int>{area / i,i};
            }
        }
        return vector<int> {};
    }
};