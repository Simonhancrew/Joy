var numComponents = function (head, nums) {
  let [res, inn] = [0, false];
  let st = new Set();
  for (const x of nums) st.add(x);
  while (head) {
    if (st.has(head.val)) {
      if (!inn) {
        inn = true;
        res++;
      }
    } else {
      inn = false;
    }
    head = head.next;
  }
  return res;
};