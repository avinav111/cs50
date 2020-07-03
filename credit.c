#include <cs50.h>
#include <stdio.h>
int length(long number);
bool checksum(long number);
bool valid(long number);
void card(long number);
int main(void)
{
    long number;
    do
    {
        number = get_long("Number:\n");
    }while(number<0);

    if(valid(number)==true)
    {
        card(number);
    }
  //  else
 //   {
  //      printf("INVALID\n");
//    }
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
    int sum = 0;
    for(int x=0; number!=0; x++, number/=10)
    {
        if(x%2==0)
        {
           sum += number % 10;
//do the algebra now
        }
        else
        {
            int sum2 = 2*(number%10);
            sum+=sum2/10 + sum %10;
        }
    }
    /*if((sum%10)==0)
    {
       return true;
    }
    else
    {
        return false;
    }
    */
    return (sum%10)==0;
}
bool valid(long number)
{
    int length2= length(number);
    return (length2 == 13 || length2 == 15|| length2 == 16)&& (checksum(number));
    /*if((length2 == 13 || length2 == 15|| length2 == 16)&& (checksum(number)==true))
    {
         return true;
    }
    else
    {
        return false;
    }
*/
}
void card(long number)
{
    if((number< 35e13 && number >= 34e13 )|| (number<38e13 && number>=37e13))
    {
        printf("AMEX\n");
    }
    else if((number< 56e14 && number >= 51e14 ))
    {
        printf("MASTERCARD\n");
    }
    else if((number< 5*(10^12) && number >= 4*(10^12) )|| (number<5*(10^15) && number>=4*(10^15)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}