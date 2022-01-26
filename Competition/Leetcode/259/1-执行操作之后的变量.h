class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int add = 0,minus = 0;
        for(auto op : operations){
            if(op == "++X" || op == "X++") add++;
            else minus++;
        }
        return add - minus;   
    }
};