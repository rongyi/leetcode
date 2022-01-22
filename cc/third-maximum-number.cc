// http://leetcode.com/problems/third-maximum-number/description/
#include "xxx.hpp"

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    priority_queue<int> pq;
    unordered_set<int> uniq;
    for (auto i : nums) {
      if (uniq.count(i) > 0) {
        continue;
      }
      uniq.insert(i);

      pq.push(i);
      // if (pq.size() > 3) {
      //   pq.pop();
      // }
    }
    if (pq.size() < 3) {
      return pq.top();
    }
    pq.pop();
    pq.pop();

    return pq.top();
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 2, 5, 3, 5};
  auto ret = so.thirdMax(input);
  cout << ret << endl;
}
