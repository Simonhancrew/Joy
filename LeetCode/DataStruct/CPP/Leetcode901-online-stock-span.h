class StockSpanner {
public:
    int idx = 0;
    stack<int> day, prices;
    StockSpanner() {
        day.emplace(-1);
        prices.emplace(INT_MAX);
    }   
    
    int next(int price) {
        while(price >= prices.top()) {
            day.pop();
            prices.pop();
        }
        int res = idx - day.top();
        day.emplace(idx++);
        prices.emplace(price);
        return res;
    }
};

