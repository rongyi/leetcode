// http://leetcode.com/problems/array-of-doubled-pairs/description/
#include "xxx.hpp"

class Solution {
public:
  bool canReorderDoubled(vector<int> &A) {
    long long sum = accumulate(A.begin(), A.end(), 0ll);
    if (sum % 3 != 0) {
      return false;
    }
    unordered_map<int, int> count;
    for (auto num : A) {
      count[num]++;
    }
    vector<int> uniq;
    for (auto kv : count) {
      uniq.push_back(kv.first);
    }
    sort(uniq.begin(), uniq.end(),
         [](int l, int r) { return abs(l) < abs(r); });

    for (auto num : uniq) {
      // 不够消耗的
      if (count[2 * num] < count[num]) {
        return false;
      }
      count[2 * num] -= count[num];
    }

    return true;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 4, 8};
  auto ret = so.canReorderDoubled(input);
  cout << ret << endl;
}
