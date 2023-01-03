// https://leetcode.com/problems/design-memory-allocator/
#include "xxx.hpp"

class Allocator {
public:
  Allocator(int n) {
    mem_.clear();
    mem_[0] = n;
  }

  int allocate(int size, int mID) {
    int val = -1;
    for (auto &kv : mem_) {
      // enough memory?
      if (kv.second >= size) {
        alloc_[mID].push_back({kv.first, size});

        int mem_left = kv.second - size;
        // put left to mem_
        if (mem_left > 0) {
          mem_[kv.first + size] = mem_left;
        }
        // clear the origin mem_

        val = kv.first;
        break;
      }
    }
    if (val != -1) {
      mem_.erase(val);
    }

    return val;
  }

  int free(int mID) {
    int sum = 0;
    for (auto &cur : alloc_[mID]) {
      sum += cur.second;
      // put back
      // are there mem can be merged?
      mem_[cur.first] = cur.second;
    }

    alloc_.erase(mID);
    // merge mem
    for (auto it = mem_.begin(); it != mem_.end();) {
      auto it2 = next(it);
      while (it2 != mem_.end() && it2->first == it->first + it->second) {
        it->second += it2->second;
        auto rm = it2;
        it2 = next(it2);
        mem_.erase(rm);
      }
      it = it2;
    }

    return sum;
  }

private:
  // start pos -> len
  map<int, int> mem_;
  // alloc ID -> {start, len}
  map<int, vector<pair<int, int>>> alloc_;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */

int main(int argc, char *argv[]) {
  Allocator alloc(10);
  return 0;
}
