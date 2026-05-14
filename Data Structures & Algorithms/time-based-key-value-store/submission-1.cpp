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
        if(curr.empty()) return "";
        sort(curr.begin(),curr.end(),greater<pair<int,string>>());
        if(curr[0].second>timestamp) return "";
        return curr[0].second;    
    }
};
