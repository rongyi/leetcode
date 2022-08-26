// https://leetcode.com/problems/design-a-number-container-system/
#include "xxx.hpp"

class NumberContainers {
public:
  NumberContainers() {}

  void change(int index, int number) {
    if (keytoval_.count(index)) {
      valtokeys_[keytoval_[index]].erase(index);
    }

    keytoval_[index] = number;
    valtokeys_[number].insert(index);
  }

  int find(int number) {
    // count the value part, not key
    if (valtokeys_[number].size() > 0) {
      return *valtokeys_[number].begin();
    }

    return -1;
  }

private:
  map<int, int> keytoval_;
  map<int, set<int>> valtokeys_;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
