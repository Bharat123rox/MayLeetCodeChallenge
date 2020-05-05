int firstUniqChar(string s) {
        unordered_map<char, int> pos;
        for(int i = 0; i < s.size(); i++)
        {
            if(pos.find(s[i]) == pos.end())
            {
                pos.insert({s[i], i});
            }
            else pos[s[i]] = -2;
        }
        int ans = s.size() + 1;
        for(auto itr = pos.begin(); itr != pos.end(); itr++)
        {
            if(itr->second != -2) {
                ans = min(ans, itr->second);
            }
        }
        if(ans == s.size() + 1) ans = -1;
        return ans;
}