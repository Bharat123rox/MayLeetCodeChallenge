int majorityElement(vector<int>& nums) {
    int ct = 1, cand = nums[0], freq = 0, n = nums.size();
    for(int i = 1; i < n; i++)
    {
        if(nums[i] != cand) ct--;
        else ct++;
        if(ct == 0)
        {
            cand = nums[i];
            ct = 1;
        }
    }
    return cand;
}