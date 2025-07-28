class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        // We only need two rows at a time: current and next
        vector<int> next(n2 + 1, 0), curr(n2 + 1, 0);

        // Base case: when word1 is empty, insert all remaining word2 chars
        for(int j = 0; j <= n2; j++) {
            next[j] = n2 - j;
        }

        // Fill dp from bottom to top, right to left
        for(int i = n1 - 1; i >= 0; i--) {
            // If word2 is empty, delete all remaining word1 chars
            curr[n2] = n1 - i;

            for(int j = n2 - 1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    curr[j] = next[j + 1]; // characters match, move diagonally
                } else {
                    int insertOp = 1 + curr[j + 1];    // insert char into word1
                    int deleteOp = 1 + next[j];        // delete char from word1
                    int replaceOp = 1 + next[j + 1];   // replace char in word1
                    curr[j] = min({insertOp, deleteOp, replaceOp});
                }
            }
            next = curr; // move curr row to next
        }

        return next[0]; // final result
    }
};
