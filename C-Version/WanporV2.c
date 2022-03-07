#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool letters(char b){
	if (b=='a'||b=='b'||b=='c'||b=='d'||b=='e'||b=='f'||b=='g'||b=='h'||b=='i'||b=='j'||b=='k'||b=='l'||b=='m'||
	    b=='n'||b=='o'||b=='p'||b=='q'||b=='r'||b=='s'||b=='t'||b=='u'||b=='v'||b=='w'||b=='x'||b=='y'||b=='z'||
	    b=='A'||b=='B'||b=='C'||b=='D'||b=='E'||b=='F'||b=='G'||b=='H'||b=='I'||b=='J'||b=='K'||b=='L'||b=='M'||
		b=='N'||b=='O'||b=='P'||b=='Q'||b=='R'||b=='S'||b=='T'||b=='U'||b=='V'||b=='W'||b=='X'||b=='Y'||b=='Z')
		return true;
	return false;
}

bool number(char b){
	if (b=='1'||b=='2'||b=='3'||b=='4'||b=='5'||b=='6'||b=='7'||b=='8'||b=='9'||b=='0')
		return true;
	return false;
}

bool specialchar(char b){
	if (b==' '||b=='!'||b=='%'||b=='^'||b=='&'||b=='*'||b=='('||b==')'||b=='-'||b=='_'||b=='='||b=='+'||b=='\''||
	    b=='<'||b=='>'||b==':'||b==';'||b=='"'||b=='`'||b=='['||b==']'||b=='{'||b=='}'||b=='/'||b=='\\'||b=='|'||b==',')
		return true;
	return false;
}

