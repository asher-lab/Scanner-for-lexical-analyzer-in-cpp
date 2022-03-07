#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Is Arithmetic Operator: +, - *, /, %, ++, -- 
bool isValidOperator(char x, char y)
{
	if ((x == '+') && (y != '=') ||
		(x == '-') && (y != '=') ||
		(x == '*') && (y != '=') && (y != '/') ||
		(x == '/') && (y != '=') && (y != '*') ||
		(x == '%') && (y != '=') ||
		(x == '+') && (y != '=') ||
		(x == '-') && (y != '=') ||
		(x == '+' && y == '+')   ||
		(x == '-' && y == '-')
)	// End of Arithmetic Operator
		return (true);
	return (false);	// if None Operator Arithmetic
}


// Is Assignment Operator: =,  +=, -=, *=, /=, %=
bool isValidAssignmentOperator(char x, char y)
{
	if ((x == '=' && y != '=') ||
		(x == '+' && y == '=') ||
		(x == '-' && y == '=') ||
		(x == '*' && y == '=') ||
		(x == '/' && y == '=') ||
		(x == '%' && y == '=')
)	// End of Assignment Operator
		return (true);
	return (false);	// if None Operator Assignment
}

// Is Relational Operator: ==, >, < , >=,<=, !=
bool isValidRelationalOperator(char x, char y)
{
	if ((x == '=' && y == '=') ||
		(x == '>' && y == '=') ||
		(x == '<' && y == '=') ||
		(x == '>') ||
		(x == '<') ||
		(x == '!' && y == '=')
)	// End of Relational Operator 
		return (true);
	return (false);	// if None Operator Relational
}

// Is Logical Operator: !=, &&, ||
bool isValidLogicalOperator(char x, char y)
{

	if ((x == '!' && y == '=') ||
		(x == '&' && y == '&') ||
		(x == '|' && y == '|')
)	// End of Logical Operator    
		return (true);
	return (false);	// if None Operator Logical
}

// isValidInteger
bool isValidInteger(char *str)
{
	int i, len = strlen(str);
	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' &&
			str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
			return (false);
	}

	return (true);
}

// isRealNumber
bool isRealNumber(char *str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;
	if (len == 0)
		return (false);
	for (i = 0; i < len; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' &&
			str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}

	return (hasDecimal);
}


