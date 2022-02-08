#include<fstream>// needed for file in/out
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.hpp"
#include <iostream>

using namespace std;

char *lastFour(int s, const char *input){

	char *ret = new char[s];
	for (int i = 0; i<=s; i++)
	{
		ret[i] = input[strlen(input)-(s-i)];
	}
	return ret;
}

int main(){
        //OverWrite
        ofstream output;
        output.open("SymbolTable.txt");
	FILE *filepointer;
	char temp[10];
	printf("Which file for it to open?: ");
	scanf(" %[^\n]s",temp);
        
        
        
        char *temp1;
        temp1 = (char *)malloc(4);
        
        strcpy(temp1,lastFour(4,temp));
       
	char temp2[5]= ".por";
        
	if (strcmp(temp1,temp2)!=0){
	
		printf("\nFile is not a .por file\n");
		}
		
		else{
		filepointer=fopen(temp,"r");
		if (filepointer==NULL)
			printf("\nFailed to open file\n");
			else
			{
			char str[100];
			fgets(str,100,filepointer);
			lexicalAnalyze(temp);

              return 0;

		}
	}
}
