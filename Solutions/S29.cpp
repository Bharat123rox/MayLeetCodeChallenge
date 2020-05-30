bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    list<int> adj[numCourses];
    vector<int> indeg(numCourses, 0), res;
    queue<int> q;
    int n = prerequisites.size();
    for(int i = 0; i < n; i++)
    {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        adj[b].push_back(a);
        indeg[a]++;
    }
    for(int i = 0; i < numCourses; i++)
    {
        if(indeg[i] == 0) {q.push(i);}
    }
    while(!q.empty())
    {
        int k = q.front();
        res.push_back(k);
        q.pop();
        for(auto it = adj[k].begin(); it != adj[k].end(); it++)
        {
            if(--indeg[*it] == 0) q.push(*it);
        }
    }
    return (res.size() == numCourses);
}