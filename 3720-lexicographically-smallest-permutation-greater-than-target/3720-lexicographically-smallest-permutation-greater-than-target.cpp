class Solution {
public:

    bool solve(string &s, string &target, vector<int>& count,
               string &curr, bool greater, int i) {

        // All characters are used
        if (i == s.length()) {
            return greater;
        }

        // Try every available character
        for (int c = 0; c < 26; c++) {

            if (count[c] == 0)
                continue;

            char ch = 'a' + c;

            // If we are still equal to target,
            // we cannot choose a smaller character
            if (!greater && ch < target[i])
                continue;

            // Check whether we become greater
            bool newGreater = greater || (ch > target[i]);

            // Choose
            curr.push_back(ch);
            count[c]--;

            // Explore
            if (solve(s, target, count, curr, newGreater, i + 1))
                return true;

            // Backtrack
            count[c]++;
            curr.pop_back();
        }

        return false;
    }

    string lexGreaterPermutation(string s, string target) {

        vector<int> count(26, 0);

        // Frequency of characters in s
        for (char ch : s) {
            count[ch - 'a']++;
        }

        string curr = "";

        solve(s, target, count, curr, false, 0);

        return curr;
    }
};