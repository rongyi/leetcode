// http://leetcode.com/problems/reveal-cards-in-increasing-order/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    const int n = deck.size();
    sort(deck.begin(), deck.end());
    queue<int> q;
    for (int i = 0; i < n; i++) {
      q.push(i);
    }
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
      ret[q.front()] = deck[i];
      q.pop();
      q.push(q.front());
      q.pop();
    }
    return ret;
  }
};
