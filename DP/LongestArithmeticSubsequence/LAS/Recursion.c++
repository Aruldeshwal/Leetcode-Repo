class Solution {
public:
    
    int solve(vector<int> &arr, int index, int difference){
       // if index reaches negative, it means there's no element left, so return 0 
       if(index < 0) return 0;
        
        // store the ans of the entire looping for this index
        int ans = 0;
        
        // We start backward traversal
        // The aim is to discover a suitable previous term for our current index.
        for(int i = index - 1; i >= 0; i--){
            // if it matches the difference, it is part of the AP
            if(arr[index] - arr[i] == difference)
                
                // we find the max of the ans we have obtained so far 
                // and recursion for this previous index
                // we add 1 as curr index (i) contributes 1 element to the AP
                ans = max(ans, 1 + solve(arr, i, difference));
        }
        // return the maximum length of an AP that could be formed
        return ans;
    }

    int lengthOfLongestAP(vector<int>& arr) {
        
        int n = arr.size();
        
        // if array only contains less than 3 elements then all elements are part of the AP
        if(n <= 2) return n;
        
        // store the maximum value obtained after all the passes inside ans
        int ans = 0;
        
        // create a double-nested loop
        for(int i = 0; i < n; i++){
            // The inner loop selects the second potential term, ensuring it comes after the first.
            for(int j = i + 1; j < n; j++){
                // With two terms in hand (arr[i] and arr[j]), we can now calculate their difference
                // This difference will be the characteristic of the AP we seek.
                // We then call our solve function, starting from i
                // and seeking to extend the AP with the calculated difference.
                // We add 2 to the result of 'solve' because 'arr[i]' and 'arr[j]'
                // themselves constitute two terms of the AP.
                // The 'ans' is then updated with the maximum length found.
                ans = max(ans, 2 + solve(arr, i, arr[j] - arr[i]));
            }
        }
        // return the max length of AP that can be formed
        return ans;
    }
};
