class Solution {
public:
  // Finds max sum of non-adjacent slices from `index` to `end`, picking `n` slices.
  int solve(vector<int> &slices, int index, int end, int n){
      // Base case: No slices to pick or end reached.
      if(n == 0 || index > end) return 0;
        
      // Option 1: Take current slice; skip next.
      int eat = slices[index] + solve(slices, index + 2, end, n - 1);
        
      // Option 2: Skip current slice.
      int notEaten = solve(slices, index + 1, end, n);
        
      // Return maximum of eating or not eating.
      return max(eat, notEaten); 
  }

  // Handles circular pizza: solves for two linear cases.
  int maxSizeSlices(vector<int>& slices) {
      int len = slices.size();
        
      // Case 1: First slice included, so last slice excluded.
      int case1 = solve(slices, 0, len - 2, len / 3);
        
      // Case 2: First slice excluded, so last slice can be included.
      int case2 = solve(slices, 1, len - 1, len / 3);
        
      // Result is the maximum of the two cases.
      return max(case1, case2);
  }
};
