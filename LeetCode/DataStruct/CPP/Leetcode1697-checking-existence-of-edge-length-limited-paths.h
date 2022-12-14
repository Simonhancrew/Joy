class Solution {
 public:
  vector<int> pa;
  int find(int x) {
    if (pa[x] != x) pa[x] = find(pa[x]);
    return pa[x];
  }
  void merge(int x, int y) {
    if (find(x) == find(y)) return;
    pa[find(x)] = pa[find(y)];
  }
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    int m = queries.size();
    vector<bool> res(m);
    pa.resize(n);
    for (int i = 0; i < n; i++) pa[i] = i;
    sort(edgeList.begin(), edgeList.end(), [](vector<int>& lhs, vector<int>& rhs) { return lhs[2] < rhs[2]; });
    vector<int> ref(m);
    for (int i = 0; i < m; i++) ref[i] = i;
    sort(ref.begin(), ref.end(), [&](int l, int r) { return queries[l][2] < queries[r][2]; });
    int j = 0;
    for (int i = 0; i < m; i++) {
      while (j < edgeList.size() && edgeList[j][2] < queries[ref[i]][2]) {
        merge(edgeList[j][1], edgeList[j][0]);
        j++;
      }
      if (find(queries[ref[i]][0]) == find(queries[ref[i]][1])) {
        res[ref[i]] = true;
      }
    }
    return res;
  }
};