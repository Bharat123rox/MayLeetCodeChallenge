vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int fre[26] = {0};
    if(s.size() < p.size()) return res;
    for(char c: p) {fre[c-'a']++;}
    int st = 0, end = 0, cnt = p.size();
    while(end < s.size())
    {
        //Two pointer approach
        // If the starting character appeared in p, increment and move start pointer
        if(end - st == p.size() && fre[s[st++] - 'a']++ >= 0) cnt++;
        
        //If ending character appeared in p {since it's not < 0}, decrement and move end pointer
        if(--fre[s[end++]-'a'] >= 0) cnt--;
        
        //We have found one occurrence/match, since entire pattern size exhausted
        if(cnt == 0) res.push_back(st);
    }
    return res;
}