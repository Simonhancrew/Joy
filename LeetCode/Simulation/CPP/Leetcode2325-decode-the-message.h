class Solution {
 public:
  string decodeMessage(string key, string message) {
    unordered_map<char, char> mp;
    int n = key.size();
    for (int i = 0, j = 0; i < n; i++) {
      if (mp.count(key[i]) || key[i] == ' ') continue;
      mp[key[i]] = 'a' + j;
      j++;
    }
    n = message.size();
    for (int i = 0; i < n; i++) {
      if (message[i] == ' ' || !mp.count(message[i])) continue;
      message[i] = mp[message[i]];
    }
    return message;
  }
};