class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        multiset<int> st;
        for(int hd : hand) st.insert(hd);
        while(st.size()){
            int x = *st.begin();
            for(int i = 0;i < groupSize;i++){
                if(!st.count(x + i)) return false;
                st.erase(st.find(x + i));
            }
        }
        return true;
    }
};