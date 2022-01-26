var buddyStrings = function(s, goal) {
    if(s.length != goal.length) return false;
    if(s === goal){
        let mp = new Map();
        for(const ch of s){
            mp.set(ch,(mp.get(ch) || 0) + 1);
            if(mp.get(ch) > 1) return true;
        }
        return false;
    }
    let arr = new Array();
    for(let i = 0;i < s.length;i++){
        if(s[i] != goal[i]) arr.push(i);
    }
    if(arr.length != 2) return false;
    let [x,y] = [arr[0],arr[1]];
    return s[x] == goal[y] && s[y]== goal[x];
};