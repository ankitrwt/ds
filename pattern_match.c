#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int i,j,k,len; 
char str[40],pat[5];

	printf("Enter String: ");
	scanf(" %[^\n]s",str);

	printf("Enter Pattern: ");
	scanf(" %[^\n]s",pat);

len = strlen(str) - strlen(pat);

for(i = 0; i < strlen(str); i++){
	
	j = 0;
	while(str[i + j] == pat[j]){
		j++;
	}

	if(j == strlen(pat)){
		printf("Pattern found at position: %d\n",(i+1));
		return 0;
	}

}
printf("Pattern not found\n");
return 0;
}
