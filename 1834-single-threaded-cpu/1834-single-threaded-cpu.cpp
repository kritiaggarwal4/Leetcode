class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
        vector<vector<int>>arr;
        for(int i=0;i<tasks.size();i++){
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

     priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int,int>>> pq; //min heap;
     sort(arr.begin(), arr.end());
     long long starttime = arr[0][0];
      int i=0;
      int n = arr.size();
     while(i<arr.size() || !pq.empty()){
       
        while(i<n && arr[i][0]<= starttime){
            pq.push({arr[i][1], arr[i][2]});
            i++;
        }
        if(pq.empty()){
            starttime = arr[i][0];
            continue;
        }
       long long processtime = pq.top().first;
        int idx = pq.top().second;
        ans.push_back(idx);
        pq.pop();
        starttime= starttime+processtime;
     }
return ans;
    }
};