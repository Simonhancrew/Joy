/**
 * @param {ListNode} head
 */
var Solution = function(head) {
    this.node = []
    while(head){
        this.node.push(head.val);
        head = head.next;
    }
};

/**
 * @return {number}
 */
Solution.prototype.getRandom = function() {
    return this.node[Math.floor(Math.random() * this.node.length)];
};