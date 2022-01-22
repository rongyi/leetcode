// http://leetcode.com/problems/beautiful-array/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/beautiful-array/discuss/187669/Share-my-O(NlogN)-C%2B%2B-solution-with-proof-and-explanation
  vector<int> beautifulArray(int N) {
    vector<int> ret;
    for (int i = 0; i < N; i++) {
      ret.push_back(i + 1);
    }
    sort(ret, 0, N - 1, 1);
    return ret;
  }

private:
  void sort(vector<int> &v, int start, int end, int mask) {
    if (start >= end) {
      return;
    }

    int mid = partition(v, start, end, mask);
    sort(v, start, mid - 1, mask << 1);
    sort(v, mid, end, mask << 1);
  }
  int partition(vector<int> &v, int start, int end, int mask) {
    int j = start;
    for (int i = start; i <= end; i++) {
      if (v[i] & mask) {
        swap(v[i], v[j]);
        j++;
      }
    }
    return j;
  }
};
