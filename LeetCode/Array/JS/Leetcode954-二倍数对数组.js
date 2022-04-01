var canReorderDoubled = function(arr) {
    let mp = new Map();
    for(const num of arr) {
        mp.set(num,(mp.get(num) || 0) + 1);
    }
    if((mp.get(0) || 0) % 2 != 0) return false;
    const rec = [];
    for(const k of mp.keys()){
        rec.push(k);
    }
    rec.sort((a,b) => Math.abs(a) - Math.abs(b));
    for(const k of rec) {
        if ((mp.get(k * 2) || 0) < mp.get(k)) {
            return false;
        }
        mp.set(k * 2,(mp.get(k * 2) || 0) - mp.get(k)); 
    }
    return true;
};