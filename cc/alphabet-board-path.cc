// http://leetcode.com/problems/alphabet-board-path/description/
#include "xxx.h"

class Solution {
public:
  // do we need bfs? may be not
  string alphabetBoardPath(string target) {
    target = "a" + target;
    ostringstream ss;
    for (int i = 1; i < target.size(); ++i) {
      ss << route(target[i - 1], target[i]);
      ss << "!";
    }

    return ss.str();
  }
private:
  string route(char from, char to) {
    if (from == to) {
      return "";
    }
    stringstream ss;
    if (from == 'z') {
      return "U" + route('u', to);
    }
    if (to == 'z') {
      return route(from, 'u') + "D";
    }

    int cold = (to - 'a') % 5 - (from - 'a') % 5;
    int rowd = (to - 'a') / 5 - (from - 'a') / 5;
    if (rowd != 0) {
      ss << string(abs(rowd), rowd > 0 ? 'D' : 'U');
    }

    if (cold != 0) {
      ss << string(abs(cold), cold > 0 ? 'R' : 'L');
    }

    return ss.str();
  }
};

int main() {
  Solution so;
  so.alphabetBoardPath("leetcode");
}
