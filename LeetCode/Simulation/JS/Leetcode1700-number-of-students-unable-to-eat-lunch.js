var countStudents = function (students, sandwiches) {
  let stu1 = students.reduce((sum, item) => sum + item);
  let stu0 = students.length - stu1;
  for (let i = 0; i < students.length; i++) {
    if (sandwiches[i] == 0) {
      if (stu0 != 0) stu0--;
      else break;
    } else {
      if (stu1 != 0) stu1--;
      else break;
    }
  }
  return stu0 + stu1;
};

