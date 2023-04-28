// http://leetcode.com/problems/expression-add-operators/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ret;
    recur(num, target, 0, 0, 0, "", ret);

    return ret;
  }

  void recur(string &input, int target, int pos, long long cur_eval,
             long long prev, string cur, vector<string> &ret) {
    // output
    if (pos == input.size()) {
      if (cur_eval == target) {
        ret.push_back(cur);
      }
      return;
    }
    string cur_num_str;
    long long cur_num = 0;

    for (int i = pos; i < input.size(); i++) {
      // invalid input case, ignore leading zero
      if (i > pos && input[pos] == '0') {
        break;
      }
      cur_num_str += input[i];
      cur_num = cur_num * 10 + (input[i] - '0');

      // three operator action
      // but before that we should consider the initial case i.e.
      // start from 0
      if (pos == 0) {
        recur(input, target, i + 1, cur_num, cur_num, cur + cur_num_str, ret);
      } else {

        recur(input, target, i + 1, cur_eval + cur_num, cur_num,
              cur + "+" + cur_num_str, ret);
        recur(input, target, i + 1, cur_eval - cur_num, cur_num,
              cur + "-" + cur_num_str, ret);
        recur(input, target, i + 1, cur_eval - prev + prev * cur_num,
              prev * cur_num, cur + "*" + cur_num_str, ret);
      }
    }
  }
};
