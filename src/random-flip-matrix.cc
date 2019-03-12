// http://leetcode.com/problems/random-flip-matrix/description/
#include "xxx.h"

class Solution {
public:
  Solution(int n_rows, int n_cols) : num_row_(n_rows), num_col_(n_cols) {
    size_ = num_row_ * num_col_;

    srand(time(nullptr));
  }

  // which chooses a 0 value uniformly at random, changes it to 1
  // 不是随机选一个点然后flip，是随机选一个0然后flip
  vector<int> flip() {
    int index = rand() % size_;
    while (flipped_.find(index) != flipped_.end()) {
      index = rand() % size_;
    }
    flipped_.insert(index);
    return {index / num_col_, index % num_col_};
  }

  void reset() {
    flipped_.clear();
  }

private:
  int num_row_;
  int num_col_;
  unordered_set<int> flipped_;
  int size_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */
int main() {
  Solution so(2, 2);
  so.flip();
  so.flip();
  so.flip();
  so.flip();
}
