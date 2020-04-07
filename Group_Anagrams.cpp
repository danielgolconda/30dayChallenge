class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> mp;
        map<vector<int>,vector<string>> :: iterator it;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> v(26,0);
            string p = strs[i];
            for(int j=0;j<p.size();j++)
            {
                char c = p[j];
                v[c-'a']++;
            }
            mp[v].push_back(p);
        }
        //ans.resize(mp.size());
        for(it = mp.begin();it!=mp.end();it++)
        {
          ans.push_back(it->second);
        }
        return ans;
    }
};
