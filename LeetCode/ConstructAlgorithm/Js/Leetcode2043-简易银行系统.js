
var Bank = function (balance) {
    this.n = balance.length;
    this.rec = balance;
};


Bank.prototype.transfer = function (account1, account2, money) {
    if (account1 < 1 || account1 > this.n || account2 < 1 || account2 > this.n) return false
    if (this.rec[account1 - 1] < money) return false;
    this.rec[account1 - 1] -= money;
    this.rec[account2 - 1] += money;
    return true;
};

Bank.prototype.deposit = function (account, money) {
    if (account < 1 || account > this.n) return false;
    this.rec[account - 1] += money;
    return true;
};

Bank.prototype.withdraw = function (account, money) {
    if (account < 1 || account > this.n) return false;
    if (this.rec[account - 1] < money) return false;
    this.rec[account - 1] -= money;
    return true;
};