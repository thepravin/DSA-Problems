
// 1456. Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    bool checkVowel(char& ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int result = INT_MIN;

        int i = 0, j = 0;
        int currCount = 0;
        while (j <=
               n) { //<------------ IMP (if <n then , miss corrner case ==>last
                    // char is vowel and when count++ and j++ ==> j outoff bound
            // and result sore previous max not current)
            if ((j - i) < k) {
                if (checkVowel(s[j])) {
                    currCount++;
                }
                j++;
            } else { // shrink the window

                result = max(result, currCount);

                if (checkVowel(s[i])) {
                    currCount--;
                }
                i++;
            }
        }

        return result;
    }
};