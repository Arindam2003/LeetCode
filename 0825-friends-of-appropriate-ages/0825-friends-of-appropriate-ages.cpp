class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int total = 0;
        
        int left = 0, right = 0;

        for (int i = 0; i < n; ++i) {
            int age = ages[i];
            if (age < 15) continue; 
            
            
            while (ages[left] <= 0.5 * age + 7) left++;

            
            while (right + 1 < n && ages[right + 1] <= age) right++;

            total += right - left;  
        }
        return total;
    }
};