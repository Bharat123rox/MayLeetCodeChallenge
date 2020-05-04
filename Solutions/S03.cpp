bool canConstruct(string ransomNote, string magazine)
{
    int fm[26] = {0}, fr[26] = {0};
    for (int i = 0; i < magazine.size(); i++)
    {
        fm[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.size(); i++)
    {
        fr[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (fr[i] > fm[i])
            return false;
    }
    return true;
}