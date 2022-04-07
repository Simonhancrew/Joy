var rotateString = function(s, goal) {
    return s.length == goal.length && (s + s).indexOf(goal) != -1;
};