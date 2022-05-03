// https://leetcode.com/problems/design-an-atm-machine/
#include "xxx.hpp"

class ATM {
public:
  ATM() {
  }

  void deposit(vector<int> banknotesCount) {
    for (int i = 0; i < 5; ++i) {
      moneys_[i] += banknotesCount[i];
    }
  }

  vector<int> withdraw(int amount) {
    bool succ = false;
    vector<int> spit_out(5, 0);
    for (int i = 4; i >= 0; --i) {
      if (moneys_[i] == 0) {
        continue;
      }
      // then we must use this larger money first
      if (amount >= page_lst_[i]) {
        int cur_spit_out = amount / page_lst_[i];
        // at most thos nums
        if (cur_spit_out > moneys_[i]) {
          cur_spit_out = moneys_[i];
        }

        moneys_[i] -= cur_spit_out;
        amount -= page_lst_[i] * cur_spit_out;
        spit_out[i] = cur_spit_out;

        if (amount == 0) {
          succ = true;
          break;
        }
      }
    }

    if (succ) {
      return spit_out;
    }

    // we didn't make it, restore back
    for (int i = 0; i < 5; ++i) {
      moneys_[i] += spit_out[i];
    }

    return {-1};
  }

private:
  array<int, 5> page_lst_ = {20, 50, 100, 200, 500};
  array<long long, 5> moneys_ = {};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
