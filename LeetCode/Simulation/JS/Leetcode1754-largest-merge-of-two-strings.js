var minMovesToSeat = function(seats, students) {
    seats.sort((a, b) => a - b);
    students.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0;i < students.length;i++) {
        ans += Math.abs(students[i] - seats[i]);
    }
    return ans;
};
