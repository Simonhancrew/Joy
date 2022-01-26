class TopVotedCandidate {
public:
    vector<int> win;
    vector<int> t;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        win.resize(n);
        t = times;
        vector<int> sum(n);
        int maxc = 0,maxp;
        for(int i = 0;i < n;i++){
            int p = persons[i];
            ++sum[p];
            if(sum[p] >= maxc) {
                maxc = sum[p];
                maxp = p;
            }
            win[i] = maxp;
        }
    }
    
    int q(int m) {
        int k = upper_bound(t.begin(),t.end(),m) - t.begin() - 1;
        return win[k];
    }
};