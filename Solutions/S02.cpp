int numJewelsInStones(string J, string S) {
        int ans = 0;
        sort(J.begin(), J.end());
        sort(S.begin(), S.end());
        for(int i = 0, j = 0; i < S.size() && j < J.size();) {
            if(S[i] == J[j]) {
                i++;
                ans++;
            }
            else if(S[i] < J[j]) i++;
            else j++;
        }
        return ans;
    }