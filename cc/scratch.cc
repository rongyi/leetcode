#include "xxx.h"

uint32_t toint(string &ip) {
  uint32_t sum = 0;
  uint32_t field = 0;
  int i = 0;
  while (i < ip.size()) {
    if (ip[i] == '.') {
      sum += field;
      sum <<= 8;
      field = 0;
      i++;
    } else if (isdigit(ip[i])) {
      field = field * 10 + (ip[i] - '0');
      i++;
    } else {
      // do nothing
      if (isspace(ip[i])) {
        if (i > 0 && i < ip.size() - 1 && isdigit(ip[i - 1]) &&
            isdigit(ip[i + 1])) {
          return 0;
        }
      }
      i++;
    }
  }
  sum += field;
  return sum;
}

class Solutionmq {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      if (!dq.empty() && dq.front() == i - k) {
        dq.pop_front();
      }
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};

class Solution {
public:
  // void dfs(vector<vector<int>> &grid, int i, int j, vector<string> path) {
  //   const int m = grid.size();
  //   const int n = grid[0].size();
  //   if (i >= m || j >= n) {
  //     return;
  //   }
  //   stringstream ss;
  //   ss << "i: " << i << " j:" << j;
  //   path.push_back(ss.str());

  //   if (i == m - 1 && j == n - 1) {
  //     for (auto p : path) {
  //       cout << p << endl;
  //     }
  //     cout << "==========" << endl;
  //     return;
  //   }

  //   dfs(grid, i + 1, j, path);
  //   dfs(grid, i, j + 1, path);
  // }
  void dfs(string input, vector<int> &res) {
    if (input.size() == 0)
      return;
    bool all_digit = true;
    for (int i = 0; i < input.size(); i++) {
      if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
        all_digit = false;
        vector<int> l, r;
        dfs(input.substr(0, i), l);
        dfs(input.substr(i + 1, input.size() - i), r);
        for (auto x : l) {
          for (auto y : r) {
            if (input[i] == '+')
              res.push_back(x + y);
            else if (input[i] == '-')
              res.push_back(x - y);
            else
              res.push_back(x * y);
          }
        }
      }
    }
    if (all_digit)
      res.push_back(stoi(input));
  }
};

class Solution2 {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> result;
    int size = input.size();
    for (int i = 0; i < size; i++) {
      char cur = input[i];
      if (cur == '+' || cur == '-' || cur == '*') {
        // Split input string into two parts and solve them recursively
        vector<int> result1 = diffWaysToCompute(input.substr(0, i));
        vector<int> result2 = diffWaysToCompute(input.substr(i + 1));
        for (auto n1 : result1) {
          cout << n1 << "  n1" << endl;
          for (auto n2 : result2) {
            if (cur == '+')
              result.push_back(n1 + n2);
            else if (cur == '-')
              result.push_back(n1 - n2);
            else
              result.push_back(n1 * n2);
          }
        }
      }
    }
    // if the input string contains only number
    if (result.empty())
      result.push_back(atoi(input.c_str()));
    return result;
  }
};

struct mycompare {
  bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.first + p1.second < p2.first + p2.second;
  }
};

namespace rongyi {
// Ternary get ith bit value (0, 1 or 2)
int get(int prevN, int i) {
  prevN /= ((int)pow(3, i));
  return prevN % 3;
}

// Ternary set new-coming bit to value
int set(int currRow, int value) { return (currRow * 3 + value) % 243; }
} // namespace rongyi

