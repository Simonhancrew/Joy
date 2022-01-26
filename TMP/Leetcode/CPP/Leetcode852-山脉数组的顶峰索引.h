#include <vector>

using namespace std;

#if 0
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0,r = arr.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(arr[mid] > arr[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
#endif

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1,r = arr.size() - 2;
        while(l < r){
            int mid = l + r >> 1;
            if(arr[mid] < arr[mid + 1]) l = mid + 1;
            else r = mid;
        }        
        return l;
    }
};