#include <stdio.h>

#define MAXSIZE 1000

void input_reader();

char input_line[MAXSIZE];

int main(){

    //Printing the user activity request
    printf("Please start Typing: ");
    //readng user input
    input_reader();

    printf("\n\nEnd of program\n");
    return 0;
}

void input_reader(){

    int c; // input character reader
    int index; //input array index
    index = 0;
    while((c = getchar()) != EOF){        
        //if user press enter, input ends and line is analyzed for Tabs
        if(c == '\n'){                        
            printf("\nYou Typed: %s\n", input_line);
            index = 0;
            printf("\nPlease start Typing: ");
        }
        //if the user type a tab, it is replaced with 3 spaces
        else if (c == '\t'){
            input_line[index] = ' ';
            input_line[index+1] = ' ';
            input_line[index+2] = ' ';
            index = index + 3;
        }
        // as the user types normal character, is it being saved in the array
        else{
            input_line[index] = c;
            index++;
        }
    }
}