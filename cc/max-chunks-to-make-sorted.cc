// https://leetcode.com/problems/max-chunks-to-make-sorted/description/

#include "xxx.h"
class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    const int n = arr.size();
    int ret = 0;
    int cur_max = 0;
    for (int i = 0; i < n; ++i) {
      cur_max = max(cur_max, arr[i]);
      if (i == cur_max) {
        ++ret;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{0, 1, 5, 3, 4, 2};
  auto ret = so.maxChunksToSorted(input);
  cout << ret << endl;
}
