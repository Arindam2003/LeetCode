class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector <int>a(n+1);
        for(int i=0;i<shifts.size();i++)
        {
            if(shifts[i][2]==0)
            {
                a[shifts[i][0]]--;
                a[shifts[i][1]+1]++;
            }
            else
            {
                a[shifts[i][1]+1]--;
                a[shifts[i][0]]++;
            }
        }
        int change =0;
        for(int i=0;i<s.size();i++)
        {
            change+=a[i];
            int temp=s[i]-'a';
            temp=((temp+change)%26+26)%26;
            s[i]='a'+temp;
        }
        return s;
    }
};