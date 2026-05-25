class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums) 
        {
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        x = k;
        
    }
    
    int add(int val) {
        pq.push(val);
        int result = pq.top();
        if(pq.size()>x) pq.pop();
        return pq.top();
    }
};
