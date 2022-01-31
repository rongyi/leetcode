// https://leetcode.com/problems/time-needed-to-buy-tickets/
#include "xxx.hpp"

class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int step = 0;
    for (int i = 0; i < tickets.size(); ++i) {
      step += min(tickets[i], tickets[k] - (i > k));
    }

    return step;
  }
  int timeRequiredToBuyBruteForce(vector<int> &tickets, int k) {
    // simulation
    int step = 0;
    while (true) {
      for (int i = 0; i < tickets.size(); ++i) {
        if (tickets[i] == 0) {
          continue;
        }
        step++;
        tickets[i]--;
        if (tickets[k] == 0) {
          return step;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution so;
  vector<int> input{84, 49, 5, 24, 70, 77, 87, 8};
  so.timeRequiredToBuy(input, 3);
}
