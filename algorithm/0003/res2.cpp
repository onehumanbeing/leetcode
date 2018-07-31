#include <iostream>
#include <map>
#include <vector>
using namespace std;

// https://github.com/ZE3kr/LeetCode-Problems/blob/master/0001~0100/0003/main.cpp

class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		int answer = 0;
		int start = 0;
		int length;
		map<char, int> charPlace;
		for (int i = 0; i < s.length(); i++) {
			if (charPlace.find(s[i]) != charPlace.end()) {
				if (charPlace[s[i]] >= start) {
					start = charPlace[s[i]] + 1;
				}
				charPlace[s[i]] = i;
			} else {
				charPlace.insert(map<char, int>::value_type(s[i], i));
			}

			length = i - start + 1;
			if (length > answer) {
				answer = length;
			}
		}
		return answer;
	}
};

int main() {
	Solution s = Solution();
	cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	return 0;
}
