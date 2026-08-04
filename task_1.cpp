#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
using namespace std;
int lineNumber = 0;
char* idArray[100];
int idCount = 0;
char* opArray[100];
int opCount = 0;
char* libArray[100];
int libCount = 0;
char* invalidVarArray[100];
int invalidVarCount = 0;
bool semicolonMissing = false;

// Returns 'true' if the character is a DELIMITER.
bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
		ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
		ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
		ch=='\t'||ch=='\n'||ch=='&'||ch=='^'||ch=='?'||
		ch=='|' ||ch==':'||ch=='.'|| ch=='"'||ch=='#'||
		ch=='!' )
		return (true);
	return (false);
}

// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '>' || ch == '<' ||
		ch == '%' || ch == '='||ch=='-='||ch=='+='||
		ch =='--'||ch =='++'||ch=='-+'||
		ch=='/*'||ch=='*='||ch=='||'||
		ch=='&&'||ch=='=='||ch=='<='||
		ch=='=>'||ch=='!'||ch=='!='||
		ch=='/=')
		return (true);
	return (false);
}

// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
		str[0] == '3' || str[0] == '4' || str[0] == '5' ||
		str[0] == '6' || str[0] == '7' || str[0] == '8' ||
		str[0] == '9' || isDelimiter(str[0]) == true)
		return (false);
	return (true);
}
//bool isPreprocessor(char* substr){
    //return true|false;
//}


// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
		!strcmp(str, "while") || !strcmp(str, "do") ||
		!strcmp(str, "break") || !strcmp(str, "for") ||
		!strcmp(str, "continue") || !strcmp(str, "int") ||
		!strcmp(str, "double") || !strcmp(str, "float") ||
		!strcmp(str, "return") || !strcmp(str, "char") ||
		!strcmp(str, "case") || !strcmp(str, "char") ||
		!strcmp(str, "sizeof") || !strcmp(str, "long") ||
		!strcmp(str, "short") || !strcmp(str, "typedef") ||
		!strcmp(str, "switch") || !strcmp(str, "unsigned") ||
		!strcmp(str, "void") || !strcmp(str, "static") ||
		!strcmp(str, "struct") || !strcmp(str, "goto") ||
		!strcmp(str, "using") || !strcmp(str, "namespace") ||
		!strcmp(str, "cout") || !strcmp(str, "cin") ||
		!strcmp(str, "endl") || !strcmp(str, "return") ||
		!strcmp(str, "main") || !strcmp(str, "include") ||
		!strcmp(str, "for") || !strcmp(str, "int") || !strcmp(str, "std"))
		return (true);
	return (false);
}

// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
	int i, len = strlen(str);

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if ((str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9') ||(str[i] == '-' && i >  0))
			return (false);
	}
	return (true);
}

// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
	int i, len = strlen(str);
	bool hasDecimal = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != '.' ||
			(str[i] == '-' && i > 0))
			return (false);
		if (str[i] == '.')
			hasDecimal = true;
	}
	return (hasDecimal);
}

// Extracts the SUBSTRING.
char* subString(char* str, int left, int right)
{
	int i;
	char* subStr = (char*)malloc(
				sizeof(char) * (right - left + 2));

	for (i = left; i <= right; i++)
		subStr[i - left] = str[i];
	subStr[right - left + 1] = '\0';
	return (subStr);
}
// Function to add unique variable to array
void addUniqueVariable(char* str) {
	// Check if already exists
	for (int i = 0; i < idCount; i++) {
		if (strcmp(idArray[i], str) == 0)
			return;
	}

	idArray[idCount] = (char*)malloc(strlen(str) + 1);
	strcpy(idArray[idCount], str);
	idCount++;
}
// Function to add unique operator to array
void addUniqueOperator(char ch) {
	char op[2] = {ch, '\0'};
	for (int i = 0; i < opCount; i++) {
		if (strcmp(opArray[i], op) == 0)
			return;
	}
	opArray[opCount] = (char*)malloc(2);
	strcpy(opArray[opCount], op);
	opCount++;
}
// Function to add unique library
void addUniqueLibrary(char* str) {
	for (int i = 0; i < libCount; i++) {
		if (strcmp(libArray[i], str) == 0)
			return;
	}
	libArray[libCount] = (char*)malloc(strlen(str) + 1);
	strcpy(libArray[libCount], str);
	libCount++;
}
void addInvalidVariable(char* str) {
	for (int i = 0; i < invalidVarCount; i++) {
		if (strcmp(invalidVarArray[i], str) == 0)
			return;
	}
	invalidVarArray[invalidVarCount] = (char*)malloc(strlen(str) + 1);
	strcpy(invalidVarArray[invalidVarCount], str);
	invalidVarCount++;
}
// Function to check valid expression
bool checkValidExpression(char* tokens[], int tokenCount) {
	if (tokenCount < 3) return false;

	// Check if token at index 1 is '='
	if (strcmp(tokens[1], "=") != 0) return false;

	// Check token at index 0 must be a valid identifier
	if (!validIdentifier(tokens[0]) || isKeyword(tokens[0])) return false;

	// Check even indexes (2,4,6,...) must be variables or integers
	// Check odd indexes (3,5,7,...) must be valid operators
	for (int i = 2; i < tokenCount; i++) {
		if (i % 2 == 0) {
			// Even index: must be variable or integer
			char* temp = tokens[i];
			// Remove semicolon if present
			int len = strlen(temp);
			if (temp[len-1] == ';') {
				temp[len-1] = '\0';
			}
			if (!validIdentifier(temp) && !isInteger(temp)) {
				return false;
			}
		} else {
			// Odd index: must be operator
			if (!isOperator(tokens[i][0])) {
				return false;
			}
		}
	}
	return true;
}

