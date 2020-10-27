#include "headers.h"

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());

    return wordBreak(s, dict);
  }
  bool wordBreak(const string &s, const unordered_set<string> &dict) {
    if (memo.count(s)) return memo[s];
    if (dict.count(s)) return memo[s] = true;
    for (size_t i = 1; i < s.length(); i++) {
      const auto left = s.substr(0, i);
      const auto right = s.substr(i);
      if (wordBreak(left, dict) && dict.count(right)) {
        return memo[s] = true;
      }
    }
    return memo[s] = false;
  }

 private:
  unordered_map<string, bool> memo;
};
TEST(wordBreak, wordBreak) {
  Solution s;
  vector<string> v{"a", "b"};
  EXPECT_EQ(s.wordBreak("ab", v), true);
  vector<string> v2{"aaaa", "aaa"};
  EXPECT_EQ(s.wordBreak("aaaaaaa", v2), true);
  vector<string> v3{"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                    "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
  auto astr =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaa";
  EXPECT_EQ(s.wordBreak(astr, v3), false);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}