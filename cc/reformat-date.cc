// http://leetcode.com/problems/reformat-date/description/
#include "xxx.h"

class Solution {
public:
  string reformatDate(string date) {
    vector<string> month{"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    unordered_map<string, int> month_index;
    for (int i = 0; i < month.size(); ++i) {
      month_index[month[i]] = i + 1;
    }
    auto first_space = date.find(' ');
    auto second_space = date.find(' ', first_space + 1);

    ostringstream ss;

    auto y = date.substr(second_space + 1);
    ss << y;
    ss << '-';

    auto m = date.substr(first_space + 1, second_space - first_space - 1);

    auto curm = month_index[m];
    if (curm < 10) {
      ss << '0' << curm;
    } else {
      ss << curm;
    }
    ss << '-';

    auto d = date.substr(0, first_space);
    int i = 0;
    while (i < d.size() && isdigit(d[i])) {
      i++;
    }
    // only the digit part
    d = d.substr(0, i);
    if (d.size() < 2) {
      ss << '0' << d;
    } else {
      ss << d;
    }
    return ss.str();
  }
};

int main() {
  Solution so;
  cout << so.reformatDate("20th Oct 2052") << endl;
}
