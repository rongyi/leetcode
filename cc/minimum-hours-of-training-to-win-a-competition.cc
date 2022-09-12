// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
#include "xxx.hpp"

class Solution {
public:
  // shitty problem
  int minNumberOfHours(int initEnergy, int initialExperience,
      vector<int> &energy, vector<int> &experience) {
    int ret = 0;
    int sz = energy.size();
    // both energy and experience must stricly greater
    for (int i = 0; i < sz; ++i) {
      // energy part
      if (initEnergy <= energy[i]) {
        ret += energy[i] + 1 - initEnergy;
        initEnergy = energy[i] + 1;
      }
      initEnergy -= energy[i];

      // experience part
      if (initialExperience <= experience[i]) {
        ret += experience[i] + 1 - initialExperience;
        initialExperience = experience[i] + 1;
      }
      initialExperience += experience[i];
    }

    return ret;
  }
};
