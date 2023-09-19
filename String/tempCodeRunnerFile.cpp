bool isVowel(char ch)
{
    ch = tolower(ch); // conver upper to lower
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s)
{
    int start = 0;
    int end = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[start]) && isVowel(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (!isVowel(s[start]))
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return s;
}