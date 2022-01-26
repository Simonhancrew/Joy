#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int> heap;
        for(int i = 0;i < arr.size();i++){
            if(i < k) heap.push(arr[i]);
            else{
                if(heap.size() && arr[i] < heap.top()){
                    heap.push(arr[i]);
                    heap.pop();
                }
            }
        }
        vector<int> res;
        while(heap.size()){
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};