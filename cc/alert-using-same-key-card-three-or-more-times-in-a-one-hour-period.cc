// http://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/
#include "xxx.h"

class Solution {
public:
  vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
    map<string, vector<int>> count;
    for (int i = 0; i < keyName.size(); ++i) {
      count[keyName[i]].push_back(time_to_int(keyTime[i]));
    }
    vector<string> ret;
    for (auto kv : count) {
      if (!check(kv.second)) {
        ret.push_back(kv.first);
      }
    }

    return ret;
  }

private:
  bool check(vector<int> &ts) {
    sort(ts.begin(), ts.end());

    int start_index = 0;

    // an hour window
    for (int i = 1; i < ts.size(); ++i) {
      // 当前元素在这个window里面
      if (ts[i] - ts[start_index] <= 60) {
        if (i - start_index + 1 >= 3) {
          return false;
        }
      } else {
        start_index++;
      }
    }
    return true;
  }
  int time_to_int(string &s) {
    auto h = s.substr(0, s.find(':'));
    auto m = s.substr(s.find(':') + 1);

    return std::stoi(h) * 60 + std::stoi(m);
  }
};

int main() {
  vector<string> input{"daniel", "daniel", "daniel", "luis",
                       "luis",   "luis",   "luis"};
  vector<string> input2{"10:00", "10:40", "11:00", "09:00",
                        "11:00", "13:00", "15:00"};
  Solution so;
  so.alertNames(input, input2);
}
