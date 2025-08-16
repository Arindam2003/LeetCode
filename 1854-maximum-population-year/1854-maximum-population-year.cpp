class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int arr[101] = {0};
        for (int i = 0; i < logs.size(); i++) {
            int dy = logs[i][1] - 1950;
            int by = logs[i][0] - 1950;
            arr[by]++;
            arr[dy]--;
        }
        int prefixarr[101];
        prefixarr[0] = arr[0];
        for (int i = 1; i < 101; i++) {
            prefixarr[i] = prefixarr[i - 1] + arr[i];
        }

        int maxPop = prefixarr[0];
        int year = 1950; // base year

        for (int i = 1; i < 101; i++) {
            if (prefixarr[i] > maxPop) {
                maxPop = prefixarr[i];
                year = 1950 + i;
            }
        }

        return year;
    }
};