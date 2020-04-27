/*https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/



Given an string A. The only operation allowed is to insert characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.



Input Format

The only argument given is string A.

Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.

For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".


*/


bool isPalindrome(string s){
    int low = 0;
    int high = s.size()-1;
    while(low <= high){
        if(s[low] != s[high])
            return false;
        low++; high--;
    }
    return true;
}

int Solution::solve(string s) {
    int cnt = 0;

    while(s.size()>0){
        if(isPalindrome(s)){
            break;
        }
        else{
            cnt++;
            s.pop_back();
        }
    }
    return cnt;
}
