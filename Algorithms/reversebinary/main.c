/**********************************************
* Author: Gerald Selvino
* Description: Displays the reversed binary 
*              decimal equivalent of a number
* Language: C
***********************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int inputNumber;
    unsigned int convertedNumber=0;

    printf("Please enter a whole(1<=N<=1000000000) number: ");
    scanf("%u", &inputNumber);
    if(inputNumber<1 || inputNumber>1000000000)
    {
        printf("Invalid input!\n");
        exit(0);
    }
    else
    {
        do
        {
            convertedNumber = inputNumber%2 + (convertedNumber*2);
        }while((inputNumber = inputNumber/2)!=0);

        printf("The Reversed binary Decimal equivalent is: %d\n", convertedNumber);
    }

    return 0;
}
