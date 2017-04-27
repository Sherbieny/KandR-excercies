/*
 * K&R Chapter 1 - Excercise 24
 * Write a program to check a C program for rudimentary syntax errors like unmatched parentheses,
 * brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This
 * program is hard if you do it in full generality.)
 *
 * TODO:
 * 	- read input char by char using getchar() assigning it into an int c
 * 	- handle cases one by one
 * 	- Case 1: Unmatched elements --> {} () [] 
 * 		- Case 1-A: opening bracket found
 * 			- increment brackets counter
 * 		- Case 1-B: closing bracket found
 * 			- increment brackets counter
 * 		- At the end, if the counter is not even, print error (unmatched paranthesis) at the end of the program
 *
 * 	- Case 2: semi-colon --> when newline is read, check if Case 1 is still active
 * 		- if active, ignore
 * 		- else,  raise semi-colon error flag and print at the end
 *
 * 	- Case 3: Quotes (single and double):
 * 		- Case 3-A: Double quotes
 * 			- count number of quotes found on each line
 * 			- when newline is read, count the number
 * 				- if even, ignore
 * 				- odd, raise quote error flag and print at the end
 * 		- Case 3-B: single quotes
 * 			- when a single quote is read, check if the next char or the one after it is another quote
 * 				- if yes, ignore
 * 				- else, raise single-quote error flag and print at the end
 *
 * 	- Case 4: escape sequence --> when a \ is found, check the double quotes counter
 * 		- if even, raise escape sequence error flag
 * 		- if odd, ignore
 *
 * 	- Case 5: Comments
 * 		- Case 5-A: single and multiline (when / is read)
 * 			- when / is read
 * 				- check the single-quote and double-quote counters
 * 					- even, check for next char
 * 						- if /, ignore
 * 						- if *, increment multi counter
 * 						- else, raise error
 * 
 * 					- odd, ignore
 * 	
 * 		- Case 5-B: multiline comment closure (when * is read)
 * 			- when * is read and next char is /
 * 				- increment multi counter
 * 			- at the end, if the counter is even, ignore - else, raise multi error flag
 *
 * 			
 * */

#include<stdio.h>

//Defining counters
int brackets, sq_brackets, paranthesis, quotes, multi;

//Defining flags
int unmatched, d_quotes, s_quotes, escape, comments;

//Defining reader
int c, c_next;


int main(){

	//start reading and handle case by case
	
	while((c = getchar()) != EOF){
	
		//case 1-A
		if(c == '{'){
		
			brackets++;

		}
		else if(c == '['){
		
			sq_brackets++;
		
		}
		else if(c == '('){
		
			paranthesis++;
		}
		//case 1-B
		else if(c == '}'){
		
			brackets--;

		}
		else if(c == ']'){
		
			sq_brackets--;		
		}
		else if(c == ')'){
		
			paranthesis--;
		}
		//case 3-A
		else if(c == '"'){
		
			quotes++;
		}
		//case 3-B
		else if(c == '\''){
			//getting next char
			c_next = getchar();
			if(c_next != '\''){
				//getting next char
				c_next = getchar();
				if(c_next != '\''){
						
					s_quotes = 1;
				}
			}
		}
		//case 3-A checker when newline is read
		else if(c == 10){
		
			if(quotes % 2 != 0){
				
				d_quotes = 1;
			}
		}
		//case 4
		else if(c == '\\'){
		
			if(quotes % 2 == 0){
			
				escape = 1;
			}
		}
		//case 5-A
		else if(c == '/'){


			if(quotes % 2 == 0){
			
				c_next = getchar();

				if(c_next == '*'){
			
					multi++;
				}
				
				else if(c_next != '/'){
					
					comments = 1;
				}
			}
		}
		//case 5-B
		else if(c == '*'){
			
			c_next = getchar();
			if(c_next == '/'){
			
				multi--;
			}		
		}				
	}

	//handling flags
	printf("\n\n-----Program Report-----\n\n");
	//unmatched brackets
	if(brackets != 0){
	
		printf("Unmatched curly braces error found!\n");
	}
	if(sq_brackets != 0){
	
		printf("Unmatched Square Brackets error found!\n");

	}
	if(paranthesis != 0){
	
		printf("Unmatched Paranthesis error found!\n");

	}
	//Single Quote
	if(s_quotes == 1){
	
		printf("Single quote error found!\n");
	}
	//Double Quote
	if(d_quotes == 1){
	
		printf("Double quotes error found!\n");
	}
	//Escape sequences
	if(escape == 1){
	
		printf("Escape Sequence error found!\n");
	}
	//Comments
	if(comments == 1){
	
		printf("Single line Comment error found!\n");
	}
	if(multi != 0){
	
		printf("Multi line comment error found!\n");
	}
	////////////////////
	
	printf("\n\nEnd of Program\n");
	return 0;

}











