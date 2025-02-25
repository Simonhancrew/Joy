class Allocator {
 public:
  vector<uint16_t> arr;
  Allocator(int n) : arr(n, 0) {
  }

  int allocate(int size, int mID) {
    int free = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == 0) {
        free++;
      } else {
        free = 0;
      }
      if (free == size) {
        for (int j = i; j > i - size; j--) {
          arr[j] = mID;
        }
        return i - size + 1;
      }
    }
    return -1;
  }

  int freeMemory(int mID) {
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == mID) {
        arr[i] = 0;
        ++cnt;
      }
    }
    return cnt;
  }
};

#if 0


class Allocator {
public:
  using PII = pair<int, int>;
  map<int, int> mp;
  unordered_map<int, vector<PII>> rec;
  int n;
  Allocator(int n) : n(n) {
    mp[n] = n;
  }

  int allocate(int size, int mID) {
    int rp = 0;
    for (const auto &[k, v] : mp) {
      if (k - rp >= size) {
        rec[mID].emplace_back(rp, rp + size);
        mp[rp] = rp + size;
        return rp;
      }
      rp = v;
    }
    return -1;
  }

  int freeMemory(int mID) {
    int ans = 0;
    for (const auto &[k, v] : rec[mID]) {
      mp.erase(k);
      ans += v - k;
    }
    rec.erase(mID);
    return ans;
  }
};

#endif
