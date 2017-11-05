///TODO:

/* ********************INCOMPLETE*****************************************

    * get input from user char by char
    * save charcacters in buffer array
    * analyze the characters one by one as they come
    * if a TAB is found, call expand_tab method
        * replace the TAB with 8 spaces, BUT:
            * if the position as we push the spaces exceed the WRAP limit, stop and print the line and reset indexx
            * else, put the spaces and return the new position of indexx
    * if a newline is found, and the position did not exceed WRAP call print_line method
    * if a newline is found, and we exceeded the WRAP, call get_last_space method
        * find the last space before the newline, make it the new position and print the chars before it
    * otherwise, keep reading until we reach WRAP limit, when reached, print_line and startover     
*/

#include <stdio.h>

#define WRAP 50
#define TAB 8


//defining global variable
int c, indexx; //reading character, reading position
char buffer[WRAP]; // reading buffer

//defining the methods
//expand_tab: replaces a TAB with 8 spaces and returns the new position
void expand_tab(int);
//get_last_space: find the last space encountered before the newline, print chars before it and make it new position
void get_last_space(int);

//move the data after the space to the begining of the buffer
void move_remaining_data(int);

//print_line: print the chars before the given indexx
void print_line(int);

void flush_buffer();

//Main function
int main(){
    indexx = 0; // starting at position zero

    //starting the reader loop
    for(indexx; (c = getchar()) != EOF;){
        
        //saving char into buffer
        buffer[indexx] = c;

        //defining conditions
        //condition 1: if WRAP is reached
        if(++indexx >= WRAP){
            get_last_space(indexx);                        
            print_line(indexx);
            move_remaining_data(indexx);
        }
        //condition 2: if a TAB is found
        else if(c == '\t'){
            expand_tab(indexx);
        }
        //condition 3: if a newline is found and we did not exceed WRAP
        else if(c == '\n' && indexx <= WRAP){
            print_line(indexx);
            indexx = 0;
            //flush_buffer();            
        }               
    }

    return 0;
}


void expand_tab(int position){
    // if we are expected to exceed the WRAP limit as we insert the spaces, stop at the limit and print line
    int limit;
    if(position + 8 > WRAP){
        limit = (position + 8) - WRAP;
        for(int i = 0; i < limit; i++){
            buffer[indexx] = ' ';
            indexx++;            
        }            
        print_line(indexx);      
    }
    else{//else, add the spaces normally
        for(int i = 0; i < 8; ++i){
            buffer[indexx] = ' ';
            indexx++;
        }
    }
}

void get_last_space(int position){
    //loop backward in the buffer until you find a space, make this the new position        
    if(position > 0){
        while(buffer[position] != ' '){        
        --position;
        }        
    }    
    // if no spaces found
    if(position == 0){
        indexx = WRAP;
    }
    else{
        indexx = position + 1;//the slot after the space
    }    
}

void move_remaining_data(int position){
    int start_position = 0;
    //checking if the current position is not at the begining or the end of the line
    if(position > 0 || position < WRAP){
        for(int i = position; i <= WRAP; ++i ){
            buffer[start_position] = buffer[i];//copy the data after the space to the begining of the array
            ++start_position; // move to next slot
        }
        indexx = start_position;
    }
    else{//position is either at 0 or WRAP
        indexx = 0;//reset position
    }
}

void print_line(int position){
    //start from position 0 and putchar till given position
    for(int i = 0; i < position; ++i){
        putchar(buffer[i]);
    }
    if(position > 0){
        putchar('\n');
    }
    //indexx = 0;    
}




