// http://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/
#include "xxx.h"
class Solution {
public:
  // https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/discuss/876998/C%2B%2B-Map

  // I think the time complexity is O(NlogN) and space O(N) but both the time
  // and space of this solution is less costly than the set+heap solution which
  // has O(NlogK) time and O(k) space. Is my time/space analysis wrong?

  // free[t] is the available time of server t. Initially free[t] = 0 for all 0
  // <= t < k. When a server t takes request i, free[t] = arrival[i] + load[i],
  // i.e. it's free at the end time of the request.

  // map<int, int> m is a map from the start time of a request to its
  // load/length. It stores the requests that are not yet handled.

  // We round-robin visit the servers. For the i-th request, we put it into the
  // request pool m as m[arrival[i]] = load[i]. Its corresponding i % k-th
  // server is free at free[i % k], so we scan (binary search) in the m to find
  // requests that this i % k-th server can handle.

  // Note that all the requests in m thus far are the leftover requests that
  // can't be handled by previous servers. So this i % k-th server can just take
  // whatever it can handle. Every time it handles a request, update its free
  // time to be the end time of the request, increment cnt[i % k], remove the
  // request from m, and keep find the next request that it can handle.

  // Every time a server successfully handles a request, we mark this round i as
  // the last successful round. If we've scanned k servers since the last
  // successful round but still haven't handled any leftover requests, then no
  // server could handle those leftover requests, we should break now.
  vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
    vector<int> cnt(k, 0);
    vector<int> free(k, 0);
    vector<int> ret;

    // 未处理的请求
    map<int, int> m;
    // 循环的是机器，不是请求
    for (int i = 0, last_i = 0;; ++i) {
      if (i < arrival.size()) {
        // 记录对应的开始结束时间
        m[arrival[i]] = load[i];
      } else if (i - last_i > k) {
        // 整整一轮没有找到新机器可run
        break;
      }
      // 大于等于当前ready的才能去运行
      // 当前对应的机器
      auto it = m.lower_bound(free[i % k]);
      while (it != m.end()) {
        last_i = i;
        ++cnt[i % k];
        free[i % k] = it->first + it->second;
        m.erase(it);
        it = m.lower_bound(free[i % k]);
      }
    }

    int max_req = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < k; ++i) {
      if (cnt[i] == max_req) {
        ret.push_back(i);
      }
    }

    return ret;
  }
};
