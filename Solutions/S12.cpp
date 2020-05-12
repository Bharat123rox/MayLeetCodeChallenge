int singleNonDuplicate(vector<int>& nums) {
    //Fast I/O mattered more than algorithm complexity :P
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n = nums.size();
    int ans = nums[0];
    for(int i = 1; i < n; i++)
    {
        ans ^= nums[i];
    }
    return ans;
}