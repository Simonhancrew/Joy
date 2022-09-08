class Solution {
public:
    int minOperations(vector<string>& logs) {
        int stp = 0, n = logs.size();
        for(int i = 0;i < n;i++) {
            if(logs[i] == "./" || (stp == 0 && logs[i] == "../")) continue;
            if(logs[i] == "../") stp--;
            else stp++; 
        }
        return stp;
    }
};