var isNStraightHand = function(hand, groupSize) {
    const n = hand.length;
    if(n % groupSize != 0) return false;
    const st = new Map();
    hand.sort((a,b) => a - b);
    for(const hd of hand){
        st.set(hd,(st.get(hd) || 0) + 1);
    }
    for(const hd of hand){
        if(!st.has(hd)) continue;
        for(let i = hd;i < hd + groupSize;i++){
            if(!st.has(i)) return false;
            st.set(i,st.get(i) - 1);
            if(st.get(i) == 0) st.delete(i);
        }
    }
    return true;
};