class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return (a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1]);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> res;
        sort(points.begin(), points.end(), cmp);
        for(int i = 0; i < K; i++) res.push_back(points[i]);
        return res;
    }
};