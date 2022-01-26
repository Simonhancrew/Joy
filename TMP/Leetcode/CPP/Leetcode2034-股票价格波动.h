class StockPrice {
public:
    StockPrice() {

    }
    
    void update(int timestamp, int price) {
        if(mp.count(timestamp)) {
            int old = mp[timestamp];
            if(rec[old] > 1) rec[old]--;
            else rec.erase(old);
        }
        rec[price]++;
        mp[timestamp] = price;

    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return rec.rbegin()->first;
    }
    
    int minimum() {
        return rec.begin()->first;
    }
private:
    map<int,int> mp;
    map<int,int> rec;
};