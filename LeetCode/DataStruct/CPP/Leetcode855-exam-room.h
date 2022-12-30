#include <set>

using namespace std;

class ExamRoom {
public:
    int sz = 0;
    set<int> st;
    ExamRoom(int n) {
        sz = n;
    }
    
    int seat() {
        int idx = 0;
        if (st.size()) {
            int dist = *st.begin();
            for (auto i = st.begin();i != st.end();i++) {
                auto j = i;
                j++;
                if (j != st.end()) {
                    if (dist < (*j - *i) / 2) {
                        dist = (*j - *i) / 2;
                        idx = *i + dist; 
                    }
                } else {
                    if (dist < sz - 1 - *i) {
                        dist = sz - 1 - *i;
                        idx = sz - 1;
                    }
                }
            }
        }
        st.insert(idx);
        return idx;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};
