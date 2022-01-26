#include <string>
#include <vector>

using namespace std;

// 找到规律就可以了，3位变一次，注意空格的问题

class Solution {
public:
    vector<string> num19 = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
        "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
        "Nineteen"
    };
    vector<string> num20 = {
        "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"
    };
    vector<string> num1000 = {
        "Billion ", "Million ", "Thousand ",""
    };
    string get(int x){
        string res;
        if(x >= 100){
            res += num19[x / 100] + " Hundred ";
            x %= 100;
        }
        if(x >= 20){
            res += num20[x / 10 - 2] + ' ';
            x %= 10;
        }
        if(x) res += num19[x] + ' ';
        return res; 
    }
    string numberToWords(int num) {
        string res;
        if(!num) return num19[0];
        for(int i = 1e9,j = 0;i >= 1;i /= 1000,j++){
            if(num >= i){
                res += get(num / i) + num1000[j];
                num %= i;
            }
        }
        res.pop_back();
        return res;
    }
};