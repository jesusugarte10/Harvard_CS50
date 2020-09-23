//Determine credit card validity

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int lenght(long int n);
bool checksum(long int n,int s);
void result(long int n, int s);

int main(void)
{
    long int number;
    int sum;
    number = get_long("Number:");
    sum = lenght(number);

    //Checking Validity of the Card
    if(checksum(number,sum))
    {
        result(number,sum);
    }
    else
    {
        printf("INVALID\n");
    }
}


//Calculating lenght
int lenght(long int n)
{
    int sum=0;

    while(n>0)
    {
        n=n/10;
        sum++;
    }

    return sum;
}



//Luhn's Algorithm
bool checksum(long int n, int s)
{
    int totalUneven=0;
    int totalEven=0;

    for (int i=1;i<=s;i++)
    {
        //If number is even, ex: (second to last)
        if (i%2==0)
        {

            //If the product of the number is greater than 9
            if((2*((n % (long int)pow(10,i))/(long int)pow(10,i-1)))>9)
            {
                // 'X' represents the product greater than 9
                int x = 2*((n % (long int)pow(10,i))/(long int)pow(10,i-1));

                //x%10 is used to get the rightmost value of two digits
                totalEven = totalEven + (x%10) + 1 ;
                // No product can be greater than 18 so we add '1'

            }

            // If the product of the number is less than 10
            else
            {
                totalEven = totalEven + 2*((n % (long int)pow(10,i))/(long int)pow(10,i-1));
            }
        }

        //If number is Uneven start with First number right to left
        else if (i%2==1)
        {
            totalUneven = (totalUneven + ((n % (long int)pow(10,i))/(long int)pow(10,i-1)));
            // Total Even is equal to Total uneven plus the uneven number
        }
    }

    //Checking if the sum is equal to 20, the card number is valid
    if ((totalEven+totalUneven)%10==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Calculating Results
void result(long int n, int s)
{
    int firstTwoDigits =(n/(long int)pow(10,s-2));

    if ((s==15)&&(firstTwoDigits==34 ||firstTwoDigits==37))
    {
        printf("AMEX\n");
    }
    else if ((s==16)&&((firstTwoDigits>50) && (firstTwoDigits<56)))
    {
        printf("MASTERCARD\n");
    }
    else if (((s==13)||(s==16))&&((firstTwoDigits/10)==4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}