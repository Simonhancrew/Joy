/*
    读取还可以考虑sscanf(string,format,varx...)
*/
class Solution {
public:
    typedef pair<int,int> PII;
    PII get(string& s){
        int x = 0,y = 0,idx = 0,n = s.size();
        for(int i = 0;i < n;i++) {
            if(s[i] == '+'){
                idx = i;
                break;
            }
        }
        x = stoi(s.substr(0,idx)),y = stoi(s.substr(idx + 1,n - idx - 2));
        return {x,y};
    }
    string complexNumberMultiply(string num1, string num2) {
        auto p1= get(num1),p2 = get(num2);
        int x1 = p1.first,y1 = p1.second,x2 = p2.first,y2 = p2.second;
        int a = x1 * x2 - y1 * y2,b = x1 * y2 + x2 * y1;
        string s = to_string(a) + '+' + to_string(b) + 'i';
        return s;
    }
};