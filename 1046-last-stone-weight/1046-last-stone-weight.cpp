class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int n = stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size()>1){
            int heaviest = pq.top();
            pq.pop();
            if(!pq.empty()){
            int secondheaviest = pq.top();
            pq.pop();
            pq.push(heaviest-secondheaviest);
            }
        }
        return pq.top();
    }
};