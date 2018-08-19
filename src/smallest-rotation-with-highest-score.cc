// https://leetcode.com/problems/smallest-rotation-with-highest-score/description/
#include "one.h"
class Solution {
public:
  // https://leetcode.com/problems/smallest-rotation-with-highest-score/discuss/118725/Easy-and-Concise-5-lines-Solution-C++JavaPython?page=1
  // https://github.com/cherryljr/LeetCode/blob/master/Smallest%20Rotation%20with%20Highest%20Score.java
  // 1. 要求某一位置上值 <= 当前index  ==> A[i] <= i，对于数组的取值范围：
  // 0-数组长度，0放哪里都满足条件， N放哪里都不满足条件
  // 不算K0的值，把它当做一个基准值，然后算往后rotate（即K++的情景中）相对值变大还是变小，这样就能算出K等于多少时，值最大
  // 首先算得分的情况，最后一位放什么都满足条件（最大值N -1, 当前index为N -
  // 1)，所以每次rotation，值会因这个case增加1 其次算失分的情况，得分的位置是：
  // (i - A[i] + N) %
  // N，过了这个位置就开始失分了，在这个位置之前本来就不得分，所以算不上失。
  // 累加的时候算失多少分，还有个细节：
  // 由于是左移，坐标在不断减小，所以原先失分的地方，在K+1的时候还是失分

  // 参考网上的解法，以 K=0 的分值为基准，分析每次 K++
  // 后，rotate分值的变化情况。 因为每次旋转都会将 0位置的数 放到 A.length-1
  // 位置上，而所有数值的范围在 0~A.length-1 之间，因此必定会有 1 的得分。
  // 知道了 加分
  // 的情况，我们主要需要分析的就是旋转位置在哪的时候，会发生扣分的情况。
  // 这样求得每个位置相比与 K=0
  // 状态的分数变化信息之后，我们就能够得出在哪个位置旋转，得分是最大的了。

  // 分析可得：对于 ith 位置上的元素 A[i] 我们只有当旋转位置在 (i - A[i] + 1 +
  // N) % N 的时候，才会出现 扣分 的情况。 这里 +N 并对 N 进行取模是为了保证下标
  // index 在 0~N-1 上，防止越界。是一个较为常用的技巧。
  // 根据上述方式，我们计算出每个旋转位置的分值变化情况即可。
  // 此时计算出来的 changes[] 是基于上一个状态的比较，(分析的是每次 K++
  // 的分值变化情况) 因此最后我们需要将 chagnes[] 累加起来，这样其代表的就是以
  // K=0 状态为基准的分值变化数组了。 最后只需要取出 加分最大值
  // 所对应的下标即可。

  int bestRotation(vector<int> &A) {
    const int n = A.size();
    vector<int> change(n, 0);
    for (int i = 0; i < n; ++i) {
      change[(i - A[i] + n + 1) % n] -= 1;
    }
    for (int i = 1; i < n; ++i) {
      change[i] += change[i - 1] + 1;
    }

    return max_element(change.begin(), change.end()) - change.begin();
  }
};

int main() {
  Solution so;
  vector<int> input{2, 3, 1, 4, 0};
  auto test = so.bestRotation(input);
  cout << test << endl;
}
