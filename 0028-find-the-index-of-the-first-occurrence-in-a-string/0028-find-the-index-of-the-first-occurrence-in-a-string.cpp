class Solution {
public:
    int strStr(string haystack, string needle) {
        auto position=haystack.find(needle);
        if(position == string::npos)
        {
            return -1;
        }
        return (int)position;
    }
};