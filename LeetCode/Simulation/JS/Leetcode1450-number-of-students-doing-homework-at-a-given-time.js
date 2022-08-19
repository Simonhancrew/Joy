var busyStudent = function(startTime, endTime, queryTime) {
    let [ans,n] = [0,startTime.length];
    for(let i = 0;i < n;i++) {
        if(queryTime >= startTime[i] && queryTime <= endTime[i]) ans++;
    }
    return ans;
};