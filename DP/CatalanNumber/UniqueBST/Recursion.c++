class Solution {
public:
    int numTrees(int n) {
        // if number of nodes is less than 2, the number of unique BSTs is 1
        if(n <= 1) return 1;

        // store ans by summation after solving for each node from 1 to n
        int ans = 0;

        // represents nodes from 1 to n
        for(int i = 1; i <= n; i++)

            // numtrees(i - 1) is called to emulate everything at the left side of current node
            // for example- if 2 is current node, 1 is in the left and 3 is on the right 
            // if current element is i, there are i - 1 nodes at the left side of the tree
            // if current element is i, the window becomes i + 1 to n, which is n - i nodes
            ans += numtrees(i - 1) * numtrees(n - i);
            
        // return the answer obtained for current recursion stack
        return ans;
    }
};
