#include "../xxx.h"

int cnt(vector<int> &edges) {
  int sz = edges.size();
  int ret = 0;
  for (int i = 0; i < sz; i++) {
    for (int j = i + 1; j < sz; j++) {
      for (int k = j + 1; k < sz; k++) {
        int sum = edges[i] + edges[j] + edges[k];
        int max_len = max({edges[i], edges[j], edges[k]});
        int tw_sum = sum - max_len;
        if (tw_sum > max_len) {
          ret++;
        }
      }
    }
  }

  return ret;
}

int main(int argc, char *argv[]) {
  vector<int> edges;
  return 0;
}
