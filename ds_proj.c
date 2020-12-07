#include<stdio.h>
#include<stdlib.h>
/*
    reference link = https://onlinetoolz.net/bitshift
*/
/*
    number = 1234
    binary = 10011010010
    logical
        right shift ( 2 ) = 00100110100 { add zeros in front that much you want to shift 
                                          & remove the digit from last that much you shift }
        left shift ( 2 )  = 01101001000 { remove digit from first that much you want to shift
                                           & add zeros to last that much you removed from front }
    arithmatic
        right shift ( 2 ) = 11100110100 { add first digit that much time you want to shift 
                                          & that much digit remove from last }
        left shift ( 2 )  = 01101001000 [ ldentical to logical left shift ]
*/

//logical right shift
void logical_rightShift(int binary[],int sizeofbinary){
    printf("\nBy how many bits do you want to shift your binary number to the left?(logical left shift): ");
    int leftshiftdigit;
    scanf("%d",&leftshiftdigit);
    for(int i = 0;i<leftshiftdigit;i++){
        printf("%d\t",0);
    }
    for(int i=sizeofbinary-1;i>=leftshiftdigit;i--){
        printf("%d\t",binary[i]);
    }
}

//arithmatic right shift
void arithmatic_rightShift(int binary[],int sizeofbinary){
    printf("\nBy how many bits do you want to shift your binary number to the right?(arithmatic right shift): ");
    int rightshiftdigit;
    scanf("%d",&rightshiftdigit);
    for(int i=0;i<rightshiftdigit;i++){
        printf("%d\t",binary[sizeofbinary-1]);
    }
    for(int i=sizeofbinary-1;i>=rightshiftdigit;i--){
        printf("%d\t",binary[i]);
    }
}

//place zero at the end that much you want to shif and remove the same number of element from front
void logical_leftShift_and_arithmatic_leftShift(int binary[],int sizeofbinary){
    printf("\nBy how many bits do you want to shift your binary number to the right?(logical right shift): ");
    int rightshiftdigit;
    scanf("%d",&rightshiftdigit);
    for(int i=sizeofbinary - (rightshiftdigit + 1);i>=0;i--){
        printf("%d\t",binary[i]);
    }
    for(int i = 0;i<rightshiftdigit;i++){
        printf("%d\t",0);
    }
}

int main(){
    printf("\t\t*BIT SHIFTING OPERATIONS*\n\n");
    while (1)
    {
        int choice;
        int binary[15]={0};
        int sizeofbinary = 16;
        printf("\nChoose the type of input you wish to give: \n1.Integer\n2.Binary\n3.Exit\n");
	    printf("\n\nEnter your choice: ");
	    scanf("%d",&choice);
        switch (choice)
        {
        case 1: 
                printf("Enter an integer number: ");
                int number = 0;
                // int binary[10];
                // sizeofbinary = 0;
                int number_before = 0;
                scanf("%d",&number);
                number_before = number;
                //convert to binary
                for(int i=0;number>0;i++){
                    binary[i] = number%2;
                    number=number/2;
                    // sizeofbinary = sizeofbinary + 1;
                }
                //print the binary number
                if(number_before == 0){
                    printf("Your binary number is: 0 0");
                }else{
                    printf("Your binary number is: ");
                    for (int i = sizeofbinary - 1; i >= 0 ; i--)
                    {
                        printf("%d\t",binary[i]);
                    }
                    
                }
            break;
        case 2:
                printf("\nHow many bits does your binary number have?: ");
                scanf("%d",&sizeofbinary);
                printf("\nEnter the binary bits one by one starting from msb: ");
                for(int i = 0;i<sizeofbinary;i++){
                    scanf("%d",&binary[i]);
                }
                printf("\nThis is the binary number you entered: ");
                for(int i = 0;i<sizeofbinary;i++){
                    printf("%d\t",binary[i]);
                }
            break;
        case 3:
                exit(0);
        default:
                printf("\nPLEASE ENTER A VALID CHOICE");
            break;
        }

        printf("\n1.Right Shift\n2.Left Shift\n3.Exit \nSelect which shift to be performed: ");
        choice = 0;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                printf("\nWhich right shift do you wish to perform?\n1.Logical Right Shift\n2.Arithmetic Right Shift\n3.Exit");
                printf("\nEnter your choice: ");
                int rightshift;
                scanf("%d",&rightshift);
                switch (rightshift)
                {
                case 1:
                        //add logical right here
                        logical_rightShift(binary,sizeofbinary);
                    break;
                case 2:
                        //arithmatic right here
                        arithmatic_rightShift(binary,sizeofbinary);
                    break;
                case 3:
                        exit(1);
                default:
                        printf("\nPLEASE ENTER A VALID CHOICE");
                    break;
                }
        case 2:
                printf("\nWhich left shift do you wish to perform?\n1.Logical left Shift\n2.Arithmetic left Shift\n3.Exit");
                printf("\nEnter your choice: ");
                int leftShift;
                scanf("%d",&leftShift);
                switch (leftShift)
                {
                case 1:
                    //logical left shift here 
                    logical_leftShift_and_arithmatic_leftShift(binary,sizeofbinary);
                    break;
                case 2:
                    //arithmatic left shift here
                    logical_leftShift_and_arithmatic_leftShift(binary,sizeofbinary);
                    break;
                default:
                    printf("\nPLEASE ENTER A VALID CHOICE");
                    break;
                }
            break;
        
        default:
            break;
        }

    }
    return 1;
    
}