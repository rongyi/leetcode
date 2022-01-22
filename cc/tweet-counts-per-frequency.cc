// http://leetcode.com/problems/tweet-counts-per-frequency/description/
#include "xxx.hpp"

// 喷的很惨
class TweetCounts {
public:
  TweetCounts() {
    freq_toi_.insert({"minute", 60});
    freq_toi_.insert({"hour", 3600});
    freq_toi_.insert({"day", 86400});
  }

  void recordTweet(string tweetName, int time) {
    twits_[tweetName].push_back(time);
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    vector<int> ret;
    for (int i = 0; i <= (endTime - startTime) / freq_toi_[freq]; i++) {
      ret.push_back(0);
    }
    for (auto &time : twits_[tweetName]) {
      if (time >= startTime && time <= endTime) {
        int index = (time - startTime) / freq_toi_[freq];
        ret[index]++;
      }
    }

    return ret;
  }

private:
  unordered_map<string, vector<int>> twits_;
  unordered_map<string, int> freq_toi_;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 =
 * obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
