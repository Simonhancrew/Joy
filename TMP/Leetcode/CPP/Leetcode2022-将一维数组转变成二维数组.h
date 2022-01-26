#if BAD
class Solution {
public:
    typedef long long LL;
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        LL res = (LL)m * n,len = original.size();
        if(len != res) return vector<vector<int>> {};
        vector<vector<int>> ans;
        for(int i = 0;i < m;i++){
            vector<int> t;
            for(int j = 0;j < n;j++){
                t.push_back(original[i * n + j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
#endif 

/*
    c++写法很多，迭代器属于比较方便的
*/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(m * n != original.size()) return ans;
        for(auto it = original.begin();it != original.end();it += n){
            ans.emplace_back(it,it + n);
        } 
        return ans;
    }
};