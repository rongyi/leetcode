// https://leetcode.com/problems/count-days-spent-together/
#include "xxx.hpp"

// shitty problem
//
class Solution {
public:
  int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                        string leaveBob) {
    vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> prefix(13, 0);
    for (int i = 0; i < 12; ++i) {
      prefix[i + 1] = month[i] + prefix[i];
    }
    auto [alice_start_month, alice_start_day] = parse(arriveAlice);
    auto [alice_end_month, alice_end_day] = parse(leaveAlice);
    auto [bob_start_month, bob_start_day] = parse(arriveBob);
    auto [bob_end_month, bob_end_day] = parse(leaveBob);

    if (bob_start_month > alice_end_month ||
        (bob_start_month == alice_end_month && bob_start_day > alice_end_day)) {
      return 0;
    }
    if (bob_end_month < alice_start_month ||
        (bob_end_month == alice_start_month && bob_end_day < alice_start_day)) {
      return 0;
    }

    pair<int, int> alice_duration = {prefix[alice_start_month] +
                                         alice_start_day,
                                     prefix[alice_end_month] + alice_end_day};

    pair<int, int> bob_duration = {prefix[bob_start_month] + bob_start_day,
                                   prefix[bob_end_month] + bob_end_day};

    int ret = min(alice_duration.second, bob_duration.second) -
              max(alice_duration.first, bob_duration.first) + 1;

    return ret;
  }

public:
  pair<int, int> parse(string &md) {
    string month = md.substr(0, 2);
    if (month[0] == '0') {
      month = month.substr(1);
    }
    string day = md.substr(3);
    if (day[0] == '0') {
      day = day.substr(1);
    }
    int m = stoi(month);
    int d = stoi(day);

    return {m - 1, d};
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  so.countDaysTogether("08-15", "08-18", "08-16", "08-19");
  return 0;
}
