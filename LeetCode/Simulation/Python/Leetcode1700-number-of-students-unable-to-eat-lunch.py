class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
      stu1 = sum(students)
      n, stu0 = len(students), len(students) - stu1
      for i in range(n):
        if sandwiches[i]:
          if stu1: stu1 -= 1
          else: break
        else:
          if stu0: stu0 -= 1
          else: break
      return stu1 + stu0