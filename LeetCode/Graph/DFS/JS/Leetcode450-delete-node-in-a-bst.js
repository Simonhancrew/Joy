var deleteNode = function (root, key) {
    if (!root) return null;
    else if (root.val == key) {
        if (!root.left && !root.right) return null;
        else if (!root.left) return root.right;
        else if (!root.right) return root.left;
        else {
            let ne = root.right;
            while (ne.left) ne = ne.left;
            ne.right = deleteNode(root.right, ne.val);
            ne.left = root.left;
            return ne;
        }
    }
    else if (root.val > key) {
        root.left = deleteNode(root.left, key);
    } else {
        root.right = deleteNode(root.right, key);
    }
    return root;
};