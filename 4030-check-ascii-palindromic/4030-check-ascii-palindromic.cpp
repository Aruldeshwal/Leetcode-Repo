class Solution {
public:
    string binaryString(int num) {
        string binary = "00000000";
        for(int i = 7; i >= 0; i--) {
            int digit = (num % 2);
            num /= 2;
            if(digit == 1) {
                binary[i] = '1';
            }
        }
        return binary;
    }
    bool isPalindromic(string s) {
        string ans = "";
        for(char ch : s){
           int num = ch;
           string temp = binaryString(num);
           ans += temp;
        }
        int i = 0, j = ans.size() - 1;
        while(i < j) {
            if(ans[i] != ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};