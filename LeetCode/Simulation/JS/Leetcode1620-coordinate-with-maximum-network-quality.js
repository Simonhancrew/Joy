var bestCoordinate = function(towers, radius) {
    let [mx, my] = [-1, -1];
    for(const t of towers) {
        mx = Math.max(mx, t[0]);
        my = Math.max(my, t[1]);
    }
    let [tx, ty, qua] = [0, 0 ,0];
    for(let x = 0;x <= mx;x++) {
        for(let y = 0;y <= my;y++) {
            let q = 0;
            for(const t of towers) {
                let d = (x - t[0]) ** 2 + (y - t[1]) ** 2;
                if(d <= radius ** 2) {
                    q += parseInt(t[2] / (1 + Math.sqrt(d)));
                }
            }
            if(qua < q) {
                [tx, ty, qua] = [x, y, q];
            }
        }
    }
    return [tx, ty];
};
