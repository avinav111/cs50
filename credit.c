#include <cs50.h>
#include <stdio.h>
int length(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number:\n");
    }while(number<0);

    printf("%i\n",length(number));

}
int length(long number)
{
    int count = 0;
    for(int i=number; i != 0; i/=10)
    {
        count++;
    }
    return count;
}
bool checksum(long number)
{
    for(int x=0; number!=0; x++; number/=10)
    {
        if(x%2==0)
        {
            
        }
        else(x%2==1)
        {
            
        }
    }
}
