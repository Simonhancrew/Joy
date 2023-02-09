#include <string>
#include <unordered_map>

using namespace std;

class AuthenticationManager {
 public:
  unordered_map<string, int> mp;
  int base = 0;
  AuthenticationManager(int timeToLive) : base(timeToLive) {}

  void generate(string tokenId, int currentTime) { mp[tokenId] = currentTime + base; }

  void renew(string tokenId, int currentTime) {
    if (!mp.count(tokenId)) return;
    auto v = mp[tokenId];
    if (v <= currentTime) {
      mp.erase(tokenId);
      return;
    }
    mp[tokenId] = currentTime + base;
  }

  int countUnexpiredTokens(int currentTime) {
    for (auto it = mp.begin(); it != mp.end();) {
      if ((*it).second <= currentTime) {
        it = mp.erase(it);
      } else {
        ++it;
      }
    }
    return mp.size();
  }
};
