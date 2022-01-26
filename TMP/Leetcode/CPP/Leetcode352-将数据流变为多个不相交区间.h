#include <vector>
#include <algorithm>
#include <set>

using namespace std;

using LL = long long;
typedef pair<LL,LL> PII;
const LL INF = 1e9;
#define x first
#define y second
class SummaryRanges {
public:
    set<PII> st;
    SummaryRanges() {
        st.insert({-INF,-INF});
        st.insert({INF,INF});
    }
    
    void addNum(int val) {
        auto r = st.upper_bound({val,INF});
        auto l = r;
        l--;
        if(l->y>=val) return;
        else if(l->y == val - 1 && r->x == val + 1){
            st.insert({l->x,r->y});
            st.erase(l),st.erase(r);
        }else if(l->y == val - 1){
            st.insert({l->x,val});
            st.erase(l);
        }else if(r->x == val + 1){
            st.insert({val,r->y});
            st.erase(r);
        }else{
            st.insert({val,val});
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto &p : st){
            if(p.x != INF && p.x != -INF){
                res.push_back({(int)p.x,(int)p.y});
            }
        }
        return res;
    }
};
