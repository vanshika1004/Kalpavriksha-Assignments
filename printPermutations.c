#include <stdio.h> 
#include <string.h> 
#include<stdlib.h>

void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void printPermutations(char *str, int index, int n) 
{ 
	if (index == n) 
		printf(" \" %s \" ", str); 
	else
	{ 
		for (int j = index; j <= n; j++) 
		{ 
			swap((str + index), (str + j)); 
			printPermutations(str, index + 1, n); 

			//backtrack 
			swap((str + index), (str + j)); 
		} 
	} 
} 

int main() 
{ 
	char* str = (char*)malloc(100 * sizeof(char));
	scanf("%99[^\n]%*c",str);
	int len = strlen(str); 
	int index = 0;
	printf("[");
        printPermutations(str, index, len-1); 
	printf("]");
	return 0; 
} 
