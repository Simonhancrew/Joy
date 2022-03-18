package sbgo

type Bank struct {
	rec []int64
	n   int
}

func Constructor(balance []int64) Bank {
	n := len(balance)
	return Bank{balance, n}
}

func (this *Bank) Transfer(account1 int, account2 int, money int64) bool {
	if account1 < 1 || account1 > this.n || account2 < 1 || account2 > this.n {
		return false
	}
	if this.rec[account1-1] < money {
		return false
	}
	this.rec[account1-1] -= money
	this.rec[account2-1] += money
	return true
}

func (this *Bank) Deposit(account int, money int64) bool {
	if account < 1 || account > this.n {
		return false
	}
	this.rec[account-1] += money
	return true
}

func (this *Bank) Withdraw(account int, money int64) bool {
	if account < 1 || account > this.n {
		return false
	}
	if this.rec[account-1] < money {
		return false
	}
	this.rec[account-1] -= money
	return true
}
