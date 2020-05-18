bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size()) return false;
    int fre1[26] = {0}, fre2[26] = {0}, cnt = 0;
    for(int i = 0; i < s1.size(); i++) {fre1[s1[i] - 'a']++; fre2[s2[i]-'a']++;}
    for(int i = 0; i < 26; i++) { if(fre1[i] == fre2[i]) cnt++;}
    for(int i = 0; i < s2.size() - s1.size(); i++) {
        //Sliding Window approach
        int r = s2[i + s1.size()] - 'a', l = s2[i] - 'a';
        if(cnt == 26) return true;
        fre2[r]++;
        if(fre2[r] == fre1[r]) cnt++;
        else if(fre2[r] == fre1[r] + 1) cnt--;
        fre2[l]--;
        if(fre2[l] == fre1[l]) cnt++;
        else if(fre2[l] == fre1[l] - 1) cnt--;
    }
    return (cnt == 26);
}