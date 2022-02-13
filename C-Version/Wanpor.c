#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
   ch == '[' || ch == ']' || ch == '{' || ch == '}')
   return (true);
   return (false);
}

bool isValidOperator(char x, char y){
   // Is Arithmetic Operator: +, - *, /, %, ++, --
   if ((x == '+' )
	   || (x == '-')
	   || (x == '*')
	   || (x == '/') 
	   || (x == '%')
	   || (x == '+')
	   || (x == '-')
	   || (x == '+' && y == '+')
	   || (x == '-' && y == '-')
	   )// End of Arithmetic Operator
	   return (true);
	return (false); // if None Operator Arithmetic
}

bool isValidAssignmentOperator(char x, char y){
   // Is Assignment Operator: =,  +=, -=, *=, /=, %=
   if ((x == '=' )
	   || (x == '+' && y == '=') 
	   || (x == '-' && y == '=') 
	   || (x == '*' && y == '=') 
	   || (x == '/' && y == '=') 
	   || (x == '%' && y == '=') 
	   )// End of Assignment Operator
	   return (true); 
	return (false); // if None Operator Assignment
}

bool isValidRelationalOperator(char x, char y){
   // Is Relational Operator: ==, >, <, >=, <=, !=
   if ((x == '=' && y == '=') 
	   || (x == '>' && y == '=') 
	   || (x == '<' && y == '=') 
	   || (x == '>' ) 
	   || (x == '<' ) 
	   || (x == '!' && y == '=') 
	   )// End of Relational Operator 
	   return (true);
	return (false); // if None Operator Relational
}

bool isValidLogicalOperator(char x, char y){
   // Is Logical Operator: ==, >, <, >=, <=, !=
   if ((x == '!' && y == '=') 
	   || (x == '&' && y == '&') 
	   || (x == '|' && y == '|') 
	   )// End of Logical Operator    
	   return (true);   
	return (false); // if None Operator Logical
}

   
// Returns 'true' if the string is a VALID IDENTIFIER.
bool isvalidIdentifier(char* str){   
   char *isAlpaB = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char *isAlpaS = "abcdefghijklmnopqrstuvwxyz";
   if (str[0] == '_' || strchr(isAlpaB, str[0]) || strchr(isAlpaS, str[0]) )
   return (true);
   return (false);
}
// isValidKeyword
bool isValidKeyword(char* str) {
   if (!strcmp(str, "bool") || !strcmp(str, "char") || !strcmp(str, "default") || !strcmp(str, "double") ||    !strcmp(str, "drop") || !strcmp(str, "else") || !strcmp(str, "float")
   || !strcmp(str, "high") || !strcmp(str, "if") || !strcmp(str, "inp") || !strcmp(str,    "int") || !strcmp(str, "low") || !strcmp(str, "out")
   || !strcmp(str, "pow") || !strcmp(str, "term") || !strcmp(str, "until") || !strcmp(str, "body") || !strcmp(str, "invalid") || !strcmp(str, "next")
   || !strcmp(str, "valid") || !strcmp(str, "ency") ||  !strcmp(str, "strike"))
   return (true);
   return (false);
}

// isValidReservedKeyword
bool isValidReservedKeyword(char* str) {
   if (!strcmp(str, "body") || !strcmp(str, "invalid") || !strcmp(str, "next") || !strcmp(str, "valid")) 
   return (true);
   return (false);
}

// isValidNoiseKeyword
bool isValidNoiseKeyword(char* str) {
   if (!strcmp(str, "input") || !strcmp(str, "integer") || !strcmp(str, "output") || !strcmp(str, "power")) 
   return (true);
   return (false);
}

// isValidInteger
bool isValidInteger(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5'
      && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
      return (false);
   }
   return (true);
}

// isRealNumber
bool isRealNumber(char* str) {
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i]       != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8'
      && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
         if (str[i] == '.')
      hasDecimal = true;
   }
   return (hasDecimal);
}

char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}


