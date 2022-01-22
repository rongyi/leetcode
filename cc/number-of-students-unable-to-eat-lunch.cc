// http://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
#include "xxx.hpp"

class Solution {
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches) {
    deque<int> dq(students.begin(), students.end());
    const int n = sandwiches.size();
    int cur_s = 0;
    while (!dq.empty()) {
      if (cur_s == n) {
        return dq.size();
      }
      vector<int> poped;
      // 学生和当前饼不匹配，走你
      while (!dq.empty() && (sandwiches[cur_s] ^ dq.front())) {
        poped.push_back(dq.front());
        dq.pop_front();
      }
      // 都弹空了也没配得上,剩下的学生狗都吃不着了
      if (dq.empty()) {
        return poped.size();
      }

      // 配上了，吃掉当前这块饼，学生拿着饼走掉
      cur_s++;
      dq.pop_front();

      // 没拿上的继续排在后面
      for (auto p : poped) {
        dq.push_back(p);
      }
    }

    return 0;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 1, 1, 0, 0, 1};
  vector<int> san{1, 0, 0, 0, 1, 1};
  cout << so.countStudents(input, san) << endl;
}
