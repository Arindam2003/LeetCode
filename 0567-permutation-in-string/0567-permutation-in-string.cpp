class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);

        for(int i=0;i<s1.size();i++)
        {
            s1Count[s1[i]-'a']++;
        }

        for(int i=0;i<s2.size();i++)
        {
            s2Count[s2[i]-'a']++;

            if(i>=s1.size())
            {
                s2Count[s2[i-s1.size()]-'a']--;
            }

            if(s1Count==s2Count)
            {
                return true;
            }
        }

        return false;

    }
};