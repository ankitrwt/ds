#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNAME 6

int main()
{
int i,len; 
char *name[MAXNAME]; // ARRAY OF POINTER TO STRING
char temp_str[20];

printf("Enter List: \n");
for(i = 0;i < MAXNAME; i++){
	printf("Enter %d Name: ",(i+1));
	scanf(" %[^\n]s",temp_str);//&name[i]);
/	name[i] = (char *)malloc(strlen(temp_str) + 1);
//	strcpy(name[i],temp_str);
}

printf("NAME LIST: \n");
for(i=0;i<MAXNAME;i++){
	printf("%d. %s\n",(i+1),name[i]);
}

return 0;
}
