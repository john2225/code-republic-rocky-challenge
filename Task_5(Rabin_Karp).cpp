#include <iostream>

void hashFunction(char* pat, char* txt)
{
    int txtSize = strlen(txt);
    int patSize = strlen(pat);
    const int primeModulo = 101;
    const int numOfSymbols = 256;
    int txtHashValue = 0;
    int patHashValue = 0;
    int pow = 1;
    /* pow (256, patern size - 1) % 101 */
    for(int i = 0; i < patSize - 1; ++i)
    {
        pow = (pow * numOfSymbols) % primeModulo;
    }
    
    /* Calculate the hash value of pattern */
    for(int i = 0; i < patSize; ++i)
    {
        patHashValue = ((numOfSymbols * patHashValue) + pat[i]) % primeModulo;
        txtHashValue = ((numOfSymbols * txtHashValue) + txt[i]) % primeModulo;
    }
    
    for(int i = 0; i <= txtSize - patSize; ++i)
    {
        int j;
        if(patHashValue == txtHashValue)
        {

            for(j = 0; j < patSize; ++j)
            {
                if(txt[i + j] != pat[j])
                {
                    break;
                }
            }
                if(j == patSize)
                {
                    std::cout << "Pattern is: " << i << std::endl;
                }
            }
                if(i < (txtSize - patSize))
                {
                    txtHashValue = (numOfSymbols * (txtHashValue - txt[i] * pow) + txt[i + patSize]) % primeModulo;
                
                    /* if text hash value < 0*/
                    if(txtHashValue < 0)
                    {
                        txtHashValue += primeModulo;
                    }
                    
                }
    }
}
        
int main()
{
    char txt[] = "the best int the world is code republic";
    char pattern[] = "code republic";
    hashFunction(pattern, txt);

}
