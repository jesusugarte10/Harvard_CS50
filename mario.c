//Code to simulate mario Bro Building
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while((height<1)||(height>8));
    
    int space=height-1;
   
   //Creating space
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<space;j++)
       {
            printf(" "); 
       }
       
       //Adding # value given height - space is the ammount to create pyramid
        for (int j=0;j<height-space;j++)
       {
            printf("#");
       }
       
       printf("  ");
      
      //Adding the # for the secodn time
      for (int j=0;j<height-space;j++)
       {
          printf("#");
       }  
       printf("\n");
       
       space=space-1;
   }
}