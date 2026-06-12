class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        while(s[n-1]==' ')
        {
            n--;
        }


        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            
            if(s[i]=='/n' || s[i]==' ')
            {
                break;
            }
            count++;
        }
        return count;
    }
};