void typeprinter(int a, FILE* output){
	//	FILE * output;
	// FILE SYMBOL TABLE
	//output = fopen("Output1.txt", "a+");
	switch(a){
		
			case 1:{printf("Integer\n");
					fprintf(output, "Integer\n" );}break;
			case 2:{printf("ArithmeticOperator\n");
					fprintf(output, "Arithmetic Operator\n" );}break;
			case 3:{printf("AssignmentOperator\n");
					fprintf(output, "AssignmentOperator\n" );}break;
			case 4:{printf("RelationalOperator\n");
					fprintf(output, "RelationalOperator\n" );}break;
			case 5:{printf("LogicalOperator\n");
					fprintf(output, "LogicalOperator\n" );}break;
			case 6:{printf("Comment\n");
					fprintf(output, "Comment\n" );}break;
			case 7:{printf("RealNumber\n");
					fprintf(output, "RealNumber\n" );}break;
			case 8:{printf("String\n");
					fprintf(output, "String\n" );}break;
			case 9:{printf("Delimiter\n");
					fprintf(output, "Delimeter\n" );}break;
			case 10:{printf("Parenthesis\n");
					fprintf(output, "Parenthesis\n" );}break;
			case 11:{printf("CurlyBrackets\n");
					fprintf(output, "CurlyBrackets\n" );}break;
			case 12:{printf("SquareBrackets\n");
					fprintf(output, "SquareBrackets\n" );}break;
			case 13:{printf("Keyword\n");
					fprintf(output, "Keyword\n" );}break;
			case 14:{printf("ReservedWord\n");
					fprintf(output, "ReservedWord\n" );}break;
			case 15:{printf("Identifier\n");
					fprintf(output, "Identifier\n" );}break;
			case 16:{printf("Boolean\n");
					fprintf(output, "Boolean\n" );}break;
			case 17:{printf("NoiseWord\n");
					fprintf(output, "NoiseWord\n" );}break;
			case 18:{printf("Comma\n");
					fprintf(output, "Comma\n" );}break;
			case 19:{printf("AdditionOperator\n");
					fprintf(output, "AdditionOperator\n" );}break;
			case 20:{printf("SubtractionOperator\n");
					fprintf(output, "SubtractionOperator\n" );}break;
			case 21:{printf("MultiplicationOperator\n");
					fprintf(output, "MultiplicationOperator\n" );}break;
			case 22:{printf("DivisionOperator\n");
					fprintf(output, "DivisionOperator\n" );}break;
			case 23:{printf("ModulusOperator\n");
					fprintf(output, "ModulusOperator\n" );}break;
			case 24:{printf("IncrementOperator\n");
					fprintf(output, "IncrementOperator\n" );}break;
			case 25:{printf("DecrementOperator\n");
					fprintf(output, "DecrementOperator\n" );}break;
			case 26:{printf("IntegerDivisionOperator\n");
					fprintf(output, "IntegerDivisionOperator\n" );}break;
			case 27:{printf("ExponentOperator\n");
					fprintf(output, "ExponentOperator\n" );}break;
			case 28:{printf("AddandAssignOperator\n");
					fprintf(output, "AddandAssignOperator\n" );}break;
			case 29:{printf("SubtractandAssignOperator\n");
					fprintf(output, "SubtractandAssignOperator\n" );}break;
			case 30:{printf("MultiplyandAssignOperator\n");
					fprintf(output, "MultiplyandAssignOperator\n" );}break;
			case 31:{printf("DivideandAssignOperator\n");
					fprintf(output, "DivideandAssignOperator\n" );}break;
			case 32:{printf("ModulusandAssignOperator\n");
					fprintf(output, "ModulusandAssignOperator\n" );}break;
			case 33:{printf("EqualOperator\n");
					fprintf(output, "EqualOperator\n" );}break;
			case 34:{printf("GreaterthanOperator\n");
					fprintf(output, "GreaterthanOperator\n" );}break;
			case 35:{printf("LessthanOperator\n");
					fprintf(output, "LessthanOperator\n" );}break;
			case 36:{printf("GreaterthanorEqualtoOperator\n");
					fprintf(output, "GreaterthanorEqualtoOperator\n" );}break;
			case 37:{printf("LessthanorEqualtoOperator\n");
					fprintf(output, "LessthanorEqualtoOperator\n" );}break;
			case 38:{printf("NotEqualtoOperator\n");
					fprintf(output, "NotEqualtoOperator\n" );}break;
			case 39:{printf("NotOperator\n");
					fprintf(output, "NotOperator\n" );}break;
			case 40:{printf("AndOperator\n");
					fprintf(output, "AndOperator\n" );}break;
			case 41:{printf("OrOperator\n");
					fprintf(output, "OrOperator\n" );}break;
			default:{printf("\n");
					fprintf(output, "\n" );}break;
		}
	return;
}
// Lexical Analyzer
void detectTokens(char* str) {
	FILE * output;
	// FILE SYMBOL TABLE
	output = fopen("Output1.txt", "a");
	if (output == NULL)
	{
		printf("Failed to create file\n\n");
	}
	
	int current = 0;
	int length = strlen(str);
   	int strlength = 0; 
   	int type= 0;
   	//0 no type
   	//1 integer
   	//2 arithmetic operator
   	//3 assignment operator
   	//4 relational operator
   	//5 logical operator
   	//6 comment
   	//7 Real Number
   	//8 String
   	//9 Delimiter
   	//10 Parenthesis
   	//11 Curly Brackets
   	//12 Square Brackets
   	//13 Keyword
   	//14 Reserved Word
   	//15 Identifier
   	//16 Boolean
   	//17 Noice Word
   	//18 Comma
   	int previous=0;
   
	lexical: // Lexical
	
	if (current == length)
		return;
	if (specialchar(str[current]) && str[current]==' ')
		current++;
	else if (specialchar(str[current]) && (str[current]=='+'||str[current]=='-'||str[current]=='*'||str[current]=='/'||str[current]=='%'||str[current]=='^'))
		goto aoperator;	
	else if (number(str[current]))
		goto integer;
	else if (specialchar(str[current])&&((str[current]=='=')||(str[current]=='!')||(str[current]=='>')||(str[current]=='<')))
		goto roperator;
	else if (specialchar(str[current])&&((str[current]=='|')||(str[current]=='&')))
		goto loperator;
	else if (specialchar(str[current])&&((str[current]=='|')||(str[current]=='&')))
		goto loperator;
	else if (specialchar(str[current])&&((str[current]=='"')||(str[current]=='\'')))
		goto string;
	else if (specialchar(str[current])&&(str[current]==';')){
		type=9;
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		current++;
		goto printer1;
	}
	else if (specialchar(str[current])&&(str[current]==',')){
		type=18;
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		current++;
		goto printer1;
	}
	else if (specialchar(str[current])&&((str[current]=='(')||(str[current]==')'))){
		type=10;
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		current++;
		goto printer1;
	}
	else if (specialchar(str[current])&&((str[current]=='{')||(str[current]=='}'))){
		type=11;
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		current++;
		goto printer1;
	}
	else if (specialchar(str[current])&&((str[current]=='[')||(str[current]==']'))){
		type=12;
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		current++;
		goto printer1;
	}
	else if (letters(str[current]))
		goto bus;
	else if (str[current]=='\n')
		current++;
	else {
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		printf("\t\t\t\t\t\tOwO What's This? This character is not supported.\n");
		fprintf(output, "\t\t\t\t\t\tOwO What's This? This character is not supported.\n" );
		current++;
	}
	goto lexical;
	
	integer: //Integer
		if (current == length){
			previous=0;
			goto printer3;
		}
		else if (specialchar(str[current]) && str[current]!='.'){
			previous=0;
			goto printer1;
		}	
		else if (str[current]=='.'&&previous==0){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous=1;
			type=7;
		}
		else if (number(str[current])&&previous==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (number(str[current])){
			type=1;
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			previous=0;
			current++;
			goto printer2;
		}
	goto integer;
	
	aoperator: // Arithmetic Operator
		if (current == length)
			goto printer3;
		else if ((specialchar(str[current]) && (str[current] !='+') && (str[current] != '-') && (str[current] != '*') && (str[current] != '/') && (str[current] != '=') && (str[current] != '%') && (str[current] != '^')) || letters(str[current])||number(str[current])){
			previous=0;
			strlength=0;
			goto printer1;
		}
		else if (specialchar(str[current]) && strlength==0){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			strlength++;
			if (str[current]=='+'){
				previous=1;
				type=19; //previous is equals to +
			}
			else if (str[current]=='-'){
				previous=2;
				type=20;
			} //previous is equals to -
			else if (str[current]=='/'){
				type=22;
				previous=3;
			}
			else if (str[current]=='*'){
				type=21;
			}
			else if (str[current]=='%'){
				type=23;
			}
			else if (str[current]=='^'){
				type=27;
			}
			current++;
		}
		else if (str[current]=='='){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (type==19)
				type=28;
			else if (type==20)
				type=29;
			else if (type==21)
				type=30;
			else if (type==22)
				type=31;
			else if (type==23)
				type=32;
			else
			type=3;
			current++;
			strlength=0;
			previous = 0;
			goto printer1;
		}
		else if ((str[current]=='+' && previous==1) || (str[current]=='-'&&previous==2)|| (str[current]=='/'&& previous==3)){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (str[current]=='+')
				type=24;
			else if (str[current]=='-')
				type=25;
			else if (str[current]=='/')
				type=26;
			current++;
			previous = 0;
			strlength=0;
			goto printer1;
		}	
		else if (str[current]=='*' && previous==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous = 0;
			strlength=0;
			type=6;
			goto comment;
		}
		else if (strlength!=0){
				type=2;
				printf("%c",str[current]);
				fprintf(output, "%c",str[current]);
				current++;
				previous=0;
				strlength=0;
				goto printer2;
			}	
	goto aoperator;
	
	roperator: // Relational Operator
		if (current == length)
			goto printer3;
		else if ((specialchar(str[current]) && (str[current] !='!') && (str[current] != '=') && (str[current] != '>') && (str[current] != '<')) || letters(str[current])||number(str[current])){
			strlength=0;
			goto printer1;
		}
		else if ((str[current]=='=')&&strlength==0){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			type=3;
			current++;
			strlength++;
		}
		else if ((((str[current])=='>')||(str[current]=='<'))&&strlength==0){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (str[current]=='>')
				type=34;
			else
				type=35;
			current++;
			strlength++;
		}
		else if ((str[current]=='!')&&strlength==0){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			type=39;
			strlength++;
		}
		else if (((str[current])=='=')&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (type==3)
				type=33;
			else if (type==34)
				type=36;
			else if (type==35)
				type=37;
			else if(type==39)
				type=38;
			current++;
			strlength=0;
			goto printer1;
		}
		else{
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			strlength=0;
			goto printer2;
		}
	goto roperator;
	
	loperator:
		type=5;
		if (current == length)
			goto printer2;
		else if ((specialchar(str[current]) && (str[current] !='|') && (str[current] != '&')) || letters(str[current])||number(str[current])){
			previous=0;
			goto printer2;
		}
		else if (specialchar(str[current]) && previous == 0){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (str[current]=='|')
				previous=1; //previous is equals to |
			else if (str[current]=='&')
				previous=2; //previous is equals to &
			current++;
		}
		else if ((str[current]=='|' && previous==1) || (str[current]=='&'&&previous==2)){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (str[current]=='|')
				type=40;
			else
				type=41;
			previous=0;
			current++;
			goto printer1;
		}
		else{
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous=0;
			goto printer2;
		}
	goto loperator;	
	
	comment: //Comment
		if (current == length)
			goto printer3;
		else if  (str[current]=='*'){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous=1;
		}
		else if ((str[current]=='/')&&(previous==1)){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous=0;
			goto printer1;
		}
		else{
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous=0;
		}	
	goto comment;
	
	string:
		type=8;
		if (current == length)
			goto printer4;
		else if  (((str[current]=='\'')||(str[current]=='"'))&&(previous==0)){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (str[current]=='\'')
				previous=1;
			else
				previous=2;
			current++;
		}
		else if (((str[current]=='\'')&&(previous==1))||((str[current]=='"')&&(previous==2))){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			previous=0;
			goto printer1;
		}
		else{
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}	
	goto string;
			
	bus:
		type=13;
		printf("%c",str[current]);
		fprintf(output, "%c",str[current]);
		if (str[current]=='b'){
			current++;
			goto botype;
		}
		else if (str[current]=='c'){
			current++;
			goto ctype;
		}
		else if (str[current]=='d'){
			current++;
			goto dtype;
		}
		else if (str[current]=='e'){
			current++;
			goto etype;
		}
		else if (str[current]=='f'){
			current++;
			goto ftype;
		}
		else if (str[current]=='h'){
			current++;
			goto htype;
		}
		else if (str[current]=='i'){
			current++;
			goto itype;
		}
		else if (str[current]=='l'){
			current++;
			goto ltype;
		}
		else if (str[current]=='n'){
			current++;
			goto ntype;
		}
		else if (str[current]=='o'){
			current++;
			goto otype;
		}
		else if (str[current]=='p'){
			current++;
			goto ptype;
		}
		else if (str[current]=='t'){
			current++;
			goto ttype;
		}
		else if (str[current]=='u'){
			current++;
			goto utype;
		}
		else if (str[current]=='v'){
			current++;
			goto vtype;
		}
		else{
			current++;
			goto identifier;
		}
			
	botype:
		strlength++;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4) && str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='o'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='e'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			goto betype;
		}
		else if ((str[current]=='d'||str[current]=='o')&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			if (str[current]=='d'){
				type=14;
				previous=1;
			}
			else
				previous=2;
			current++;
		}
		else if (((str[current]=='y'&&previous==1)||(str[current]=='l'&&previous==2))&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto botype;
		
	betype:
		type=17;
		strlength++;
		if (current == length && strlength==5)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==5) && str[current]!='_'){
			goto printer1;
		}
		else if ((str[current]=='g')&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (((str[current]=='i'))&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (((str[current]=='n'))&&strlength==4){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto betype;
	
	ctype:
		strlength++;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4) && str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='h'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='a'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='r'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto ctype;
	
	dtype:
		if(str[current]=='e'){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			goto detype;
		}
		else if(str[current]=='o'){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			goto dotype;
		}
		else if(str[current]=='r'){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			goto drtype;
		}
		else
			goto identifier;
		
		
	detype:
		strlength++;
		if (current == length && strlength==6)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==6)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='f'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='a'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='u'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='l'&&strlength==4){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='t'&&strlength==5){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto detype;
		
	dotype:
		strlength++;
		if (current == length && strlength==5)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==5)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='u'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='b'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='l'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='e'&&strlength==4){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto dotype;
	
	drtype:
		strlength++;
		if (current == length && strlength==3)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==3)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='o'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='p'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto drtype;
	
	etype:
		strlength++;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='l'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='s'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='e'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto etype;
	
	ftype:
		strlength++;
		if (current == length && strlength==5)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==5)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='l'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='o'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='a'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='t'&&strlength==4){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto ftype;
	
	htype:
		strlength++;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='i'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='g'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='h'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto htype;
	
	itype:
		if(str[current]=='f'){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			goto iftype;
		}
		else if(str[current]=='n'){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			if(str[current]=='p'){
				printf("%c",str[current]);
				fprintf(output, "%c",str[current]);
				current++;
				goto iftype;
			}
			else if (str[current]=='t'){
				printf("%c",str[current]);
				fprintf(output, "%c",str[current]);
				current++;
				goto iftype;
			}
			else if (str[current]=='v'){
				printf("%c",str[current]);
				fprintf(output, "%c",str[current]);
				current++;
				goto vtype;
			}
			else if(str[current]=='i'){
				printf("%c",str[current]);
				fprintf(output, "%c",str[current]);
				current++;
				goto ittype;
			}
		}
		else
			goto identifier;
	
	iftype:
		if(specialchar(str[current])&& str[current]!='_')
			goto printer1;
		else
			goto identifier;
	goto iftype;
	
	ittype:
		type=17;
		strlength++;
		if (current == length && strlength==2)
			goto printer1;
		else if((specialchar(str[current]) && strlength==2) && str[current]!='_')
			goto printer1;
		else if(str[current]=='t'&& strlength==1){
				printf("%c",str[current]);
				fprintf(output, "%c",str[current]);
				current++;
				goto ittype;
			}
		else
			goto identifier;
	goto ittype;
	
	intype:
		type=17;
		strlength++;
		if (current == length && strlength==3)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==3)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='i'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='t'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto intype;
	
	ltype:
		strlength++;
		if (current == length && strlength==3)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==3)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='o'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='w'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto ltype;
	
	ntype:
		type=14;
		strlength++;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='e'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='x'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='t'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto ntype;
	
	otype:
		strlength++;
		if (current == length && strlength==3)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==3)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='u'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='t'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto otype;
	
	ptype:
		strlength++;
		if (current == length && strlength==3)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==3)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='o'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='w'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto ptype;
	
	ttype:
		strlength++;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='h'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
			goto thtype;
		}
		else if (str[current]=='e'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='r'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='m'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto ttype;
		
	thtype:
		strlength++;
		type=17;
		if (current == length && strlength==4)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==4)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='e'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='n'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto thtype;
	
	utype:
		strlength++;
		if (current == length && strlength==5)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==5)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='n'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='t'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='i'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='l'&&strlength==4){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto utype;
	
	vtype:
		type=16;
		strlength++;
		if (current == length && strlength==5)
			goto printer1;
		else if ((specialchar(str[current]) && strlength==5)&& str[current]!='_'){
			goto printer1;
		}
		else if (str[current]=='a'&&strlength==1){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='l'&&strlength==2){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='i'&&strlength==3){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else if (str[current]=='d'&&strlength==4){
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
		else{
			strlength=0;
			goto identifier;
		}
	goto vtype;
	
	identifier:
		type=15;
		if (current == length)
			goto printer1;
		else if ((specialchar(str[current]) && str[current]!='_')){
			goto printer1;
		}
		else{
			printf("%c",str[current]);
			fprintf(output, "%c",str[current]);
			current++;
		}
	goto identifier;
	
	printer1: //Printer Valid Repeat
		printf("\t\t\t\t\t\tValid");
		fprintf(output,"\t\t\t\t\t\tValid" );
		typeprinter(type,output);
		type = 0;
		strlength=0;
		previous=0;
		goto lexical;
	
    printer2: //Printer Invalid Repeat
    	printf("\t\t\t\t\t\tInvalid");
    	fprintf(output,"\t\t\t\t\t\tInvalid" );
    	typeprinter(type,output);
    	type = 0;
    	strlength=0;
		previous=0;
    	goto lexical;
    	
    printer3: //Printer valid end
		printf("\t\t\t\t\t\tValid");
		fprintf(output,"\t\t\t\t\t\tValid" );
		typeprinter(type,output);
		return;
	
    printer4: //Printer invalid end
    	printf("\t\t\t\t\t\tInvalid");
    	fprintf(output,"\t\t\t\t\t\tInvalid" );
    	typeprinter(type,output);
    	return;
}

// Main Program
int main(){
	FILE *filepointer, *output;
	output = fopen("Output1.txt", "w");	//reset
	//fprintf(output, "Token\t\t\t\t\t\tLexeme\n\n");
	char temp[100];
	
	printf("Welcome to Wanpor");
	while (1){
		int i=0;
		printf("\n\nWhat would you like to do?\n1. Read\n2. Write\n3. Exit\n");
		printf("Number: ");
		scanf("%d",&i);
		
		// 1 Read a file
		if (i==1){
		printf("Which file for it to open?: ");
		scanf(" %[^\n]s",temp);
		
		// get last four char if == ".por"
		char temp1 [4]={temp[strlen(temp)-4],temp[strlen(temp)-3],temp[strlen(temp)-2],temp[strlen(temp)-1]};
		char temp2 [4]= ".por";
	
	    // compare if temp1 == temp2 & contains ".por"
		if (strcmp(temp1,temp2))
			printf("File is not a .por file\n");
		else{
			filepointer=fopen(temp,"r");
			if (filepointer==NULL)
				printf("Failed to open file\n");
			else{
				char str[1000];
				char *key;
				//fgets(str,1000,filepointer);
				printf("All Tokens are: \n");
				
				// Lexical Analyzer
				while (key = fgets(str,1000, filepointer)) {
            		detectTokens(str);
        		}
        		
			fclose(output);
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
				printf("\n%s failed to open\n",temp1);
			
			else{
			// if there is an input	
				if(strlen(temp)>0)
				{
					fputs(temp,filepointer);
				}
				fclose(filepointer);
				printf("Data is now written\n");
				printf("File is now closed\n");
				}
		}
		
		// 3 Exit from Program
		else if (i==3){
			return(0);
			}	
		} // end of while Block
		
		
}// end of Main Program

