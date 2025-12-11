class Solution {
public:
    int number_count(int num) {
        int count = 0;
        while (num) {
            num = num / 10;
            count++;
        }
        return count;
    }
    int reverse(int x) {
        int countDigit = number_count(x); // 3
        long new_number = 0;
        while (x) {
            int rem; // 2
            rem = x % 10;
            new_number = new_number + rem * pow(10, countDigit - 1);
            countDigit--;
            x = x / 10;
        }
        if (new_number > INT_MAX || new_number < INT_MIN) {
            return 0;
        }
        return (int)new_number;
    }
};