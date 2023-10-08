#include <map>

using namespace std;

class StockPrice {
 public:
  map<int, int> mp;
  map<int, int> rec;

  StockPrice() = default;

  void update(int timestamp, int price) {
    if (mp.count(timestamp)) {
      auto old_price = mp[timestamp];
      rec[old_price]--;
      if (rec[old_price] == 0) {
        rec.erase(old_price);
      }
    }
    rec[price]++;
    mp[timestamp] = price;
  }

  int current() { return mp.rbegin()->second; }

  int maximum() { return rec.rbegin()->first; }

  int minimum() { return rec.begin()->first; }
};
