class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int size=s.size();
        unordered_set<char>uni;  //Store all unique. char
        for(int i=0;i<size;i++)
        {
            uni.insert(s[i]);
        }
        int result=0;
        for(char j:uni)
        {

            int left=-1;
            int right=-1;

            for(int k=0;k<size;k++)
            {
                if(s[k]==j){
                    if(left==-1){  //left index paor jnno first math element ashbe tarpor kono elem match holeo asbe na.     
                        left=k; //beacause akhn e left r -1 thkbe na change hobe.
                    }
                    right=k;  //same element right e paoar jnne.
                }
            }

            unordered_set<char>res; //Store uniq. in between left and right
            for(int i=left+1;i<=right-1;i++)
            {
                res.insert(s[i]);
            }
            result= result+ res.size();  // left and right same elem., in between them unique elem is the result.

        }
        return result;

    }
};