// Parsing the input STRING.
void parse(char* str)
{
	int left = 0, right = 0;
	int len = strlen(str);
	char* tokens[100];
	int tokenCount = 0;
	int start = 0;

    // Skip leading spaces and tabs
    while(start < len && (str[start] == ' ' || str[start] == '\t'))
    {
      start++;
    }

    if (len > 0 &&
      str[len-1] != ';' &&
      str[start] != '#' &&
      str[start] != '/' &&
      str[start] != '{' &&
      str[start] != '}' &&
      strncmp(str + start, "for", 3) != 0 &&
      strncmp(str + start, "if", 2) != 0 &&
      strncmp(str + start, "while", 5) != 0 &&
      strncmp(str + start, "int main()", 10) != 0 )

      {
        printf("\";\" missing in line - %d\n", lineNumber);
      }


	for(int i=0; i<len-1; i++)
    {
      if(str[i]=='/' && str[i+1]=='/')
       {
         printf("Comment in line - %d\n", lineNumber);
         return;
       }

    }



	// Check for header file
	if (len > 0 && str[0] == '#') {
		// Extract library name
		for (int i = 0; i < len; i++) {
			if (str[i] == '<') {
				int start = i + 1;
				int end = start;
				while (end < len && str[end] != '>') end++;
				if (end < len) {
					char* lib = subString(str, start, end - 1);
					addUniqueLibrary(lib);
					free(lib);
				}
				break;
			}
		}
		return;
	}
	  for(int i=0; i<len; i++)
      {
        if(str[i] == '"')
         {
           str[i] = ' ';
           i++;

           while(i < len && str[i] != '"')
           {
             str[i] = ' ';
             i++;
           }

           if(i < len)
            str[i] = ' ';
        }
      }

	// Tokenize the line
	while (right <= len && left <= right) {
		if (isDelimiter(str[right]) == false) {
			right++;
		}
		if (isDelimiter(str[right]) == true && left == right) {
			if (isOperator(str[right]) == true) {
				char op[2] = {str[right], '\0'};
				tokens[tokenCount] = (char*)malloc(2);
				strcpy(tokens[tokenCount], op);
				tokenCount++;
				addUniqueOperator(str[right]);
			}
			right++;
			left = right;
		} else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)) {
			char* subStr = subString(str, left, right - 1);

			if (isKeyword(subStr) == false) {
				if (isInteger(subStr) == true) {
					printf("'%s' is an integer\n", subStr);
					tokens[tokenCount] = (char*)malloc(strlen(subStr) + 1);
					strcpy(tokens[tokenCount], subStr);
					tokenCount++;
				} else if (isRealNumber(subStr) == true) {
					printf("'%s' is a real number\n", subStr);
					tokens[tokenCount] = (char*)malloc(strlen(subStr) + 1);
					strcpy(tokens[tokenCount], subStr);
					tokenCount++;
				} else if (validIdentifier(subStr) == true) {
					addUniqueVariable(subStr);
					tokens[tokenCount] = (char*)malloc(strlen(subStr) + 1);
					strcpy(tokens[tokenCount], subStr);
					tokenCount++;
				} else {
					addInvalidVariable(subStr);
					tokens[tokenCount] = (char*)malloc(strlen(subStr) + 1);
					strcpy(tokens[tokenCount], subStr);
					tokenCount++;
				}
			} else {
				tokens[tokenCount] = (char*)malloc(strlen(subStr) + 1);
				strcpy(tokens[tokenCount], subStr);
				tokenCount++;
			}
			free(subStr);
			left = right;
		}
	}

	// Check expression validity
	if (tokenCount >= 3) {
		bool valid = checkValidExpression(tokens, tokenCount);
		if (!valid && str[0] != '#' && str[0] != '/') {
			// Check if it's not a variable declaration line
			bool isDeclaration = false;
			for (int i = 0; i < tokenCount; i++) {
				if (isKeyword(tokens[i])) {
					isDeclaration = true;
					break;
				}
			}
			if (!isDeclaration) {
				printf("Invalid expression in line - %d\n", lineNumber);
			}
		}
	}

	// Clean up tokens
	for (int i = 0; i < tokenCount; i++) {
		free(tokens[i]);
	}
	return;
}
// DRIVER FUNCTION
int main(){
	ifstream MyReadFile("program.cpp");
	string line;

	while(getline(MyReadFile, line)) {
		lineNumber++;
		int n = line.length();
		char str[n + 1];
		strcpy(str, line.c_str());
		parse(str);
	}
	MyReadFile.close();

	// Print all libraries
	printf("\n");
	for (int i = 0; i < libCount; i++) {
		printf("Library- %d: %s\n", i+1, libArray[i]);
	}

	// Print all variables
	printf("\n");
	for (int i = 0; i < idCount; i++) {
		printf("Variable- %d: %s\n", i+1, idArray[i]);
	}
	printf("Total number of the variables: %d\n", idCount);

	// Print all operators
	printf("\n");
	for (int i = 0; i < opCount; i++) {
		printf("Operator- %d: %s\n", i+1, opArray[i]);
	}
	printf("Total number of the operators: %d\n", opCount);

	// Print invalid variables
	if (invalidVarCount > 0) {
		printf("\n");
		for (int i = 0; i < invalidVarCount; i++) {
			printf("Invalid variable - %s\n", invalidVarArray[i]);
		}
	}

	if (semicolonMissing) {
		printf("Errors!\n");
	}

	// Clean up
	for (int i = 0; i < idCount; i++) free(idArray[i]);
	for (int i = 0; i < opCount; i++) free(opArray[i]);
	for (int i = 0; i < libCount; i++) free(libArray[i]);
	for (int i = 0; i < invalidVarCount; i++) free(invalidVarArray[i]);

	return (0);
}
