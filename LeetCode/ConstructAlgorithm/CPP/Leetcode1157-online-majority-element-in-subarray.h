#include <unordered_map>
#include <vector>

using namespace std;

class MajorityChecker {
public:
 int n{}, len{};
 vector<int> a;
 unordered_map<int, vector<int>> s;
 MajorityChecker(vector<int>& arr) {
   n = arr.size();
   a = std::move(arr);
   len = sqrt(2 * n);
   unordered_map<int, int> cnt;
   for (const auto x : a) cnt[x]++;
   for (const auto& [k, v] : cnt) {
     if (v > len) {
       s[k] = vector<int>(n + 1);
       for (int i = 1; i <= n; i++) {
         s[k][i] = s[k][i - 1];
         if (a[i - 1] == k) s[k][i]++;
       }
     }
   }
 }

 int query(int left, int right, int threshold) {
   if (right - left + 1 <= len) {
     unordered_map<int, int> cnt;
     for (int i = left; i <= right; i++) {
       if (++cnt[a[i]] >= threshold) return a[i];
     }
   } else {
     for (const auto& [k, v] : s) {
       if (v[right + 1] - v[left] >= threshold) {
         return k;
       }
     }
   }
   return -1;
 }
};
