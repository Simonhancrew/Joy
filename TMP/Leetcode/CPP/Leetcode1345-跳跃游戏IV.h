/*
    单向BFS接删除
*/
#if SINGLEBFS
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        for(int i = 0;i < n;i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> dist(n,-1);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while(q.size()) {
            auto t = q.front();
            q.pop();
            for(int ne : mp[arr[t]]) {
                if(dist[ne] == -1) {
                    dist[ne] = dist[t] + 1;
                    q.push(ne);
                }
            }
            mp.erase(arr[t]);
            if(t + 1 < n && dist[t + 1] == -1) {
                dist[t + 1] = dist[t] + 1;
                q.push(t + 1);
            } 
            if(t - 1 >= 0 && dist[t - 1] == -1) {
                dist[t - 1] = dist[t] + 1;
                q.push(t - 1);
            }
        }
        return dist[n - 1];
    }
};
#endif

#define DOUBLEDBFS 1
#if DOUBLEDBFS
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    queue<int> qa,qb;
    vector<int> da,db;
    int n;
    int extend(queue<int> &q,vector<int> &da,vector<int> &db,vector<int> const &arr) {
        int d = da[q.front()];
        while(q.size() && d == da[q.front()]) {
            auto t = q.front();
            q.pop();
            for(int ne : mp[arr[t]]) {
                if(db[ne] != -1) return da[t] + 1 + db[ne];
                if(da[ne] == -1) {
                    da[ne] = da[t] + 1;
                    q.push(ne);
                }
            }
            mp.erase(arr[t]);
            if(t + 1 < n && da[t + 1] == -1) {
                if(db[t + 1] != -1) return da[t] + 1 + db[t + 1];
                da[t + 1] = da[t] + 1;
                q.push(t + 1);
            }
            if(t - 1 >= 0 && da[t-1] == -1) {
                if(db[t - 1] != -1) return da[t] + db[t - 1] + 1;
                da[t - 1] = da[t] + 1;
                q.push(t - 1);
            }
        }
        return -1;
    }
    int minJumps(vector<int>& arr) {
        n = arr.size();
        if(n == 1) return 0;
        for(int i = 0;i < n;i++) {
            mp[arr[i]].push_back(i);
        }
        qa.push(0),qb.push(n - 1);
        da.resize(n,-1),db.resize(n,-1);
        da[0] = 0,db[n - 1] = 0;
        while(qa.size() && qb.size()) {
            int t;
            if(qa.size() < qb.size()) t = extend(qa,da,db,arr);
            else t = extend(qb,db,da,arr);
            if(t != -1) return t;
        }
        return -1;
    }
};
#endif