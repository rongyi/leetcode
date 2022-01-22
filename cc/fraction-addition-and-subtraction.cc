// http://leetcode.com/problems/fraction-addition-and-subtraction/description/
#include "xxx.hpp"

class Solution {
public:
  string fractionAddition(string s) {
    // -5/10-10/37
    vector<int> numers{};
    vector<int> denos{};
    bool is_neg = false;
    int i = 0;
    // 不会出现: -5/10-+10/37这种形式，所以
    // parser相对简单一点
    while (i < s.size()) {
      if (s[i] == '-') {
        is_neg = true;
        i++;
      } else if (s[i] == '+') {
        is_neg = false;
        i++;
      } else {
        // i is the start of digit
        int j = i;
        while (j < s.size() && isdigit(s[j])) {
          j++;
        }
        int cur_num = stoi(s.substr(i, j - i));
        // put all negative info to numerator
        if (is_neg) {
          cur_num = -cur_num;
        }
        numers.push_back(cur_num);
        // pass '/'
        j++;
        // mark i a new digit start
        i = j;

        // get all digit
        while (j < s.size() && isdigit(s[j])) {
          j++;
        }
        cur_num = stoi(s.substr(i, j - i));
        denos.push_back(cur_num);
        // final jump, j maybe the end or the
        // next round '-' or '+'
        i = j;
      }
    }

    unordered_set<int> uniq_denos(denos.begin(), denos.end());
    vector<int> denos_uniq(uniq_denos.begin(), uniq_denos.end());
    int all_lcm = denos_uniq[0];
    for (int i = 1; i < denos_uniq.size(); i++) {
      all_lcm = lcm(denos_uniq[i], all_lcm);
    }
    int sum = 0;
    for (int i = 0; i < numers.size(); i++) {
      sum += numers[i] * all_lcm / denos[i];
    }
    // 能整除
    if (sum % all_lcm == 0) {
      return to_string(sum / all_lcm) + "/1";
    }
    auto g = gcd(abs(sum), all_lcm);
    return to_string(sum / g) + "/" + to_string(all_lcm / g);
  }

private:
  int gcd(int x, int y) {
    int r;
    while (y > 0) {
      r = x % y;
      x = y;
      y = r;
    }
    return x;
  }

  int lcm(int x, int y) { return ((x * y) / gcd(x, y)); }
};

int main() {
  Solution so;
  auto ret = so.fractionAddition("7/3+5/2-3/10");
  cout << ret << endl;
}
