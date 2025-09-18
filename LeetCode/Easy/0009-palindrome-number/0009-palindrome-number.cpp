class Solution {
public:
    bool isPalindrome(int x) {
        string number=to_string(x);
        int left=0;
        int right=number.size()-1;
        while(left<=right)
        {
            if(number[left]!=number[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};