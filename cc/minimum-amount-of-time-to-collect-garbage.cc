// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
#include "xxx.hpp"

class Solution {
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    int sz = garbage.size();
    vector<int> metals(sz, 0);  // M
    vector<int> glasses(sz, 0); // G
    vector<int> papers(sz, 0);  // P
    vector<int> path_prefix(sz, 0);

    for (int i = 0; i < travel.size(); ++i) {
      // we don't add one by one, we just cnt the path along the way
      path_prefix[i + 1] = path_prefix[i] + travel[i];
    }
    for (int i = 0; i < sz; ++i) {
      metals[i] = count(garbage[i].begin(), garbage[i].end(), 'M');
      papers[i] = count(garbage[i].begin(), garbage[i].end(), 'P');
      glasses[i] = count(garbage[i].begin(), garbage[i].end(), 'G');
    }

    int ret = 0;
    ret += sum(metals, path_prefix);
    ret += sum(glasses, path_prefix);
    ret += sum(papers, path_prefix);

    return ret;
  }

private:
  int sum(vector<int> &cnt, vector<int> &path_prefix) {
    int sz = cnt.size();
    int total = 0;
    // metals
    int i = 0;
    while (i < sz && cnt[i] == 0) {
      i++;
    }
    int j = sz - 1;
    while (j >= 0 && cnt[j] == 0) {
      --j;
    }
    // becareful! panic if not check j
    // that means we need all path from start to j
    if (j >= 0) {
      total += path_prefix[j];
    }

    for (; i <= j; i++) {
      total += cnt[i];
    }

    return total;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<string> input{"G", "P", "GP", "GG"};
  vector<int> input2{2, 4, 3};
  cout << so.garbageCollection(input, input2) << endl;

  return 0;
}
