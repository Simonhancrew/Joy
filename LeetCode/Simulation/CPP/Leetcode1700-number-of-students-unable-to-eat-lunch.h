class Solution {
 public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    int stu1 = accumulate(students.begin(), students.end(), 0);
    int stu0 = students.size() - stu1;
    int n = sandwiches.size();
    for (int i = 0; i < n; i++) {
      if (sandwiches[i] == 0) {
        if (stu0)
          stu0--;
        else
          break;
      } else {
        if (stu1)
          stu1--;
        else
          break;
      }
    }
    return stu1 + stu0;
  }
};
