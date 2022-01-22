// http://leetcode.com/problems/snapshot-array/description/
#include "xxx.hpp"

class SnapshotArray {
public:
  SnapshotArray(int length) : cur_snap_{0} {}

  void set(int index, int val) { snaps_[index][cur_snap_] = val; }

  int snap() { return cur_snap_++; }

  int get(int index, int snap_id) {
    auto it = snaps_[index].upper_bound(snap_id);
    if (it == snaps_[index].begin()) {
      return 0;
    }
    return prev(it)->second;
  }

private:
  int cur_snap_;
  unordered_map<int, map<int, int>> snaps_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
