var minOperations = function(logs) {
    let [stp,n] = [0,logs.length];
    for(const s of logs) {
        if(s == "./" || (s == "../" && stp == 0)) continue;
        if(s == "../") stp--;
        else stp++;
    }
    return stp;
};