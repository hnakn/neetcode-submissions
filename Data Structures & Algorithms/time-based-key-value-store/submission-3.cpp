class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> curr = mp[key];
        string result = "";
        if(curr.empty()) return "";
        int l=0,r=curr.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(curr[mid].first<=timestamp) 
            {
                result = curr[mid].second;
                l=mid+1;
            }
            else r=mid-1;
        }
        return result;    
    }
};
