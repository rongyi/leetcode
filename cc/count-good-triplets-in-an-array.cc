// https://leetcode.com/problems/count-good-triplets-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    int sz = nums1.size();
    vector<int> idx(sz, 0);
    for (int i = 0; i < sz; ++i) {
      idx[nums2[i]] = i;
    }

    long long ret = 0;
    // what we want?
    // increasing order by position
    // assume current pos is i
    // there are (i - 1) pos before i and (sz - 1 - i) after i
    // but how many in nums2?
    // so we cache this using bit(binary index tree)
    for (int i = 0; i < sz - 1; ++i) {
      long long mid = idx[nums1[i]];
      // for better understanding, the order should be this
      // add(mid, 1);
      // long long smaller = prefix_sum(mid) - 1;// exclude the mid itself

      long long smaller = prefix_sum(mid);
      add(mid, 1);
      // sz - 1 - mid is the right after mid in nums2
      // and we also need exclude the bigger one before i which is (i - smaller)
      long long greater = sz - 1 - mid - (i - smaller);
      ret += smaller * greater;
    }

    return ret;
  }

private:
  constexpr int static n_ = 100000;
  int bit[n_ + 1] = {};
  // if you don't understand following code:
  // https://medium.com/carpanese/a-visual-introduction-to-fenwick-tree-89b82cac5b3c
  int prefix_sum(int i) {
    int sum = 0;
    // i & (-i) ==> lowbit(i)
    // e.g. lowbit(1001) -> 0001
    //      lowbit(1100) -> 0100
    for (i = i + 1; i > 0; i -= i & (-i)) {
      sum += bit[i];
    }
    return sum;
  }
  void add(int i, int val) {
    for (i = i + 1; i <= n_; i += i & (-i)) {
      bit[i] += val;
    }
  }
};

int main(int argc, char *argv[]) {
  // do the following hello print?
  int i = 4;
  for (int i = i + 1; i < 3; ++i) {
    cout << "hello" << endl;
  }
  return 0;
}
