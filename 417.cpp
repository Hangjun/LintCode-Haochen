/*
417. Valid Number

Validate if a given string is numeric.
Have you met this question in a real interview?
Example
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
*/

class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        if (s.empty()) return false;
        int i = 0;
        while(isspace(s[i])) {
            i++;
        }
            
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
            
        bool eAppear = false;
        bool dotAppear = false;
        bool firstPart = false;
        bool secondPart = false;
        bool spaceAppear = false;

        while(s[i] != '\0') {
            if (s[i] == '.') {
                if (dotAppear || eAppear || spaceAppear) {
                    return false;
                } else {
                    dotAppear = true;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (eAppear || !firstPart || spaceAppear) {
                    return false;
                } else {
                    eAppear = true;
                }
            } else if (isdigit(s[i])) {
                if (spaceAppear) {
                    return false;
                }
   
                if (!eAppear) {
                    firstPart = true;
                } else {
                    secondPart = true;
                }
            } else if (s[i] == '+' || s[i] == '-') {
                if (spaceAppear) {
                    return false;
                }

                if (!eAppear || !(s[i - 1] == 'e' || s[i - 1] == 'E')) {
                    return false;
                }
            } else if (isspace(s[i])) {
                spaceAppear = true;
            } else {
                return false;
            }
            i++;            
        }
        
        if (!firstPart) {
            return false;
        } else if (eAppear && !secondPart) {
            return false;
        } else {
            return true;
        }
    }
};
