var lowestCommonAncestor = function (root, p, q) {
  let ans = root
  while (true) {
    if (q.val > ans.val && p.val > ans.val) {
      ans = ans.right;
      continue;
    }
    if (q.val < ans.val && p.val < ans.val) {
      ans = ans.left;
      continue;
    }
    break
  }
  return ans;
};
