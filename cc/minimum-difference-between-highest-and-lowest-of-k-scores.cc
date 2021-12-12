// http://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/
#include "xxx.h"

class Solution {
public:
  int minimumDifference(vector<int> &nums, int k) {
    int ret = numeric_limits<int>::max();
    sort(nums.begin(), nums.end());
    // i - k + 1 >= 0
    // i >= k - 1
    // just pick the small and largest in k size window
    for (int i = 0; i + k <= nums.size(); ++i) {
      ret = min(ret, nums[i + k - 1] - nums[i]);
    }

    return ret;
  }
};

int main() {
  vector<int> input{87063, 61094, 44530, 21297, 95857, 93551, 9918};
  Solution so;
  cout << so.minimumDifference(input, 6) << endl;
}
