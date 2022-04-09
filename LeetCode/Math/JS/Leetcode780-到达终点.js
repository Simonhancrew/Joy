var reachingPoints = function (sx, sy, tx, ty) {
    while (tx > sx && ty > sy) {
        if (tx > ty) tx %= ty;
        else ty %= tx;
    }
    if (tx < sx || ty < sy) return false;
    if (tx == sx) return (ty - sy) % sx == 0;
    return (tx - sx) % sy == 0;
};