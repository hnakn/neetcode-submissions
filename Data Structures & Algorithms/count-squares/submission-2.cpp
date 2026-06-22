class CountSquares {
private:
    unordered_map<int,unordered_map<int,int>> mp;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        if(mp.count(point[0])==0 || mp[point[0]].count(point[1])==0) mp[point[0]][point[1]] = 1;
        else mp[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int result = 0;

        int x = point[0],y = point[1];
        for(auto& it : mp)
        {
            for(auto i : it.second)
            {
                if(abs(it.first-x)-abs(i.first-y)==0 && x!=it.first)
                {
                    if(mp.count(it.first) && mp[it.first].count(y) && mp.count(x) && mp[x].count(i.first))
                    {
                        result += mp[x][i.first]*mp[it.first][y]*i.second;
                    }
                }
            }
        }
        return result;
    }
};
