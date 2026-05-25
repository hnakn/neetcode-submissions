class KthLargest {
private:
    priority_queue<int> pq;
    int x;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums) pq.push(i);
        x = k;
    }
    
    int add(int val) {
        int count = 0;
        vector<int> temp;
        pq.push(val);
        while(!pq.empty())
        {
            count++;
            if(count==x) 
            {
                int result = pq.top();
                for(int i : temp) pq.push(i);
                return result;
            }
            temp.push_back(pq.top());
            pq.pop();
        }
    }
};
