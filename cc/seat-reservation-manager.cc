// http://leetcode.com/problems/seat-reservation-manager/description/
#include "xxx.h"

class SeatManager {
public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i) {
      pq_.push(i);
    }
  }

  int reserve() {
    auto cur = pq_.top();
    pq_.pop();

    return cur;
  }

  void unreserve(int seatNumber) { pq_.push(seatNumber); }

private:
  priority_queue<int, vector<int>, greater<int>> pq_;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
