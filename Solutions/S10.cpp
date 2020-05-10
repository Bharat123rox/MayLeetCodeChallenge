int findJudge(int N, vector<vector<int>>& trust) {
    unordered_map<int, int> truster, trusted;
    for(int i = 0; i < trust.size(); i++)
    {
        //Let trust[i][0] = Person a and trust[i][1] = Person b
        //truster -> No of persons whom person a trusts
        //trusted -> No of persons trusting person b
        truster[trust[i][0]]++;
        trusted[trust[i][1]]++;
    }
    for(int i = 1; i <= N; i++)
    {
        //Definition of town judge, trusts nobody and trusted by everyone
        if(truster[i] == 0 && trusted[i] == N - 1) return i;
    }
    return -1;
}