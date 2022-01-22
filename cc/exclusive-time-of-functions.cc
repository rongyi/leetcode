// http://leetcode.com/problems/exclusive-time-of-functions/description/
#include "xxx.hpp"

class Solution {
private:
  struct Log {
    int pid_;
    bool is_start_;
    int ts_;
  };

public:
  vector<int> exclusiveTime(int n, vector<string> &logs) {
    vector<int> ret(n, 0);
    stack<Log> stk;
    for (auto &s : logs) {
      auto l = parse(s);
      if (l.is_start_) {
        stk.push(l);
      } else {
        auto duration = l.ts_ - stk.top().ts_ + 1;
        ret[l.pid_] += duration;
        stk.pop();

        if (!stk.empty()) {
          // 这个时间是属于别的pid的，完全花在了睡眠上
          ret[stk.top().pid_] -= duration;
        }
      }
    }
    return ret;
  }

  Log parse(string &s) {
    bool is_start = s.find('s') != string::npos;
    string pid = s.substr(0, s.find(':'));
    int npid = stoi(pid);
    string stamp = s.substr(s.find_last_of(':') + 1);
    int nstamp = stoi(stamp);

    return {npid, is_start, nstamp};
  }
};

int main() {
  Solution so;
  string input{"0:start:9"};
  auto ret = so.parse(input);
  cout << ret.is_start_ << endl;
}
