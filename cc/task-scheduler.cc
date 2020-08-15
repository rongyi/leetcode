// http://leetcode.com/problems/task-scheduler/description/
#include "xxx.h"

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> count(26, 0);
    for (auto c : tasks) {
      count[c - 'A']++;
    }
    sort(count.begin(), count.end());
    int i = 25;
    while (i >= 0 && count[i] == count[25]) {
      i--;
    }
    // 最大值有这么多重复的
    int repeat = 25 - i;

    // slot有这么多
    // 拣频率最高的，拖出来作为标杆比如：AAA 2 这种情况
    // A##A##A##
    // 有这么多的gap
    int slot_count = count[25] - 1;
    // 1个就是n 个xxx
    // slotlen最大就是n自己，但是如果最大频率的字符有重复则需要缩小，为什么呢？
    // 因为其实就是最大频率那个自己已经在塞idle的位置了
    // A##A##A AAABBB
    // AB#AB#A

    int slot_len = n - (repeat - 1);
    int empty_slots = slot_count * slot_len;
    int available_tasks = tasks.size() - count[25] * repeat;
    int idles = max(0, empty_slots - available_tasks);

    return tasks.size() + idles;
  }
};

int main() {
  Solution so;
  vector<char> input{'A', 'A', 'A', 'B', 'B', 'B'};
  auto ret = so.leastInterval(input, 2);
  cout << ret << endl;
}
