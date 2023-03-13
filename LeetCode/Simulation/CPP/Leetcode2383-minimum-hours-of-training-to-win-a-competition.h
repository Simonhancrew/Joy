class Solution {
 public:
  int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    int s1 = 0, s2 = 0, mn = experience[0];
    int n = experience.size();
    for (int i = 0; i < n; i++) {
      s1 += energy[i];
      s2 += experience[i];
      if (i > 0) mn = max(mn, experience[i] - s2 + experience[i]);
    }
    int res = 0;
    if (s1 >= initialEnergy) {
      res += s1 - initialEnergy + 1;
    }
    if (mn >= initialExperience) {
      res += mn - initialExperience + 1;
    }
    return res;
  }
};
