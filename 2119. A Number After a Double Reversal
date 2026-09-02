class Solution {
    int reverse ( int n )
    {
        int rev = 0 ;
        while ( n != 0 )
        {
            rev = (rev * 10 ) + n % 10 ;
            n = n / 10;
        }
        return rev ; 
    }
    public boolean isSameAfterReversals(int num) {
        int r1  = reverse ( num );
        int r2 = reverse ( r1 );
        return num == r2;
    }
}
