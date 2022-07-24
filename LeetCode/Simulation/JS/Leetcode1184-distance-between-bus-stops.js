var distanceBetweenBusStops = function (distance, start, destination) {
    if (start > destination) {
        [start, destination] = [destination, start];
    }
    let [s1, s2] = [0, 0];
    for (let i = 0; i < distance.length; i++) {
        if (i >= start && i < destination) {
            s1 += distance[i];
        } else {
            s2 += distance[i];
        }
    }
    return Math.min(s1, s2);
};