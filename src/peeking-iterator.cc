// http://leetcode.com/problems/peeking-iterator/description/
#include "simpleone.h"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const vector<int> &nums);
  Iterator(const Iterator &iter);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const vector<int> &nums) : Iterator(nums) {
    // Initialize any member here.
    // **DO NOT** save a copy of nums and manipulate it directly.
    // You should only use the Iterator interface methods.

    // 那就只能用缓存的方法来咯
    peeked_ = false;
    cache_ = -1;
  }

  // Returns the next element in the iteration without advancing the iterator.
  int peek() {
    if (!peeked_) {
      cache_ = next();
      peeked_ = true;
      return cache_;
    }

    return cache_;
  }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() {
    if (peeked_) {
      peeked_ = false;
      return cache_;
    }
    return Iterator::next();
  }

  bool hasNext() const {
    if (peeked_) {
      return true;
    }
    return Iterator::hasNext();
  }

private:
  bool peeked_;
  int cache_;
};
