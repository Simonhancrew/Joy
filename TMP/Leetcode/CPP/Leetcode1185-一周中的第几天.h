int cnt[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
string ans[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday","Sunday"};
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int days = 0;
        for(int i = 1971;i < year;i++){
            bool isleap = (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
            days += isleap ? 366 : 365;
        }
        for(int i = 0;i < month - 1;i++){
            days += cnt[i];
        }
        if((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) days += 1;
        days += day;
        return ans[(days + 3) % 7];
    }
};