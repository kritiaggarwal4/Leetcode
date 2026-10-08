class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);

        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                pq.push({freq[i], i + 'a'});
            }
        }

        string ans = "";

        while(!pq.empty()) {
            vector<pair<int, char>> temp;

            for(int i = 0; i <= 1; i++) {

                if(pq.empty()) {
                    if(!temp.empty()) {
                        return "";
                    }
                    break;
                }

                int frequency = pq.top().first;
                char character = pq.top().second;

                pq.pop();

                ans += character;
                frequency--;

                if(frequency > 0) {
                    temp.push_back({frequency, character});
                }
            }

            for(auto x : temp) {
                pq.push(x);
            }
        }

        return ans;
    }
};