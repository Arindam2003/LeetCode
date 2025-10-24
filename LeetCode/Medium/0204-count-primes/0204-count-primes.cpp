class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> seive(n, 1); // set all are prime
        seive[0] = 0;
        seive[1] = 0;

        for (int i = 4; i < n; i += 2) {
            seive[i] = 0;
        }

        for (int i = 3; i * i < n; i += 2) {
            if (seive[i] == 1) {
                for (int j = i * i; j < n; j = j + i) {
                    seive[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (seive[i] == 1) {
                count++;
            }
        }
        return count;
    }
};