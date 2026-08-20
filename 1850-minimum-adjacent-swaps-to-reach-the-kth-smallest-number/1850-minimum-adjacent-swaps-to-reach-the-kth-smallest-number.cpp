class Solution {
public:
    int getMinSwaps(string num, int k) {
        string temp=num;
        while(k--)
        {
            next_permutation(temp.begin(), temp.end());
        }
        int swaps=0;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]!=temp[i])
            {
                int j=i+1;
                //find the target in num..
                while(num[j]!=temp[i])
                {
                    j++;
                }


                while(j>i)
                {
                    swap(num[j-1],num[j]);
                    swaps++;
                    j--;
                }
            }
        }
        return swaps;
    }
};