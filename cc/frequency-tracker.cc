// https://leetcode.com/problems/frequency-tracker/
#include "xxx.hpp"

class FrequencyTracker {
public:
  FrequencyTracker() {}

  void add(int number) {
    if (num_freq_.count(number)) {
      auto old_freq = num_freq_[number];
      freq_cnt_[old_freq]--;
      if (freq_cnt_[old_freq] == 0) {
        freq_cnt_.erase(old_freq);
      }
    }

    num_freq_[number]++;
    freq_cnt_[num_freq_[number]]++;
  }

  void deleteOne(int number) {
    if (num_freq_.count(number)) {
      auto old_freq = num_freq_[number];
      freq_cnt_[old_freq]--;
      if (freq_cnt_[old_freq] == 0) {
        freq_cnt_.erase(old_freq);
      }
      // the lower next should increase
      if (old_freq > 1) {
        freq_cnt_[old_freq - 1]++;
      }

      num_freq_[number]--;
      if (num_freq_[number] == 0) {
        num_freq_.erase(number);
      }
    }
    // do nothing when not exist
  }

  bool hasFrequency(int frequency) { return freq_cnt_.count(frequency); }

private:
  // number frequency record
  map<int, int> num_freq_;
  // for each frequency in value part of num_freq_
  // we record this frequency's frequency
  // e.g.
  // num_freq_ has {3, 1}, {2, 1}, {4, 1}
  // freq_cnt_ should be: {1, 3}
  // means 3 number has frequency of 1
  map<int, int> freq_cnt_;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