// Lexical Analyzer
void detectTokens(char* str) {
   int left = 0, right = 0;
   int length = strlen(str);
   
   while (right <= length && left <= right) {
   	
   	
	//Checking for block comments
   	if (str[right]=='/' && str[right+1]=='*'){
		
		right+=2;
		left+=2;
		
		//while right has not found END comment
		while ((str[right]!='*') && (str[right+1]!='/')){
			right++;
			}
		char* comStr = subString(str, left, right - 1);
		printf("Valid comment: %s\n", comStr);
		
		right+=2;
		left=right;
	  }	
	     	
   	  // Check if Valid Delimiter
      if (isValidDelimiter(str[right]) == false)
      right++;
      
      // Check if Valid Delimeter
      if (isValidDelimiter(str[right]) == true && left == right) {
      	
        	
/* --------------- START OF NESTED-IF FOR OPERATORS!!!!! --------------------- */	
/* --------------- START OF NESTED-IF FOR OPERATORS!!!!! --------------------- */	
/* --------------- START OF NESTED-IF FOR OPERATORS!!!!! --------------------- */	
  

     // Check if Valid Operator - ASSIGNMENT         
     if (isValidAssignmentOperator(str[right], str[right+1]) == true){
         	//if (str[right] == '=' &&  isvalidIdentifier(str[right+1]) == true)
         	if (str[right+1] == '='){
			 printf("Operator Assignment: %c%c\n", str[right], str[right+1]); 
			} else 	if (str[right+1] == '=' && str[right+2] != '=') 
							 printf("Operator Assignment:  %c\n", str[right]); 
	     	}				
				
    // Check if Valid Operator - RELATIONAL  
    else if (isValidRelationalOperator(str[right], str[right+1]) == true){
    	
    	if (str[right+1] == '='){
         printf("Valid Operator Relational: %c%c\n", str[right], str[right+1]);
		} else 
			printf("Operator Relational: %c\n", str[right]);
		right++; left = right-1;
		}

					
					
    // Check if Valid Operator - LOGICAL
    else if (isValidLogicalOperator(str[right], str[right+1]) == true){
         printf("Operator Logical: %c%c\n", str[right], str[right+1]);
		 right++; left = right-1;
		}				
					     
					     
					     
	  // Check if Valid Operator - ARITHMETIC
	else if (isValidOperator(str[right], str[right+1]) == true){ 
	 
	     if (str[right+1] == '+' || str[right+1] == '-'){
	     printf("Operator Arithmetic: %c%c\n", str[right], str[right+1]);
	     right++; left = right-1; 
		 }else{
	     printf("Operator Arithmetic: %c\n", str[right]); }
		  }

    	
/* -----------------  END OF NESTED-IF FOR OPERATORS ------------------*/
/* -----------------  END OF NESTED-IF FOR OPERATORS ------------------*/
/* -----------------  END OF NESTED-IF FOR OPERATORS ------------------*/
   	
   	
	   // Increment and Set left = right	
       right++;
       left = right;
         
      } // End if Invalid Delimeter
	  
	  
	  else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left != right)) {
         char* subStr = subString(str, left, right - 1);
         
         
         if (isValidKeyword(subStr) == true)
            printf("Keyword : %s\n", subStr);
            
         else if (isValidReservedKeyword(subStr) == true)
            printf("Reserved Keyword : %s\n", subStr);
        
		 else if (isValidNoiseKeyword(subStr) == true)
            printf("Noise Keyword : %s\n", subStr);                        
            
         else if (isValidInteger(subStr) == true)
            printf("Integer : %s\n", subStr);
            
         else if (isRealNumber(subStr) == true)
            printf("Real Number : %s\n", subStr);
            
         else if (isvalidIdentifier(subStr) == true
            && isValidDelimiter(str[right - 1]) == false){
              	if (subStr != '\n')
				           printf("Identifier : %s\n", subStr);          	
			}
			
         else if (isvalidIdentifier(subStr) == false
            && isValidDelimiter(str[right - 1]) == false ){
            	if (str[right-1] != '\n')
            	         printf("Invalid Identifier : %s\n", subStr);
			}
         
         
         
         left = right;
      }
   } // END OF WHILE LOOP
   return;
   
}




// Main Program
int main(){
	FILE *filepointer, *output;
	char temp[100];
	printf("Welcome to Wanpor\n");
	while (1){
		int i=0;
		printf("What would you like to do?\n1. Read\n2. Write\n3. Exit\n");
		printf("Number:   ");
		scanf("%d",&i);
		
		// 1 Read a file
		if (i==1){
		printf("Which file for it to open?:   ");
		scanf(" %[^\n]s",temp);
		
		// get last four char if == ".por"
		char temp1 [4]={temp[strlen(temp)-4],temp[strlen(temp)-3],temp[strlen(temp)-2],temp[strlen(temp)-1]};
		char temp2 [4]= ".por";
	
	    // compare if temp1 == temp2 & contains ".por"
		if (strcmp(temp1,temp2))
			printf("File is not a .por file\n\n");
			else{
			filepointer=fopen(temp,"r");
				if (filepointer==NULL)
				printf("Failed to open file\n\n");
				else
				{
				char str[1000];
				char *key;
				fgets(str,100,filepointer);
				printf("All Tokens are : \n\n");
				
				// Lexical Analyzer
				 while (key = fgets(str,1000, filepointer)) {
            		detectTokens(str);
        		}
        		
				output = fopen("Output1.txt","w");
				if(output==NULL){
				printf("Failed to create file\n\n");}
				else {
				fprintf(output, "Lexeme\t\t Token\n  %s\t\t\n",str);
				fclose(output);}
				return (0);
				}
			}
		}
		
		
	    // 2 Write via Terminal		
		else if (i==2){
			printf("Input items:");
			scanf(" %[^\n]s",temp);
			char temp1[100];
			printf("Which file for it to save?:");
			scanf(" %[^\n]s",temp1);
			filepointer=fopen(temp1,"w");
			
			// if NUll
			if (filepointer == NULL)
				printf("\n%s failed to open\n\n",temp1);
			
			else{
			// if there is an input	
				if(strlen(temp)>0)
				{
					fputs(temp,filepointer);
				}
				fclose(filepointer);
				printf("Data is now written\n");
				printf("File is now closed\n\n");
				}
				return 0;
		}
		
		// 3 Exit from Program
		else if (i==3){
			break;
			}	
		} // end of while Block
		
		
}// end of Main Program
