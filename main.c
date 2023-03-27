#include <stdio.h>
#include <string.h>
#include <math.h>


int toDec(char input[])     // conversion to decimal notation
{
    int length = strlen(input);     // length of string
    int sum = 0;
    short isBinary = 1;
    for (int i = 0; i < length; i++)    // loop for each character of the array
    {
        switch (input[i])
        {
            // if the input is equal to 1, then 2 is added to the sum to the power of the remaining length of the string
            case '1':
                sum += pow(2, length - i - 1);
                break;

            case '0':
                break;

            default:
                isBinary = 0;
        }
    }

    if (isBinary) return sum;   //the function will return a value if 0 or 1 is entered
    else return -1;
}


short alreadyMet(int num, int len, int array[]) {    //a function that checks the repetition of an element
    short result = 0;
    for (int i = 0; i < len; i++)
    {
        if (num == array[i])
        {
            result = 1;
            break;
        }
    }

    return result;
}


int main()
{
    int numOfTryings;
    printf("Enter the number of your inputs \n");
    scanf("%d", &numOfTryings);

    char binaryDigits[numOfTryings][50];
    int digits[numOfTryings];
    int numOfElements = 0;
    int triesCounter = 0;

    while (triesCounter < numOfTryings)
    {
        char input[50];
        printf("Enter the binary digit: \n");
        scanf("%s", &input);
        int digit = toDec(input);
        if (digit == -1)
        {
            printf("Your input is not a binary digit! Try again: \n");
            continue;
        }

        if (!alreadyMet(digit, numOfElements, digits)) {
            int length = strlen(input);
            for (int i = 0; i <= length; i++) {
                binaryDigits[numOfElements][i] = input[i];
            }
            digits[numOfElements] = digit;
            numOfElements++;
        }

        triesCounter++;
    }

    printf("\n Printing sets...\n");
    printf("Binary \t\t Dec \n");
    for (int i = 0; i < numOfElements; i++) {
        printf("%s \t\t %d \n", binaryDigits[i], digits[i]);
    }
    return 0;
}