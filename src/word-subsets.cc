// http://leetcode.com/problems/word-subsets/description/
#include "xxx.h"

class Solution {
public:
  vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
    vector<string> ret;
    vector<int> count(26, 0);
    for (auto &b : B) {
      auto tmp = counter(b);
      for (int i = 0; i < 26; i++) {
        count[i] = max(count[i], tmp[i]);
      }
    }
    for (auto &s : A) {
      auto tmp = counter(s);
      int i = 0;
      for (i = 0; i < 26; i++) {
        if (tmp[i] < count[i]) {
          break;
        }
      }
      if (i == 26) {
        ret.push_back(s);
      }
    }
    return ret;
  }
  vector<int> counter(const string &s) {
    vector<int> ret(26, 0);
    for (auto c : s) {
      ret[c - 'a']++;
    }

    return ret;
  }

  // ========================
  vector<string> wordSubsetsTLE(vector<string> &A, vector<string> &B) {
    vector<unordered_map<char, int>> counts(A.size(),
                                            unordered_map<char, int>{});
    for (int i = 0; i < A.size(); i++) {
      unordered_map<char, int> cur_count;
      for (auto c : A[i]) {
        cur_count[c]++;
      }
      counts[i] = cur_count;
    }

    auto first_set = compsit(A, counts, B[0]);
    for (int i = 1; i < B.size(); i++) {
      first_set = intersection(first_set, compsit(A, counts, B[i]));
    }

    return vector<string>(first_set.begin(), first_set.end());
  }

  unordered_set<string> compsit(vector<string> &A,
                                vector<unordered_map<char, int>> &counts,
                                string &cur) {
    unordered_set<string> ret;

    unordered_map<char, int> check_count;
    for (auto c : cur) {
      check_count[c]++;
    }
    for (int i = 0; i < A.size(); i++) {
      if (issubset(counts[i], cur, check_count)) {
        ret.insert(A[i]);
      }
    }

    return ret;
  }
  bool issubset(unordered_map<char, int> &cur_count, const string &check,
                unordered_map<char, int> &check_count) {

    for (auto c : check) {
      if (cur_count.find(c) == cur_count.end()) {
        return false;
      }
      if (cur_count[c] < check_count[c]) {
        return false;
      }
    }
    return true;
  }

  unordered_set<string> intersection(const unordered_set<string> &l,
                                     const unordered_set<string> &r) {
    unordered_set<string> ret;
    for (auto s : l) {
      if (r.find(s) != r.end()) {
        ret.insert(s);
      }
    }
    return ret;
  }
  // subset, not subsequence
  bool issubsequence(const string &heystack, const string &check) {
    const int n = heystack.size();
    const int m = check.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (check[j] == heystack[i]) {
        j++;
      }
      if (j == m) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
  string input{"abcde"};
  string input2{"ce"};

  auto ret = so.issubsequence(input, input2);
  cout << ret << endl;
}
