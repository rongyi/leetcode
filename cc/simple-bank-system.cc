// https://leetcode.com/problems/simple-bank-system/
#include "xxx.hpp"

class Bank {
public:
  Bank(vector<long long> &balance) {
    acts_ = balance;
    sz_ = acts_.size();
  }

  bool transfer(int account1, int account2, long long money) {
    if (!validAccount(account1) || !validAccount(account2)) {
      return false;
    }
    // insuffcient
    if (acts_[account1 - 1] < money) {
      return false;
    }
    acts_[account1 - 1] -= money;
    acts_[account2 - 1] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    if (!validAccount(account)) {
      return false;
    }
    acts_[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (!validAccount(account)) {
      return false;
    }

    if (acts_[account - 1] < money) {
      return false;
    }
    acts_[account - 1] -= money;

    return true;
  }

private:
  bool validAccount(int index) {
    if (index < 1 || index > sz_) {
      return false;
    }
    return true;
  }

private:
  vector<long long> acts_;
  int sz_;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
