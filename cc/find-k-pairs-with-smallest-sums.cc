// http://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
#include "xxx.h"

class Solution {
private:
  struct mycompare {
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
      return p1.first + p1.second < p2.first + p2.second;
    }
  };

public:
  vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                        int k) {
    vector<pair<int, int>> ret;
    // pq是一个大顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;

    for (int i = 0; i < min((int)nums1.size(), k); i++) {
      for (int j = 0; j < min((int)nums2.size(), k); j++) {
        if (pq.size() < k) {
          pq.push({nums1[i], nums2[j]});
        } else if (nums1[i] + nums2[j] < pq.top().first + pq.top().second) {
          pq.push({nums1[i], nums2[j]});
          // 把大的都逼走
          pq.pop();
        }
      }
    }

    while (!pq.empty()) {
      ret.push_back(pq.top());
      pq.pop();
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input1{1, 7, 11};
  vector<int> input2{2, 4, 6};
  auto ret = so.kSmallestPairs(input1, input2, 3);
  for (auto p : ret) {
    cout << p.first << "  :  " << p.second << endl;
  }
}