int main() {
  // Solution so;
  // vector<vector<int>> input{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  // vector<string> path;
  // so.dfs(input, 0, 0, path);

  // unordered_map<int, int> test;
  // test[1] = 1;
  // for (int i = 0; i < 2; i++) {
  //   --test[i];
  // }
  // for (auto kv : test) {
  //   cout << kv.first << "--> " << kv.second << endl;
  // }

  // bool b1 = true;
  // bool b2 = false;
  // if (b1 ^ b2) {
  //   cout << "yes" << endl;
  // }

  // Solution2 so;
  // auto ret = so.diffWaysToCompute("2-1-1");
  // for (auto i : ret) {
  //   cout << i << endl;
  // }

  // Solutionmq so;
  // vector<int> input{1, 3, -1, -3, 5, 3, 6, 7};
  // auto ret = so.maxSlidingWindow(input, 3);
  // for (auto i : ret) {
  //   cout << i << endl;
  // }

  // 默认是大顶堆
  // priority_queue<int, vector<int>> max_heap;
  // priority_queue<int, vector<int>, std::less<int>> max_heap;
  // max_heap.push(1);
  // max_heap.push(2);
  // cout << max_heap.top() << endl;

  // priority_queue<int, vector<int>, std::greater<int>> min_heap;
  // min_heap.push(1);
  // min_heap.push(2);
  // cout << min_heap.top() << endl;

  // string s{"324"};
  // int i = 0;
  // if (s[0] == '-') {
  //   i++;
  // }
  // int j = i;
  // while (s[j] <= '9' && s[j] >= '0') {
  //   j++;
  // }
  // string number = s.substr(i, j - i);
  // cout << number << endl;

  // vector<int> i{1, 2, 3, 4};
  // i.erase(next(next(i.begin())));
  // cout << i.size() << endl;
  // for (int j = 0; j < i.size(); j++) {
  //   cout << i[j] << endl;
  // }

  // priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> pq;
  // pq.push({1, 3});
  // pq.push({1, 2});
  // cout << pq.top().first << "   :    " << pq.top().second << endl;
  // pq.pop();

  // cout << pq.top().first << "   :    " << pq.top().second << endl;

  // set::lower_bound/upper_bound
  std::set<int> myset;
  std::set<int>::iterator itlow, itup;

  for (int i = 1; i < 10; i++) {
    myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90
  }

  // >= 28里面找最小的
  // >=
  itlow = myset.lower_bound(21);
  cout << *itlow << endl;         // 30
  // 大于81的第一个
  // >
  itup = myset.upper_bound(80);
  cout << *itup << endl;          // 90

  // myset.erase(itlow, itup); // 10 20 70 80 90

  // std::cout << "myset contains:";
  // for (std::set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
  //   std::cout << ' ' << *it;
  // }
  // std::cout << '\n';

  // unordered_map<int, unordered_set<int>> s;
  // s[1].insert(2);
  // for (auto i : s[1]) {
  //   cout << i << endl;
  // }

  // unordered_map<int, int> test;
  // cout << 2 * test[0]++ << endl;
  // cout << 2 * test[0]++ << endl;
  // cout << test[0] << endl;

  // return value test
  // unordered_map<int, bool> dp;
  // cout << (dp[1] = false) << endl;

  // list<int> l;
  // auto ret = l.insert(l.begin(), 1);
  // cout << (ret == l.begin()) << endl;

  // int i = -4;
  // cout << i % 3 << endl;
  // i = -3;
  // cout << i % 3 << endl;

  // stringstream ss("119.118.113.110");
  // string section;
  // getline(ss, section, '.');
  // getline(ss, section, '.');
  // getline(ss, section, '.');
  // getline(ss, section, '.');
  // cout << section << endl;

  // cout << ((double)rand() / RAND_MAX) << endl;

  // cout << rand() << endl;

  // vector<int> ut{3, 7, 10};
  // auto it = lower_bound(ut.begin(), ut.end(), 8);
  // cout << it - ut.begin() << endl;

  // cout << rand() << endl;

  // string input{"1 72.168. 5 .1"};
  // cout << toint(input) << endl;
  // string zero{"0011"};
  // auto i = stoi(zero);
  // cout << i << endl;

  // string s{"aba"};
  // sort(s.begin(), s.end());
  // do {
  //   cout << s << endl;
  // } while (next_permutation(s.begin(), s.end()));

  // cout << 9 % (-2) << endl;
  // cout << -8 % 3 << endl;
  // cout << 0 % 3 << endl;

  // unordered_map<char, int> count;
  // count['A'] = 3;
  // count['D'] = 4;
  // vector<char> target{'A', 'D'};
  // for (auto t : target) {
  //   count.erase(t);
  // }
  // cout << count.size() << endl;

  // string test{"a\nb\nc\n"};
  // stringstream ss(test);
  // auto ret = count(istreambuf_iterator<char>(ss),
  // istreambuf_iterator<char>(), '\n');
  // cout << ret << endl;
  // ret = count(test.begin(), test.end(), '\n');
  // cout << ret << endl;

  // vector<int> test{1, 7, 7};
  // auto ret = accumulate(test.begin(), test.end(), 0);
  // cout << ret << endl;
  // ret = accumulate(test.begin(), test.end(), 1, multiplies<int>());
  // cout << ret << endl;

  // string test{"a\nb\nc\n"};
  // auto f = [](int prev, char c) { return (c != '\n' ? prev : prev + 1); };
  // // 0就是传到 f 的第一个参数
  // auto ret = accumulate(test.begin(), test.end(), 0, f);
  // cout << ret << endl;

  // auto is_not_space = [](const char &c) { return c != ' '; };
  // auto trim_left = [=](string s) {
  //   s.erase(s.begin(), find_if(s.begin(), s.end(), is_not_space));
  //   return s;
  // };
  // auto trim_right = [=](string s) {
  //   s.erase(find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
  //   return s;
  // };
  // string test{"     a     "};
  // cout << "|" << trim_left(test) << endl;
  // cout << "|" << trim_right(test) << "|" << endl;

  // can not see the stable or unstable
  // vector<bool> input{false, true, false, true, true, false};
  // partition(input.begin(), input.end(), [](bool v) { return !v; });
  // for (auto v : input) {
  //   cout << v << " ";
  // }
  // cout << endl;

  // vector<int> input{4, 3, 2, 1, 7, 8, 9, 1};
  // // partition(input.begin(), input.end(), [](int v) { return v < 5; });
  // stable_partition(input.begin(), input.end(),
  //                  [](int v) -> bool { return v < 5; });
  // // if you need order intact
  // for (auto v : input) {
  //   cout << v << " ";
  // }
  // cout << endl;

  // struct people {
  //   string name_;
  //   int aget_;
  //   bool is_man_;
  // };
  // vector<people> input{{"rongyi", 99, true},
  //                      {"xxx", 88, false},
  //                      {"yyy", 99, true},
  //                      {"zzz", 909, false}};
  // vector<people> female;
  // copy_if(input.begin(), input.end(), back_inserter(female),
  //         [](const people &p) { return !p.is_man_; });

  // // 记得这里要先分配好size， 否则coredump
  // vector<string> female_name(female.size());
  // transform(female.cbegin(), female.cend(), female_name.begin(),
  //           [](const people &p) { return p.name_; });
  // for (auto s : female_name) {
  //   cout << s << " ";
  // }
  // cout << endl;

  // vector<int> input{1, 2, 3, 4, 7};
  // auto end = remove_if(input.begin(), input.end(), [](const int &i) { return
  // i < 3; });
  // input.erase(end, input.end());
  // for (auto i : input) {
  //   cout << i << " ";
  // }
  // cout << endl;

  // function wrapper
  // function<float(float, float)> test_func;
  // test_func = multiplies<float>();
  // cout << test_func(3.14, 2) << endl;
  // float d{3.33};
  // test_func = [d](float a, float b) { return a + d + b; };
  // cout << test_func(3.14, 1) << endl;

  // string input{""};
  // // string input{"hello"};
  // function<bool(const string &)> f;
  // f = &string::empty;
  // cout << f(input) << endl;

  // partial application
  // auto thunk = bind(greater<int>(), 10, 9);
  // cout << thunk() << endl;
  // auto thunk2 = bind(greater<int>(), std::placeholders::_1, 9);
  // cout << thunk2(2) << endl;
  // cout << thunk2(10) << endl;

  // vector<int> input{1, 3, 7, 4, 5};
  // // sort(input.begin(), input.end(), bind(greater<int>(),
  // // std::placeholders::_2, std::placeholders::_1));
  // // same effect as above
  // sort(input.begin(), input.end());
  // for_each(input.begin(), input.end(), [](int i) { cout << i << " "; });
  // cout << endl;

  // unordered_set<string> s1;
  // s1.insert("hello");
  // s1.insert("world");
  // // it's not iterater, just the element
  // for (auto it : s1) {
  //   cout << it <<endl;
  // }

  // string s{"*/aaa/* xxx */"};
  // auto start = s.find("/*");
  // cout << start << endl;

  // auto end = s.rfind("*/");

  // cout << end << endl;
  // cout << s.size() - end - 1 << endl;

  // string s{"    /** / more comments here"};
  // auto idx = s.find_last_of("*/");
  // cout << idx << endl;
  // cout << s.substr(idx+2) << endl;

  // for (int i = 10; i < 100; i++) {
  //   if (i % 10 + i / 10 == 7) {
  //     cout << i << endl;
  //     break;
  //   }
  // }

  // map<int, int> m;
  // m.insert({1, 2});
  // m.insert({3, 3});
  // m.insert({4, 7});
  // auto it = m.upper_bound(3);
  // cout << (it == m.end()) << endl;
  // // // point to 4
  // cout << it->first << endl;
  // // it = m.upper_bound(7);
  // // cout << (it == m.end()) << endl;

  // string s{"1234"};
  // cout << s.substr(2, 1) << endl;

  // vector<int> input{3, 4, 5, 6, 7, 8, 9};
  // int n = input.size();
  // for (int i = 0; i < n; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     for (int k = j + 1; k < n; k++) {
  //       for (int l = k + 1; l < n; l++) {
  //         if (input[i] + input[j] + input[k] + input[l] == 23) {
  //           cout << input[i] << " + " << input[j] << " + " << input[k] << " +
  //           " << input[l] << "  "<< endl;
  //         }
  //       }
  //     }
  //   }
  // }

  // vector<int> input{1, 7, 3, 10, 0};
  // const int n = input.size();
  // sort, quick sort
  // for (int i = 1; i < n; ++i) {
  //   int tmp = input[i];
  //   int j = i - 1;
  //   for (; j >= 0 && input[j] > tmp; --j) {
  //     input[j + 1] = input[j];
  //   }
  //   input[j + 1] = tmp;
  // }
  // for (auto num : input) {
  //   cout << num << " ";
  // }
  // cout << endl;

  // string t{"alice,20,800,mtv"};
  // istringstream ss(t);
  // //  name, time (in minutes), amount, and city
  // vector<string> part(5, "");

  // int i = 0;
  // while (getline(ss, part[i++], ',')) {
  //   ;
  // }
  // cout << part[3] << endl;

  // cout << sizeof(int) << endl;
  // cout << sizeof(long) << endl;
  // cout << sizeof(long long) << endl;

  // vector<int> input{1, 4, 7, 9};
  // unordered_set<int> uniq{1, 4, 7, 9};

  // unordered_set<int> cur;
  // for (int i = 0; i < input.size(); ++i) {
  //   for (int j = i + 1; j < input.size(); ++j) {
  //     cout << input[i] * 10 + input[j] << endl;
  //     cout << input[j] * 10 + input[i] << endl;

  //   }
  //   cur.clear();
  // }
  // map<int, int> m;
  // m[2] = 3;
  // m[4] = 6;
  // auto it = m.lower_bound(3);
  // if (it == m.end()) {
  //   cout << "not found" << endl;
  // } else {
  //   cout << it->first << endl;
  // }
  // string s("aabc   ");
  // auto it = std::find_if_not(s.rbegin(), s.rend(), [](int c) -> bool {
  //   if (isspace(c)) {
  //     return true;
  //   }
  //   return false;
  // });
  // cout << *it << endl;
  // cout << s.rend() - it << endl;
  // cout << min({1, 2, -1}) << endl;

  // int n = 5;
  // int prevn = 0;
  // prevn = rongyi::set(prevn, 1);
  // prevn = rongyi::set(prevn, 0);
  // prevn = rongyi::set(prevn, 0);
  // prevn = rongyi::set(prevn, 0);
  // prevn = rongyi::set(prevn, 0);
  // cout << prevn << endl;
  // cout << rongyi::get(prevn, 1) << endl;

  // deque<int> q;
  // q.push_back(1);
  // q.push_back(7);
  // q.push_back(9);
  // q.insert(q.begin() + 1, 2);
  // q.pop_front();
  // auto cur = q.front();
  // cout << cur << endl;

  // vector<int> input(4, 0);
  // std::iota(input.begin(), input.end(), 2);
  // vector<vector<int>> input{{1, 2}, {3, 4}};
  // for (auto &i : input) {
  //   cout << i[3] << " ";
  // }
  // cout << endl;

  // multiset<int> ms;
  // ms.insert(1);
  // ms.insert(1);
  // cout << ms.size() << endl;
  // ms.erase(ms.find(1));
  // cout << ms.size() << endl;

  // bool reverse = false;
  // vector<vector<int>> group(4);
  // for (int i = 1; i <= 279; i++) {
  //   int index = (i + 3) / 4;
  //   // odd normal
  //   if (index & 1) {
  //     group[(i - 1) % 4].push_back(i);
  //   } else {
  //     // even reverse
  //     group[4 - (i - 1) % 4 - 1].push_back(i);
  //   }
  // }
  // for (int i = 0; i < 4; ++i) {
  //   for (auto n : group[i]) {
  //     cout << n << " ";
  //   }
  //   cout << endl;
  // }
}
