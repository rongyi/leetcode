// http://leetcode.com/problems/valid-square/description/
#include "xxx.hpp"

class Solution {
public:
  bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3,
                   vector<int> &p4) {
    vector<int> dists;
    dists.push_back(distSquare(p1, p2));
    dists.push_back(distSquare(p1, p3));
    dists.push_back(distSquare(p1, p4));
    dists.push_back(distSquare(p2, p3));
    dists.push_back(distSquare(p2, p4));
    dists.push_back(distSquare(p3, p4));
    sort(dists.begin(), dists.end());

    return dists[0] > 0 && dists[0] == dists[1] && dists[1] == dists[2] &&
           dists[2] == dists[3] && dists[4] == dists[5] &&
           dists[4] == 2 * dists[0];
  }

  long long distSquare(vector<int> &p1, vector<int> &p2) {
    long long d1 = p1[0] - p2[0];
    long long d2 = p1[1] - p2[1];
    return d1 * d1 + d2 * d2;
  }
};
