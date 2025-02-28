class FoodRatings {
 public:
  using PSI = pair<string, int>;
  map<string, PSI> f2cr;
  map<string, map<int, set<string>>> c2fr;
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    int n = foods.size();
    for (int i = 0; i < n; i++) {
      f2cr[foods[i]] = {cuisines[i], ratings[i]};
      c2fr[cuisines[i]][ratings[i]].insert(foods[i]);
    }
  }

  void changeRating(string food, int newRating) {
    auto pre_rating   = f2cr[food].second;
    auto cuisine      = f2cr[food].first;
    f2cr[food].second = newRating;
    c2fr[cuisine][pre_rating].erase(food);
    c2fr[cuisine][newRating].insert(food);
    if (c2fr[cuisine][pre_rating].empty()) {
      c2fr[cuisine].erase(pre_rating);
    }
  }

  string highestRated(string cuisine) {
    return *c2fr[cuisine].rbegin()->second.begin();
  }
};
