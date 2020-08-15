// http://leetcode.com/problems/teemo-attacking/description/
#include "xxx.h"

class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    if (timeSeries.empty()) {
      return 0;
    }

    unordered_set<int> uniq(timeSeries.begin(), timeSeries.end());
    vector<int> vec(uniq.begin(), uniq.end());
    sort(vec.begin(), vec.end());

    int ret = 0;
    for (int i = 0; i < vec.size() - 1; ++i) {
      ret += min(duration, vec[i + 1] - vec[i]);
    }
    ret += duration;

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2};
  cout << so.findPoisonedDuration(input, 2) << endl;
}
