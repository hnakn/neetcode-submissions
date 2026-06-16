class Solution {
public:
    vector<string> result = {};
    void dfs(string curr, unordered_map<string,vector<string>>& adj)
    {
        for(int i=0;i<adj[curr].size();i++)
        {
            string temp = adj[curr][i];
            if(temp.size()==0) continue;
            adj[curr][i]="";
            dfs(temp,adj);
        }
        result.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> adj;
        sort(tickets.begin(),tickets.end());
        for(auto& it : tickets)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        dfs("JFK",adj); 
        reverse(result.begin(),result.end());       
        return result;
    }
};
