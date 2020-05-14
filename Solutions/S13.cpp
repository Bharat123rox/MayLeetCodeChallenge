string removeKdigits(string num, int k) {
    int n = num.size();
    char c;
    if(k >= n) return "0";
    for(int i = 0; i < k; i++)
    {
        int j = 0;
        while(j < n - 1 && num[j] <= num[j + 1]) j++;
        num.erase(num.begin() + j, num.begin() + j + 1);
    }
    
    //Remove leading zeros
    while(num.size() > 1 && num[0] == '0') num.erase(num.begin(), num.begin() + 1);
    
    return num;
}