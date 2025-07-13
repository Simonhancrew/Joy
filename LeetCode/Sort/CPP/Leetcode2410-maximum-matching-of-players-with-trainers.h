class Solution {
 public:
  int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    ranges::sort(players);
    ranges::sort(trainers);
    int j = 0, ans = 0;
    int n = players.size(), m = trainers.size();
    for (int i = 0; i < n; i++, j++) {
      while (j < m && trainers[j] < players[i])
        j++;
      if (j == m)
        break;
      ans++;
    }
    return ans;
  }
};
