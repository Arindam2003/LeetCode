class Solution {
public:
    void reverseString(vector<char>& s) {
        int size=s.size();
        int st=0,end=size-1;
        while(st<end)
        {
            int temp=s[st];
            s[st]=s[end];
            s[end]=temp;
            st++;
            end--;
        }
    }
};