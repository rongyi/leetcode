// https://leetcode.com/problems/reward-top-k-students/
#include "xxx.hpp"

class Solution {
public:
  vector<int> topStudents(vector<string> &positive_feedback,
                          vector<string> &negative_feedback,
                          vector<string> &report, vector<int> &student_id,
                          int k) {
    // {score, index}
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
        pq;
    auto wordsSet = [](string &s) -> map<string, int> {
      map<string, int> ret;
      int start = 0;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
          ret[s.substr(start, i - start)]++;
          start = i + 1;
        }
      }
      ret[s.substr(start)]++;

      return ret;
    };
    set<string> pset(positive_feedback.begin(), positive_feedback.end());
    set<string> nset(negative_feedback.begin(), negative_feedback.end());

    for (int i = 0; i < report.size(); ++i) {
      string &cur_report = report[i];
      int score = 0;
      auto rset = wordsSet(cur_report);
      for (auto &kv : rset) {
        if (pset.count(kv.first)) {
          score += 3 * kv.second;
        } else if (nset.count(kv.first)) {
          score -= kv.second;
        }
      }

      pq.push({score, -student_id[i]});
    }
    vector<int> ret;
    while (k-- && !pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      ret.push_back(-cur.second);
    }

    return ret;
  }
};
