// http://leetcode.com/problems/design-circular-queue/description/
#include "xxx.hpp"

class MyCircularQueue {
public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) : n_(k), beg_(0), readable_(0) {
    if (k <= 0) {
      data_ = vector<int>{};
      return;
    }
    data_ = vector<int>(k, 0);
  }

  /** Insert an element into the circular queue. Return true if the operation is
   * successful. */
  bool enQueue(int value) {
    if (readable_ == n_) {
      return false;
    }
    data_[(readable_ + beg_) % n_] = value;
    readable_++;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is
   * successful. */
  bool deQueue() {
    if (readable_ == 0) {
      return false;
    }
    readable_--;
    if (beg_ == n_ - 1) {
      beg_ = 0;
    } else {
      beg_++;
    }
    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (readable_ == 0) {
      return -1;
    }
    return data_[beg_];
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (readable_ == 0) {
      return -1;
    }
    // readable_ + beg_是下一个可写的位置，所以当前可读的rear在这个位置之前
    return data_[(readable_ + beg_ - 1) % n_];
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return readable_ == 0; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return readable_ == n_; }

private:
  vector<int> data_;
  int n_;
  int beg_;
  int readable_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
