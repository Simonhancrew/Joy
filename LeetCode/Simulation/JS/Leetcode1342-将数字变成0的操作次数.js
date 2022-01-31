var numberOfSteps = function(num) {
    let cnt = 0;
    while(num) {
        if(num & 1) num--;
        else num >>= 1;
        cnt++;
    }
    return cnt;
};