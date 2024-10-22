// http://leetcode.com/problems/clumsy-factorial/description/
#include "xxx.hpp"
#include <numeric>

class Solution {
public:
  int clumsy(int N) {
    auto nums = vector<int>();
    nums.push_back(N);
    int cur = N - 1;
    int index = 0;
    while (cur > 0) {
      int order = index % 4;
      if (order == 0 ){
        int val = nums.back();
        nums.pop_back();
        nums.push_back(val * cur);
      } else if (order == 1) {
        int val = nums.back(); nums.pop_back();
        nums.push_back(val / cur);
      } else if (order == 2) {
        nums.push_back(cur);
      } else {
        nums.push_back(-cur);
      }
      
      cur -= 1;
      index += 1;
    }
    return accumulate(nums.begin(), nums.end(), 0);
  }
};

int main() {
  Solution so;
  auto ret = so.clumsy(10);
  cout << ret << endl;
}
