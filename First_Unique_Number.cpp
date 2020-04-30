class FirstUnique {
public:
    unordered_map <int,int> mp;
    queue <int> q;
    FirstUnique(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]) == mp.end())
            {
                mp[nums[i]]++;
                q.push(nums[i]);
            }
            else
            {
                mp[nums[i]]++;
            }
        }
    }
    
    int showFirstUnique() {
        while(mp[q.front()] > 1 && q.empty() == false)
        {
            q.pop();
        }
        if(q.empty())
        {
            return -1;
        }
        else
        {
            return q.front();
        }
    }
    
    void add(int value) {
        if(mp.find(value) == mp.end())
        {
            mp[value]++;
            q.push(value);
        }
        else
        {
            mp[value]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
