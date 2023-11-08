#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
using namespace std;

int x = 0;
int y = 0;
int m = 0;
int n = 0;
// package size
int sz = 0;
int cur_sz = 0;
int timestamp = 0;
// count, timestamp
using PackageValue = pair<int, int>;
array<PackageValue, 17> inventory = {};

// 霰弹枪>突击步枪>射手步枪>栓动步枪>空手
array<int, 10> gun_priority{0, 3, 3, 2, 1, 3, 2, 2, 4, 4};
array<int, 10> gun_bullet{0, 14, 14, 14, 14, 15, 15, 15, 16, 16};
vector<vector<int>> dirs{{}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main_weapon = 0;
int sec_weapon = 0;

using GridValue = array<int, 3>;
vector<vector<GridValue>> grid(101, vector<GridValue>(101));

array<int, 17> space_unit = {0, 0,  0,  0,  0,  0, 0, 0, 0,
                             0, 50, 40, 30, 20, 2, 1, 5};

int lose = 0;
vector<vector<int>> visited(101, vector<int>(101, 0));

void switch_weapon() {
  auto v = grid[x][y][0];
  auto l1 = gun_priority[main_weapon];
  auto l2 = gun_priority[sec_weapon];
  auto lv = gun_priority[v];
  if (lv > l1) {
    main_weapon = v;
  } else if (lv != l1 && lv > l2) {
    sec_weapon = v;
  }
}

// id, num
void update_inventory() {
  auto id = grid[x][y][0];
  auto num = grid[x][y][1];
  auto space = space_unit[id] * num;
  if (cur_sz + space <= sz) {
    cur_sz += space;
    inventory[id].first += num;
    inventory[id].second = timestamp;
    return;
  }

  vector<int> ids(17, 0);
  iota(ids.begin(), ids.end(), 0);
  sort(ids.begin(), ids.end(), [&](auto &l, auto &r) {
    return inventory[l].second < inventory[r].second;
  });

  auto id1 = gun_bullet[main_weapon];
  auto id2 = gun_bullet[sec_weapon];
  for (auto id : ids) {
    if (cur_sz + space <= sz) {
      break;
    }
    if (inventory[id].first == 0 || id == id1 || id == id2 || id < 14) {
      continue;
    }
    int drop_num = (cur_sz + space - sz + space_unit[id] - 1) / space_unit[id];
    drop_num = min(drop_num, inventory[id].first);
    inventory[id].first -= drop_num;
    cur_sz -= drop_num * space_unit[id];
  }

  for (auto id : ids) {
    if (cur_sz + space <= sz) {
      break;
    }
    if (inventory[id].first == 0) {
      continue;
    }
    int drop_num = (cur_sz + space - sz + space_unit[id] - 1) / space_unit[id];
    drop_num = min(drop_num, inventory[id].first);
    inventory[id].first -= drop_num;
    cur_sz -= drop_num * space_unit[id];
  }
  cur_sz += space;
  inventory[id].first += num;
  inventory[id].second = timestamp;
}

void fight() {
  auto a = grid[x][y][1];
  auto b = grid[x][y][2];
  auto mea = inventory[gun_bullet[main_weapon]].first;
  auto meb = inventory[gun_bullet[sec_weapon]].first;
  if (mea >= a) {
    inventory[gun_bullet[main_weapon]].first -= a;
    cur_sz -= a * space_unit[gun_bullet[main_weapon]];
  } else if (meb >= b) {
    inventory[gun_bullet[sec_weapon]].first -= b;
    cur_sz -= b * space_unit[gun_bullet[sec_weapon]];
  } else {
    lose = 1;
  }
}

void entry() {
  if (visited[x][y]) {
    return;
  }
  visited[x][y] = 1;

  auto v = grid[x][y][0];
  if (v >= 1 && v <= 9) {
    switch_weapon();
  } else if (v >= 10 && v <= 16) {
    update_inventory();
  } else if (v == 17) {
    fight();
  }
}

int main() {
  // instruction
  int ops_sz = 0;
  cin >> m >> n >> sz >> ops_sz;
  sz *= 10;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j][0] >> grid[i][j][1];
      if (grid[i][j][0] == 17) {
        cin >> grid[i][j][2];
      }
    }
  }

  vector<int> ops(ops_sz, 0);
  for (int i = 0; i < ops_sz; i++) {
    cin >> ops[i];
  }

  x = 1;
  y = 1;
  entry();

  for (auto op : ops) {
    if (lose) {
      break;
    }
    timestamp++;
    x += dirs[op][0];
    y += dirs[op][1];
    entry();
  }

  if (lose) {
    printf("%d %d\n", x, y);
  } else {
    printf("%d\n", main_weapon);
    printf("%d\n", sec_weapon);

    vector<int> ids(17, 0);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](auto &l, auto &r) {
      return inventory[l].second < inventory[r].second;
    });
    for (auto id : ids) {
      if (inventory[id].first) {
        printf("%d %d\n", id, inventory[id].first);
      }
    }
  }
}

