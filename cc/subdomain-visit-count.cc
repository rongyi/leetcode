// https://leetcode.com/problems/subdomain-visit-count/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> subdomainVisits(vector<string> &cpdomains) {
    vector<string> ret;
    unordered_map<string, int> dict;
    for (auto sp : cpdomains) {
      auto c = count(sp);
      auto d = domain(sp);
      auto ss = sections(d);
      for (auto s : ss) {
        dict[s] += c;
      }
    }
    for (auto item : dict) {
      ret.push_back(to_string(item.second) + " " + item.first);
    }

    return ret;
  }

  // private:
  vector<string> sections(const string &domain) {
    vector<string> ret;
    ret.push_back(domain);
    auto split = domain;
    while (split.find(".") != string::npos) {
      auto cur_domain = split.substr(split.find(".") + 1);
      ret.push_back(cur_domain);
      split = cur_domain;
    }
    return ret;
  }

  int count(const string &cp) {
    auto intstr = cp.substr(0, cp.find(" "));
    return stod(intstr);
  }
  string domain(const string &cp) {
    auto domain = cp.substr(cp.find(" ") + 1);
    return domain;
  }
};

int main() {
  Solution so;
  int i = so.count("9001 discuss.leetcode.com");
  cout << (i == 9001) << endl;
  auto s = so.domain("9001 discuss.leetcode.com");
  cout << (s == "discuss.leetcode.com") << endl;

  auto sections = so.sections("discuss.leetcode.com");
  cout << "===" << endl;
  for (auto s : sections) {
    cout << s << endl;
  }

  vector<string> input{"9001 discuss.leetcode.com"};
  auto ret = so.subdomainVisits(input);
  for (auto s : ret) {
    cout << s << endl;
  }
}
