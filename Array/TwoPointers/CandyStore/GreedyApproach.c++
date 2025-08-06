class Solution {
public:
    vector<int> minMaxCandy(vector<int>& arr, int k) {
        // Sort the array to make it easier to access the cheapest and costliest candies
        sort(arr.begin(), arr.end());

        vector<int> res(2, 0);  // res[0] = min cost, res[1] = max cost
        int minCost = 0, maxCost = 0;

        // Calculate the minimum cost
        // Strategy: Always buy the cheapest available candy, and skip k costliest ones
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            minCost += arr[i];  // buy the cheapest candy
            i++;                // move to next cheapest
            j -= k;             // skip k costliest candies
        }

        // Calculate the maximum cost
        // Strategy: Always buy the costliest available candy, and skip k cheapest ones
        i = 0, j = arr.size() - 1;
        while (i <= j) {
            maxCost += arr[j];  // buy the costliest candy
            j--;                // move to next costliest
            i += k;             // skip k cheapest candies
        }

        res[0] = minCost;
        res[1] = maxCost;
        return res;  // return {minimum cost, maximum cost}
    }
};
