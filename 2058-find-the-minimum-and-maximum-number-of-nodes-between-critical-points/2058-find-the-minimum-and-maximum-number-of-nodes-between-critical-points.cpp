class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;
        int maxDist = 0;

        while (curr->next != nullptr) {

            ListNode* next = curr->next;

            // Check whether curr is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                if (first == -1) {
                    // First critical point
                    first = index;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - last);

                    // Distance from first critical point
                    maxDist = index - first;
                }

                last = index;
            }

            prev = curr;
            curr = next;
            index++;
        }

        if (first == last)
            return {-1, -1};

        return {minDist, maxDist};
    }
};