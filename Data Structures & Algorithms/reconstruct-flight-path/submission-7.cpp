class Solution {
public:
    vector<string> result = {};
    void dfs(string curr, unordered_map<string,vector<string>>& adj, int count,vector<string>& curr_result)
    {
        if(!result.empty()) return;
        if(curr_result.size()==count+1) result = curr_result;        
        if(curr.size()==0) return;
        for(int i=0;i<adj[curr].size();i++)
        {
            string temp = adj[curr][i];
            if(temp.size()==0) continue;
            curr_result.push_back(temp);
            adj[curr][i]="";
            dfs(temp,adj,count,curr_result);
            adj[curr][i] = temp;
            curr_result.pop_back();
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        sort(tickets.begin(),tickets.end());
        for(auto& it : tickets)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<string> curr_result = {"JFK"};
        dfs("JFK",adj,tickets.size(),curr_result);        
        return result;
    }
};
