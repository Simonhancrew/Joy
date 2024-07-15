#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> fa;
  vector<vector<string>> accounts;

  int find(int x) {
    if (fa[x] != x) {
      fa[x] = find(fa[x]);
      return fa[x];
    }
    return fa[x];
  }

  void merge(int l, int r) {
    auto fl = find(l);
    auto fr = find(r);
    if (fl == fr) {
      return;
    }
    fa[fr] = fl;
    for (int i = 1; i < accounts[fr].size(); i++) {
      accounts[fl].push_back(accounts[fr][i]);
    }
    sort(accounts[fl].begin() + 1, accounts[fl].end());
    accounts[fl].erase(unique(accounts[fl].begin() + 1, accounts[fl].end()),
                       accounts[fl].end());
  }

  vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
    this->accounts = std::move(acc);
    int n = accounts.size();
    fa.resize(n);
    iota(fa.begin(), fa.end(), 0);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        if (mp.count(accounts[i][j])) {
          merge(i, mp[accounts[i][j]]);
        } else {
          mp[accounts[i][j]] = i;
        }
      }
    }
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
      if (fa[i] == i) {
        sort(accounts[i].begin() + 1, accounts[i].end());
        accounts[i].erase(unique(accounts[i].begin() + 1, accounts[i].end()),
                          accounts[i].end());
        ans.push_back(accounts[i]);
      }
    }
    return ans;
  }
};
