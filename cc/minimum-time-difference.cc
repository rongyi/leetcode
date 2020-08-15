// http://leetcode.com/problems/minimum-time-difference/description/
#include "xxx.h"

class Solution {
public:
  int findMinDifference(vector<string> &timePoints) {
    // 按分来统计，然后sort
    vector<int> normal_mins;
    for (auto &s : timePoints) {
      normal_mins.push_back(normal(s));
    }
    sort(normal_mins.begin(), normal_mins.end());

    int ret = numeric_limits<int>::max();
    for (int i = 0; i < normal_mins.size() - 1; i++) {
      auto diff = abs(normal_mins[i + 1] - normal_mins[i]);
      // 1440 == 24 * 60
      ret = min(ret, min(diff, 1440 - diff));
    }
    // 不要忘记首尾也需要来一次，是环起来的
    auto diff = abs(normal_mins.back() - normal_mins.front());
    ret = min(ret, min(diff, 1440 - diff));

    return ret;
  }

public:
  int normal(string &input) {

    stringstream ss(input);
    string section;
    getline(ss, section, ':');

    int hour = 0;
    if (section[0] == '0') {
      hour = stoi(section.substr(1));
    } else {
      hour = stoi(section);
    }
    int min = 0;
    getline(ss, section, ':');
    if (section[0] == '0') {
      min = stoi(section.substr(1));
    } else {
      min = stoi(section);
    }

    return hour * 60 + min;
  }
};
int main() {
  Solution so;
  vector<string> input{"05:31", "22:08", "00:35"};
  auto ret = so.findMinDifference(input);
  cout << ret << endl;
}
