class MedianFinder {
public:
    priority_queue<int> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxq.empty() || num<maxq.top())
        {
            maxq.push(num);
            while(maxq.size()>minq.size()+1)
            {
                minq.push(maxq.top());
                maxq.pop();
            }
        }
        else
        {
            minq.push(num);
            while(minq.size()>maxq.size()+1)
            {
                maxq.push(minq.top());
                minq.pop();
            }
        }
    }
    
    double findMedian() {
        if(maxq.size()==minq.size()) return double((maxq.top()+minq.top()))/2;
        else if(maxq.size()>minq.size()) return maxq.top();
        else return minq.top();
    }
};
