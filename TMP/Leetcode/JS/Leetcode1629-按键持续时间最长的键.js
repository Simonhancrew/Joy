var slowestKey = function(releaseTimes, keysPressed) {
    let ans = keysPressed[0],time = releaseTimes[0];
    for(let i = 0;i < releaseTimes.length;i++){
        const t = releaseTimes[i] - releaseTimes[i - 1];
        if(t > time || (t == time && ans < keysPressed[i])) time = t,ans = keysPressed[i]
    }
    return ans;
};