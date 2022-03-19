// https://leetcode.com/problems/design-bitset/
#include "xxx.hpp"

class Bitset {
public:
  Bitset(int size) : ones_(0) {
    bits_ = vector<int>(size, 0);
    flip_ = vector<int>(size, 1);
  }

  void fix(int idx) {
    if (bits_[idx] == 0) {
      ones_++;
    }
    bits_[idx] = 1;
    flip_[idx] = 0;
  }

  void unfix(int idx) {
    if (bits_[idx] == 1) {
      ones_--;
    }
    bits_[idx] = 0;
    flip_[idx] = 1;
  }

  void flip() {
    swap(bits_, flip_);
    ones_ = bits_.size() - ones_;
  }

  bool all() { return ones_ == bits_.size(); }

  bool one() { return ones_ > 0; }

  int count() { return ones_; }

  string toString() {
    string ret{};
    for (int i = 0; i < bits_.size(); ++i) {
      if (bits_[i] == 0) {
        ret.push_back('0');
      } else {
        ret.push_back('1');
      }
    }
    return ret;
  }

private:
  vector<int> bits_;
  vector<int> flip_;
  int ones_;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

class BitsetUsingSet {
public:
  Bitset(int size) : sz_(size) {
    for (int i = 0; i < size; ++i) {
      zeros_.insert(i);
    }
  }

  void fix(int idx) {
    auto it = zeros_.find(idx);
    if (it != zeros_.end()) {
      zeros_.erase(it);
    }

    ones_.insert(idx);
  }

  void unfix(int idx) {
    auto it = ones_.find(idx);
    if (it != ones_.end()) {
      ones_.erase(it);
    }

    zeros_.insert(idx);
  }

  void flip() { swap(zeros_, ones_); }

  bool all() { return ones_.size() == sz_; }

  bool one() { return ones_.size() > 0; }

  int count() { return ones_.size(); }

  string toString() {
    string ret;
    for (int i = 0; i < sz_; ++i) {
      if (zeros_.find(i) != zeros_.end()) {
        ret.push_back('0');
      } else {
        ret.push_back('1');
      }
    }
    return ret;
  }

private:
  set<int> zeros_;
  set<int> ones_;
  int sz_;
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
