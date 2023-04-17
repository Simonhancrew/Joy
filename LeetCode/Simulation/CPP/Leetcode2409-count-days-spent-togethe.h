class Solution {
 public:
  static constexpr int month[12] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    vector<int> s(13);
    for (int i = 1; i <= 12; i++) {
      s[i] = s[i - 1] + month[i - 1];
    }
    int bob_l = s[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3));
    int bob_r = s[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3));
    int alice_l =
        s[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3));
    int alice_r =
        s[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3));
    if (alice_l > bob_r || alice_r < bob_l) return 0;
    return min(bob_r, alice_r) - max(bob_l, alice_l) + 1;
  }
};
