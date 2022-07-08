var minCostToMoveChips = function (position) {
    let [o, e] = [0, 0];
    for (const p of position) {
        if (p & 1) e++;
        else o++;
    }
    if (!o || !e) return 0;
    return Math.min(e, o);
};