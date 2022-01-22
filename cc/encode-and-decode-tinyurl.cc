// http://leetcode.com/problems/encode-and-decode-tinyurl/description/
#include "xxx.hpp"

class Solution {
public:
  Solution() : naive_(0), domain_("rytiny.com") {}
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    if (tiny_.find(longUrl) != tiny_.end()) {
      return tiny_[longUrl];
    }

    stringstream ss;
    ss << "http://" << domain_ << "/";
    ss << naive_++;
    auto tiny = ss.str();
    tiny_[longUrl] = tiny;
    rev_tiny_[tiny] = longUrl;

    return tiny;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    if (rev_tiny_.find(shortUrl) == rev_tiny_.end()) {
      return "";
    }

    return rev_tiny_[shortUrl];
  }

private:
  int naive_;
  string domain_;
  unordered_map<string, string> tiny_;
  unordered_map<string, string> rev_tiny_;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
