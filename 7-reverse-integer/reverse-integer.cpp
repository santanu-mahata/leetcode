class Solution {
public:
    int reverse(int x) {
        int revnumber = 0 ;
        while ( x != 0 ){
            int lastdigit = x % 10 ; 
            x = x / 10 ; 
             if (revnumber > INT_MAX / 10 || 
               (revnumber == INT_MAX / 10 && lastdigit > 7))
                return 0;

            if (revnumber < INT_MIN / 10 || 
               (revnumber == INT_MIN / 10 && lastdigit < -8))
                return 0;
            revnumber = (revnumber * 10 )+ lastdigit ; 
        }
    return revnumber ; 
    }
};