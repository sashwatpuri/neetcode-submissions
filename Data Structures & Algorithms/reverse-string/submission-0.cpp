class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        //Swapping the first and the last element
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
    }
};