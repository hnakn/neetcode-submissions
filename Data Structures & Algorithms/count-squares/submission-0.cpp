class CountSquares {
private:
    
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        if(mp.count({point[0],point[1]})==0) mp[{point[0],point[1]}] = 1;
        mp[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int result = 0;

        int x = point[0],y = point[1];
        for(autu& it : mp)
        {
            if(abs(it.first.first-x)-abs(it.first.second-y)==0)
            {
                if(mp.count({it.first.first,y}) && mp.count({x,it.first.second}))
                {
                    result += min({mp[x],mp[y],mp[it.first.first],mp[it.first.second]});
                }
            }
        }
        return result;
    }
};