char LEXICALANALYZER_DFA(char *str){
	int checkState = 1;
	int state = 0;
	int right = 0;
	int left = 0;
	bool statesRead = true;

	if (checkState == 1){
		
/*
*
BootStrapper = Assign str[0] values to case to BootStrap;
*
*/

if (isValidOperator(str[right], str[right+1])){state = 2; }
if (isValidAssignmentOperator(str[right], str[right+1])){state = 4; }	
if (isValidRelationalOperator(str[right], str[right+1])){state = 6; }	
if (isValidLogicalOperator(str[right], str[right+1])){state = 9; }	

if (str[0]=='b'){state = 12; }
if (str[0]=='c'){state = 16; }
if (str[0]=='d'){state = 20; }
if (str[0]=='e'){state = 35; }
if (str[0]=='f'){state = 39; }
if (str[0]=='h'){state = 44; }
if (str[0]=='i'){state = 48; }
if (str[0]=='l'){state = 53; }
if (str[0]=='o'){state = 56; }
if (str[0]=='p'){state = 59; }
if (str[0]=='t'){state = 62; }
if (str[0]=='u'){state = 66; }
if (str[0]=='n'){state = 79; }
if (str[0]=='v'){state = 83; }
if (str[0]=='/' || str[0] == '*'){state = 99; }
if (str[0]==';'){state = 104; }

/* --------------- Perform states checking ------------------*/
//              printf("CHECKER");
while (statesRead == true){ // {} START OF GREAT WHILE LOOP
	switch(state) {
		case 2  :
	      if (isValidOperator(str[right], str[right+1])){
		  state=state+1; 
	      break;}
		case 3  : // < ----------------------    ACCEPT END STATE
	      if (isValidOperator(str[right], str[right+1])){
		  printf("Arithmetic Operator: \t\t%c%c\n", str[right], str[right+1]);
		  statesRead = false;
	      break;}
		case 4  :
	      if (isValidAssignmentOperator(str[right], str[right+1])){
		  state=state+1; 
	      break;}
		case 5  : // < ----------------------    ACCEPT END STATE
	      if (isValidAssignmentOperator(str[right], str[right+1])){
		  printf("Assignment Operator: \t\t%c%c\n", str[right], str[right+1]);
		  statesRead = false;
	      break;}
		case 6  :
	      if (isValidRelationalOperator(str[right], str[right+1])){
		  state=state+1; 
	      break;}
		case 7  :
	      if (isValidRelationalOperator(str[right], str[right+1])){
		  state=state+1; 
	      break;}
		case 8  : // < ----------------------    ACCEPT END STATE
	      if (isValidRelationalOperator(str[right], str[right+1])){
		  printf("Relational Operator: \t\t%c%c\n", str[right], str[right+1]);
		  statesRead = false;
	      break;}
		case 9  :
	      if (isValidLogicalOperator(str[right], str[right+1])){
		  state=state+1; 
	      break;}
		case 10  :
	      if (isValidRelationalOperator(str[right], str[right+1])){
		  state=state+1; 
	      break;} 
		case 11  : // < ----------------------    ACCEPT END STATE
	      if (isValidLogicalOperator(str[right], str[right+1])){
		  printf("Logical Operator: \t\t%c%c\n", str[right], str[right+1]);
		  statesRead = false;
	      break;}
	    case 12  :
	      if (str[right] == 'b'){
		  state=state+1; right++;
	      break;} 
	    case 13  :
			if (str[right]   == 'o'){
			if (str[right+1] == 'd')	
				state=72; 
			if (str[right+1] == 'o')
				state=state+1; right++;
	      	break;} 
	    case 14  :
	      if (str[right] == 'o'){
		  state=state+1; right++;
	      break;}
	    case 15  : // < ----------------------    ACCEPT END STATE
	      if (str[right] == 'l' && str[right+1] == '\0'){
		  printf("Keyword: \t\t\t%s\n", str);
		  statesRead = false;
	      break;}
	    case 16  :
	      if (str[right] == 'c'){
		  state=state+1; right++;
	      break;} 
	    case 17  :
	      if (str[right] == 'h'){
		  state=state+1; right++;
	      break;} 
	    case 18  :
	      if (str[right] == 'a'){
		  state=state+1; right++;
	      break;} 
	    case 19  : // < ----------------------    ACCEPT END STATE -----------> bool
	      if (str[right] == 'r' && (str[right+1] == '\0' )){
		     printf("Keyword: \t\t\t%s\n", str);

		     statesRead = false;
	         break;}
	 	case 20  :
			if (str[right]   == 'd'){
			if (str[right+1] == 'o')	
				state=27;
			if (str[right+1] == 'r')
				state=32;
			if (str[right+1] != 'o' && str[right+1]!='r')
				state=state+1; right++;
	      	break;} 
		case 21  :
			if (str[right] == 'e'){
			state=state+1; right++;
	      	break;} 
		case 22  :
			if (str[right] == 'f'){
			state=state+1; right++;
	      	break;} 
		case 23  :
			if (str[right] == 'a'){
			state=state+1; right++;
	      	break;} 
		case 24  :
			if (str[right] == 'u'){
			state=state+1; right++;
	      	break;} 
		case 25  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 
		case 26  : // < ----------------------    ACCEPT END STATE -----------> default
			if (str[right] == 't' && str[right+1] == '\0' ){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 27  :
			if (str[right] == 'o'){
			state=state+1; right++;
	      	break;} 
		case 28  :
			if (str[right] == 'u'){
			state=state+1; right++;
	      	break;} 
		case 29  :
			if (str[right] == 'b'){
			state=state+1; right++;
	      	break;} 
		case 30  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 
		case 31  : // < ----------------------    ACCEPT END STATE -----------> double 
			if (str[right] == 'e' && str[right+1] == '\0' ){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 32  :
			if (str[right] == 'r'){
			state=state+1; right++;
	      	break;} 
		case 33  :
			if (str[right] == 'o'){
			state=state+1; right++;
	      	break;} 
		case 34  : // < ----------------------    ACCEPT END STATE  -----------> drop
			if (str[right] == 'p' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 35  :
			if (str[right] == 'e'){
			state=state+1; right++;
	      	break;} 
		case 36  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 
		case 37  :
			if (str[right] == 's'){
			state=state+1; right++;
	      	break;} 
		case 38  : // < ----------------------    ACCEPT END STATE
			if (str[right] == 'e' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 39  :
			if (str[right] == 'f'){
			state=state+1; right++;
	      	break;} 
		case 40  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 
		case 41  :
			if (str[right] == 'o'){
			state=state+1; right++;
	      	break;} 
		case 42  :
			if (str[right] == 'a'){
			state=state+1; right++;
	      	break;} 
		case 43  : // < ----------------------    ACCEPT END STATE
			if (str[right] == 't' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 44  :
			if (str[right] == 'h'){
			state=state+1; right++;
	      	break;} 
		case 45  :
			if (str[right] == 'i'){
			state=state+1; right++;
	      	break;} 
		case 46  :
			if (str[right] == 'g'){
			state=state+1; right++;
	      	break;} 
		case 47  : // < ----------------------    ACCEPT END STATE
			if (str[right] == 'h' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 48  :
			if (str[right] == 'i'){
			if(str[right+1] == 'n')
				state = 50;
			if(str[right+1] != 'n')
				state=state+1; right++;
	      	break;} 
		case 49  : // < ----------------------    ACCEPT END STATE
			if (str[right] == 'f' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 50  :
			if (str[right]   == 'n'){
			if (str[right+1] == 'p')	
				state=51;
			if (str[right+1] == 't')
				state=52;
			if (str[right+1] == 'v')
				state=74;
			if (str[right+1] != 'p' && str[right+1]!='t')
				state=state+1; right++;
	      	break;} 
		case 51  : // < ----------------------    ACCEPT END STATE
			if (str[right+1] == 'u') {state = 88;  right++; break;}
			else if (str[right] == 'p' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}	
		case 52  : // < ----------------------    ACCEPT END STATE
			if (str[right+1] == 'e') {state = 90;   right++; break;}
			if (str[right] == 't' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 53  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 
		case 54  :
			if (str[right] == 'o'){
			state=state+1; right++;
	      	break;} 
		case 55  : // < ----------------------    ACCEPT END STATE
			if (str[right] == 'w' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}	
		case 56  :
			if (str[right] == 'o'){
			state=state+1; right++;
	      	break;} 
		case 57  :
			if (str[right] == 'u'){
			state=state+1; right++;
	      	break;} 
		case 58  : // < ----------------------    ACCEPT END STATE
			if (str[right+1] == 'p') {state = 94;   right++; break;}
			if (str[right] == 't' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}	
		case 59  :
			if (str[right] == 'p'){
			state=state+1; right++;
	      	break;} 
		case 60  :
			if (str[right] == 'o'){
			state=state+1; right++;
	      	break;} 
		case 61  : // < ----------------------    ACCEPT END STATE
			if (str[right+1] == 'e') {state = 97;  right++; break;}
			if (str[right] == 'w' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 62  :
			if (str[right] == 't'){
			state=state+1; right++;
	      	break;} 
		case 63  :
			if (str[right] == 'e'){
			state=state+1; right++;
	      	break;} 
		case 64  :
			if (str[right] == 'r'){
			state=state+1; right++;
	      	break;} 
		case 65  : // < ----------------------    ACCEPT END STATE
			if (str[right] == 'm' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 66  :
			if (str[right] == 'u'){
			state=state+1; right++;
	      	break;} 
		case 67  :
			if (str[right] == 'n'){
			state=state+1; right++;
	      	break;} 
		case 68  :
			if (str[right] == 't'){
			state=state+1; right++;
	      	break;} 
		case 69  :
			if (str[right] == 'i'){
			state=state+1; right++;
	      	break;} 
		case 70  : // < ----------------------    ACCEPT END STATE	   
			if (str[right] == 'l' && str[right+1] == '\0'){
			  printf("Keyword: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}
		case 71  : // < --------- empty
		
		case 72  :
			if (str[right] == 'd'){
			state=state+1; right++;
	      	break;} 		
		case 73  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 'y' && str[right+1] == '\0'){
			  printf("Reserve Words: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}		
		case 74  :
			if (str[right] == 'V'){
			state=state+1; right++;
	      	break;} 		
		case 75  :
			if (str[right] == 'a'){
			state=state+1; right++;
	      	break;} 		
		case 76  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 		
		case 77  :
			if (str[right] == 'i'){
			state=state+1; right++;
	      	break;} 		
		case 78  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 'd' && str[right+1] == '\0'){
			  printf("Reserve Words - Boolean: \t%s\n", str);
			  statesRead = false;
		      break;}		
		case 79  :
			if (str[right] == 'n'){
			state=state+1; right++; 
	      	break;} 		
		case 80  :
			if (str[right] == 'e'){
			state=state+1; right++;
	      	break;} 		
		case 81  :
			if (str[right] == 'x'){
			state=state+1; right++;
	      	break;} 		
		case 82  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 't' && str[right+1] == '\0'){
			  printf("Reserve Words: \t\t\t%s\n", str);
			  statesRead = false;
		      break;}				
		case 83  :
			if (str[right] == 'v'){
			state=state+1; right++;
	      	break;} 		
		case 84  :
			if (str[right] == 'a'){
			state=state+1; right++;
	      	break;} 		
		case 85  :
			if (str[right] == 'l'){
			state=state+1; right++;
	      	break;} 		
		case 86  :
			if (str[right] == 'i'){
			state=state+1; right++;
	      	break;} 		
		case 87  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 'd' && str[right+1] == '\0'){
			  printf("Reserve Words - Boolean: \t%s\n", str);
			  statesRead = false;
		      break;}		
		case 88  :
			if (str[right] == 'u'){
			state=state+1; right++;
	      	break;} 		
		case 89  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 't' && str[right+1] == '\0'){
			  printf("Noise Words:  \t\t\t%s\n", str);
			  statesRead = false;
		      break;}			
		case 90  :
			if (str[right] == 'e'){
			state=state+1; right++; 
	      	break;} 		
		case 91  :

			if (str[right] == 'g'){
			state=state+1; right++;
	      	break;} 		
		case 92  :
			if (str[right] == 'e'){
			state=state+1; right++;
	      	break;} 		
		case 93  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 'r' && str[right+1] == '\0'){
			  printf("Noise Words:  \t\t\t%s\n", str);
			  statesRead = false;
		      break;}			
		case 94  :
			if (str[right] == 'p'){
			state=state+1; right++;
	      	break;} 		
		case 95  :
			if (str[right] == 'u'){
			state=state+1; right++;
	      	break;} 		
		case 96  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 't' && str[right+1] == '\0'){
			  printf("Noise Words:  \t\t\t%s\n", str);
			  statesRead = false;
		      break;}		
		case 97  :
			if (str[right] == 'e'){ 
			state=state+1; right++;
	      	break;} 		 
		case 98  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == 'r' && str[right+1] == '\0'){
			  printf("Noise Words:  \t\t\t%s\n", str);
			  statesRead = false;
		      break;}		
		case 99  :
			if ((str[right+1] == '*' && str[right] == '/' ) || ( str[right+1] == '/' && str[right] == '*'))
			{state = 101;  right++; break;}
			if (str[right] == '/'){ 
			state=state+1; right++;
	      	break;} 			
		case 100  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == '/' && str[right+1] == '\0'){
			  printf("Single Line Comment:  \t\t%c%c\n", str[right-1], str[right]);
			  statesRead = false;
		      break;}		
		case 101  :
			state = 102;
			right;
			break;
		case 102  :
			if (str[right] == '/' || str[right] == '*'){  			
			state=state+1; 
	      	break;} 		
		case 103  : // < ----------------------    ACCEPT END STATE	  
			if (str[right-1] == '/' && str[right] == '*' && str[right+1] == '\0'){
			  printf("Block Comment:  \t\t%c%c\n", str[right-1], str[right]);
			  statesRead = false;
		      break;}
			if (str[right-1] == '*' && str[right] == '/' && str[right+1] == '\0'){
			  printf("Block Comment:  \t\t%c%c\n", str[right-1], str[right]);
			  statesRead = false;
		      break;}			  			
		case 104  : // < ----------------------    ACCEPT END STATE	  
			if (str[right] == ';' && str[right+1] == '\0'){
			  printf("Delimeter:  \t\t%c%c\n", str[right]);
			  statesRead = false;
		      break;}		
		case 105  :
		
		case 106  :
		
		case 107  :
		
		case 108  :
		
		case 109  :
		
		case 110  :
		
		case 111  :
		
		case 112  : // < ----------------------    ACCEPT END STATE	  
		 
	    default:
	    	checkState = 0;
	    	statesRead = false;
	    	break;
} // {} END OF SCANNING
} // {} END OF (IF CHECKSTATE TRUE)
	}
	
/* --------------- Perform rules checking if VALID Identifier and constants checking ------------------*/	
	if (checkState==0){
	//Identifier Checking
	char *isAlpaB = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *isAlpaS = "abcdefghijklmnopqrstuvwxyz";	
	if (str[0] == '_' || strchr(isAlpaB, str[0]) || strchr(isAlpaS, str[0]))
	printf("Valid Identifier:   \t\t%s\n", str);
	else if (isRealNumber(str)) printf("Constant - Real Number: \t%s\n", str);
	else if (isValidInteger(str)) printf("Constant - Integer Number \t%s\n", str);
	else if (str[0] != '\n')printf("Invalid Identifier:   \t\t%s\n", str);
	//Constant Checking
	}
}






int main (){
	FILE *filepointer;
	filepointer = fopen("krena.por", "r");
	char str[100];
	char str_substr[100];
	fgets(str, 100, filepointer);
	while (fgets(str, 100, filepointer)){
		strcpy(str_substr,str);
		char * _word;
		_word = strtok (str," \n");
		  while (_word != NULL)
		  {
			LEXICALANALYZER_DFA(_word);
		    _word = strtok (NULL, " ");

		  }
	}
	

}
