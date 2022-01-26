var dayOfTheWeek = function(day, month, year) {
    const ans = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"];
    const cnt = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30]
    let days = 0;
    for(let i = 1971;i < year;i++){
        let isleap = (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
        days += isleap ? 366 : 365;
    }
    for(let i = 0;i < month - 1;i++) days += cnt[i];
    if((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month > 2) days += 1;
    days += day;
    return ans[(days + 3) % 7];
};