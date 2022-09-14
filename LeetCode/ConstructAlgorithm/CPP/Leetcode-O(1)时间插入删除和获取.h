/*
    支持随机索引比较恶心，但其实单纯用unordered_set迭代器配合next也能做出来
*/

class RandomizedSet {
 public:
  unordered_map<int, int> mp;
  vector<int> nums;
  RandomizedSet() {}

  bool insert(int val) {
    if (mp.count(val)) return false;
    nums.push_back(val);
    mp[val] = nums.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!mp.count(val)) return false;
    int tar = nums.back();
    int px = mp[val], py = mp[tar];
    swap(nums[px], nums[py]);
    nums.pop_back();
    swap(mp[val], mp[tar]);
    mp.erase(val);
    return true;
  }

  int getRandom() { return nums[rand() % nums.size()]; }
};
