//rightrot:rotate x to the right by n positions
unsigned rightrot(unsigned x,int n)
{
    int wordlength(void);
    unsigned rbits;
    if ( (n = n % wordlength()) > 0)
    {
        rbits = ~(~0 << n) & x;
        rbits = rbits << (wordlength() - n);
        x = x >> n;
        x = x | rbits;
    }
    return x;
}