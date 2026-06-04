class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        while(i<n/2)
        {
            swap(s[i],s[n-i-1]);
            i++;
        }
    }
};