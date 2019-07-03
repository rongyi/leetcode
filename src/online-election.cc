// http://leetcode.com/problems/online-election/description/
#include "xxx.h"

class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    for (int i = 0; i < times.size(); i++) {
      time_winner_[times[i]] = persons[i];
    }
    unordered_map<int, int> count;
    int lead = -1;
    for (auto kv : time_winner_) {
      if (++count[kv.second] >= count[lead]) {
        lead = kv.second;
      }
      time_winner_[kv.first] = lead;
    }
  }

  int q(int t) {
    // 找到第一个大于这个时间的点，退一步等也好不等也好，反正符合要求
    return (--time_winner_.upper_bound(t))->second;
  }

private:
  // record each winner at time key
  map<int, int> time_winner_;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
