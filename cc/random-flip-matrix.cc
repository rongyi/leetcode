// http://leetcode.com/problems/random-flip-matrix/description/
#include "xxx.hpp"

class Solution1 {
public:
  Solution1(int n_rows, int n_cols) : num_row_(n_rows), num_col_(n_cols) {
    size_ = num_row_ * num_col_;

    srand(time(nullptr));
  }

  // which chooses a 0 value uniformly at random, changes it to 1
  // 不是随机选一个点然后flip，是随机选一个0然后flip
  // 这是野路子
  vector<int> flipMad() {
    int index = rand() % size_;
    while (flipped_.find(index) != flipped_.end()) {
      index = rand() % size_;
    }
    flipped_.insert(index);
    return {index / num_col_, index % num_col_};
  }

  void reset() { flipped_.clear(); }

private:
  int num_row_;
  int num_col_;
  unordered_set<int> flipped_;
  int size_;
};

class Solution {
public:
  Solution(int n_rows, int n_cols) : num_row_(n_rows), num_col_(n_cols) {
    size_ = num_row_ * num_col_;

    srand(time(nullptr));
  }

  // which chooses a 0 value uniformly at random, changes it to 1
  // 不是随机选一个点然后flip，是随机选一个0然后flip
  vector<int> flip() {
    int pos = rand() % size_;
    --size_;
    // 举例
    // 1 2 3 4 5 6 7 8
    // 假设随机摇中3的位置，我们此时要把该位置给flip了。 此时 size_--,
    // 把最后位置和位置3上的数字对换， 下一轮再摇到位置3时，我们此时就不是
    // 把原来的3给flip而是把8给flip了。这种关系就保存在map中。
    // 记录 pos ==> flip_index

    // 先假设这个位置就是可以flip的
    int flip_index = pos;
    // 不行，这个位置上之前已经flip过了，
    if (swap_history_.find(pos) != swap_history_.end()) {
      flip_index = swap_history_[pos];
    }

    if (swap_history_.find(size_) == swap_history_.end()) {
      swap_history_[pos] = size_;
    } else {
      // the postion size_ has been swapped, we need to find the real
      // index to flip
      // 这种情况产生于上一轮选到的是 size_ - 2这个位置(倒数第二个)的
      // e.g.
      // 1 2 3 4 5 6 7 8
      // 摇到7的位置，flip之后变成
      // 1 2 3 4 5 6 8 7
      // 所以再摇到相同位置选择的应该是8不是7
      swap_history_[pos] = swap_history_[size_];
    }

    return {flip_index / num_col_, flip_index % num_col_};
  }

  void reset() {
    swap_history_.clear();
    size_ = num_row_ * num_col_;
  }

private:
  int num_row_;
  int num_col_;
  // key: pos
  // value: the real index to be flipped
  unordered_map<int, int> swap_history_;
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
