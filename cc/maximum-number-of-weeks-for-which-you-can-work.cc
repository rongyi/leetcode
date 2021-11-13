// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
#include "xxx.h"

class Solution {
public:
  //  I missed the big picture
  //  long long numberOfWeeks(vector<int> &milestones) {
  //    priority_queue<int> q(milestones.begin(), milestones.end());
  //    int ret = 0;
  //    while (!q.empty()) {
  //      auto cur = q.top();
  //      q.pop();
  //      if (q.empty()) {
  //        ret += 1;
  //        break;
  //      }
  //      auto below = q.top();
  //      q.pop();
  //      if (cur != below) {
  //        q.push(cur - below);
  //      }
  //      ret += (below * 2);
  //    }
  //
  //    return ret;
  //  }
  long long numberOfWeeks(vector<int> &milestones) {
    int mega_job = *max_element(milestones.begin(), milestones.end());
    long long sum = accumulate(milestones.begin(), milestones.end(), 0ll);
    long long rest = sum - mega_job;
    // work on the mega project, then one of the rest
    // work on the mega project, then one of the rest
    // till rest ==> 0
    // and work one more on the mega project
    if (mega_job > rest) {
      return rest * 2 + 1;
    }
    // why we can finish all?
    // Why the greedy strategy works?
    // Let's consider the case if n >= 3. (because if n == 1 -> only can finish
    // 1, if n == 2, we can only take turn working on it and _sum - _max must <
    // _max ) Let's say we have:

    // A max project with the most milestones: p milestones
    // A project with the second most milestones: q milestones
    // Rest of projects with r milestones in total, p + q + r == sum
    // if q + r >= p ( note: q + r is the sum of milestones except the max
    // project) We can do p-q rounds, each round, we work on the max project
    // first and the any one of the rest projects.
    // After one round, the milestones will be
    // p-1, q, r-1 respectively. So after p-q rounds, the
    // milestones will be p-(p-q) = q, q, r-(p-q) respectively. Because the
    // assumption of q + r >= p, r-(p-q) will be larger or equal to 0, it's
    // valid operations. Then we have two projects with q milestones each and it
    // means we can finish all the tasks (can refer to Example section)

    return sum;
  }
};

int main() {
  Solution so;
  vector<int> input{5, 7, 5, 7, 9, 7};
  so.numberOfWeeks(input);
}
