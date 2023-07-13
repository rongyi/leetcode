// https://leetcode.com/problems/maximum-sum-queries/
#include "xxx.hpp"

class Solution {
public:
  vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2,
                                vector<vector<int>> &queries) {
    int sz = nums1.size();
    vector<pair<int, int>> bind(sz);
    for (int i = 0; i < sz; i++) {
      bind[i] = {nums1[i], nums2[i]};
    }
    // from bigger to small
    sort(bind.rbegin(), bind.rend());
    int qsz = queries.size();
    vector<int> idx(qsz, 0);
    iota(idx.begin(), idx.end(), 0);
    // also from bigger to small
    sort(idx.begin(), idx.end(),
         [&](int x, int y) { return queries[x][0] > queries[y][0]; });

    vector<int> ret(qsz);
    for (int i = 0, j = 0; i < qsz; i++) {
      // all the candicate, (nums1[i] >= queries[j].first)
      // all insert to map
      for (; j < sz && bind[j].first >= queries[idx[i]][0]; ++j) {
        update(bind[j].second, bind[j].first + bind[j].second);
      }
      ret[idx[i]] = query(queries[idx[i]][1]);
    }

    return ret;
  }

private:
  void update(int key, int value) {
    // ok, we will insert {nums2[i], nums1[i] + nums2[i]} to map
    // but before this insert action, we want to pop some value out
    auto it = vals_.lower_bound(key);
    // what's this check?
    // we know nums1 is from bigger to small
    // and so is nums2
    // so if we find lower_bound of current key,
    // that means the sum for current value is <= it->second?
    // why? because this sum = (nums1[j] + nums2[j])
    // but it->second = nums1[i] + nums2[i]
    // and here, nums2[j] <= nums2[i] because lower_bound is not nil
    // and i is before j, we can makesure nums1[j] <= nums1[i]
    // so the sum will not bigger than it->second
    // and we just take the bigger it->second as qualified sum
    // {nums1, nums2}从大到小排列，所以如果lower_bound(key) 不为空说明什么
    // 举个例子：
    // nums1[4, 4]
    // nums2[3, 2]
    // 一开始我们插入{3, 7}，因为一开始是空的
    // 后面我们准备插入{2, 6}，这个时候lower_bound(2)不为空
    // 表示什么意思呢？意味着带插入节点value 6 肯定不会比it->second还大，因为
    // 找到it不为空就意味着key首先比里面的小了，而且因为我们按照nums1从大到小，所以那个nums1[j]对应的位置也
    // 不会比之前的大，所以这个插进来没意义，因为key没有变大(<=)而sum也没有变大(<=
    // ) 总之说人话就是： key给我往下压，sum值还提不起来，要你何用？不要！
    if (it != vals_.end()) {
      return;
    }
    // 好，一个大的key进场！
    if (it != vals_.begin()) {
      --it;
      // 这个意思就是能抬高key就抬高key，前提是value>= 前面key的value
      // 好处是什么呢？好处是查询条件我们可以尽量去满足，而value又不会变小
      // 举个例子
      // nums1[10, 8, 7]
      // nums2[5, 6, 7]
      // 先是{5, 15}进场
      // 其次是{6, 14}
      // 当{7， 14}进场时我们就可以把{6,
      // 14}干掉，因为查询的key被我们抬高了，value不变
      while (it->second <= value) {
        if (it == vals_.begin()) {
          vals_.erase(it);
          break;
        } else {
          vals_.erase(it--);
        }
      }
    }
    // not found
    vals_.insert({key, value});
  }
  int query(int key) {
    auto it = vals_.lower_bound(key);
    if (it == vals_.end()) {
      return -1;
    }

    return it->second;
  }

private:
  // nums2[i] -> nums1[i] + nums2[i]
  map<int, int> vals_;
};

int main() {
  Solution so;
  map<int, int> val;
  val[4] = 3;
  val[6] = 4;
  auto it = val.lower_bound(7);
  vector<int> nums1{10, 8, 7};
  vector<int> nums2{5, 6, 7};
  vector<vector<int>> qs{{4, 1}, {1, 3}, {2, 5}};
  so.maximumSumQueries(nums1, nums2, qs);
}
