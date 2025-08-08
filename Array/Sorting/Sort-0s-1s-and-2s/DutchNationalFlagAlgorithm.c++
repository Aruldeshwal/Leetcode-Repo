class Solution {
public:
    void sort012(vector<int>& arr) {
        // Three pointers:
        // low  -> boundary for 0's (elements before low are all 0's)
        // mid  -> current element under examination
        // high -> boundary for 2's (elements after high are all 2's)
        int low = 0, mid = 0, high = arr.size() - 1;

        // Process elements until mid passes high
        while (mid <= high) {
            if (arr[mid] == 0) {
                // Current element is 0 → swap it to the front
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                // Current element is 1 → leave it in the middle
                mid++;
            }
            else { // arr[mid] == 2
                // Current element is 2 → swap it to the end
                swap(arr[mid], arr[high]);
                high--;
                // Note: mid is NOT incremented here because the new element
                // swapped from the end still needs to be checked
            }
        }
    }
};

/*
Logic:
- Keep 0's at the beginning, 1's in the middle, and 2's at the end.
- Only one traversal is needed (mid scans array once).
- Each swap moves an element directly into its correct region.

Time Complexity:
- O(n) → Every element is checked at most once.

Space Complexity:
- O(1) → In-place sorting using only constant extra variables.
*/
