// https://leetcode.com/problems/number-of-visible-people-in-a-queue/
#include "xxx.hpp"

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int> &heights) {
    int sz = heights.size();
    stack<int> st;
    vector<int> ret(sz, 0);
    for (int i = sz - 1; i >= 0; --i) {
      // all numbers are uniq
      while (!st.empty() && heights[i] > st.top()) {
        ret[i]++;
        st.pop();
      }
      // can see one more which is taller than me
      if (!st.empty()) {
        ret[i]++;
      }
      st.push(heights[i]);
    }
    return ret;
  }
};
