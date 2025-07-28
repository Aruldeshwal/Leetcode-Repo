class Solution {
public:
    // Recursive function to calculate minimum operations from index1 and index2
    int solve(string &word1, string &word2, int index1, int index2) {
        // If word1 is exhausted, insert remaining characters of word2
        if(word1.size() == index1){
            return word2.size() - index2;
        }

        // If word2 is exhausted, delete remaining characters of word1
        if(word2.size() == index2) {
            return word1.size() - index1;
        }

        // If characters match, move both pointers ahead (no operation needed)
        if(word1[index1] == word2[index2])
            return solve(word1, word2, index1 + 1, index2 + 1);

        // Try insertion: insert word2[index2] into word1
        int insertion = 1 + solve(word1, word2, index1, index2 + 1);

        // Try deletion: delete word1[index1]
        int deletion = 1 + solve(word1, word2, index1 + 1, index2);

        // Try replacement: replace word1[index1] with word2[index2]
        int replace = 1 + solve(word1, word2, index1 + 1, index2 + 1);

        // Return the minimum of all three operations
        return min(insertion, min(deletion, replace));
    }

    // Main function to start recursion from index 0 of both words
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};
