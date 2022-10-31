// https://leetcode.com/problems/optimal-partition-of-string/
#include "xxx.hpp"

class Solution {
public:
  int partitionString(string s) {
    set<char> prev;
    int ret = 0;
    // just do as they say
    for (auto &c : s) {
      if (prev.count(c)) {
        ret += 1;
        prev.clear();
      }
      prev.insert(c);
    }

    // don't forget the last one
    return ret + 1;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.partitionString("hdklqkcssgxlvehva");
  return 0;
}
