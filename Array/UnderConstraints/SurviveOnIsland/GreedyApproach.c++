class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // Edge case: check if it's possible to survive a week
        // In any 7 days, only 6 buying days exist (1 Sunday)
        // If weekly food need > weekly buying capacity, survival is impossible
        if ((S > 6) && (M * 7 > N * 6)) return -1;

        // Count how many Sundays in total S days (no buying on Sundays)
        int sunday = S / 7;

        // Buying is only allowed on non-Sundays
        int buyingDays = S - sunday;

        // Total food required to survive all S days
        int totalFood = S * M;

        int ans = 0;

        // Calculate minimum number of days needed to buy all required food
        if (totalFood % N == 0) {
            ans = totalFood / N;
        } else {
            ans = (totalFood / N) + 1;  // Use ceil logic for partial day
        }

        // Check if it's possible to buy that much food in available days
        if (ans <= buyingDays)
            return ans;  // Survival possible, return days needed to buy food
        else
            return -1;   // Not enough buying days, survival impossible
    }
};
