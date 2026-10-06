class Solution {
public:

    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(!pq.empty() && k>0){
            int maxi = pq.top();
            pq.pop();
            pq.push(ceil(maxi/2.0));
            k--;
        }
        int res =0;
        while(!pq.empty()){
           res+=pq.top();
           pq.pop();
        }
        return res;
    }
};