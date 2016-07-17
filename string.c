#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZ 20

int copy(char *,char *);
int concatenate(char *,char *);
int compare(char *,char *);

int main()
{
char i,mode,str1[MAXSIZ],str2[MAXSIZ],*temp_str;

while(1)
{
	printf("\nENTER CHOICE\n");
	printf("1. Enter String\n");
	printf("2. Display String\n");
	printf("3. String Length\n");
	printf("4. Copy String\n");
	printf("5. Concatenate\n");
	printf("6. Compare\n");
	
	printf("\nEnter: ");
	scanf("%d",&mode);

	if((mode == 1) || (mode == 2) || (mode == 3)){
		printf("Pick:\n1. str1\n2. str2\nEnter: ");
		scanf("%d",&i);
		temp_str = (i == 1)?str1:str2;
	}

	switch(mode){
		case 1:
			printf("Enter String: ");
			memset(temp_str,'\0',MAXSIZ);
			//fgets(temp_str,MAXSIZ,stdin);
			//gets(temp_str);
			scanf(" %[^\n]s",temp_str);
			//read(0,temp_str,MAXSIZ);
		break;
		case 2:
			printf("String: %s\n",temp_str);
		break;
		case 3:
			//i = 0;
			//while(*(temp_str++))i++;
			for(i=0;temp_str[i] != '\0';i++);
				printf("String Length: %d\n", i);
		break;
		case 4:
			copy(str1,str2);
		break;
		case 5:
			concatenate(str1,str2);
		break;
		case 6:
			printf("got: %d\n",compare(str1,str2));
		break;
		default:
			printf("INVALID CHOICE\n");
		break;	
	}
}
return 0;
}

//COPY STRING---------------------------------------------------------------------
int copy(char *des,char *source)
{
int i;
memset(des,'\0',MAXSIZ);

for(i = 0;((source[i] != '\0') && (i < MAXSIZ));i++)
	des[i] = source[i];

return 0;
}
//CONCATENATE STRING--------------------------------------------------------------
int concatenate(char *str1,char *str2)
{
int i,j;
// Result stored in first string str1
	for(i = 0; str1[i] != '\0'; i++);
	for(j = 0; str2[j] != '\0'; j++)	
		str1[i + j] = str2[j];
	str1[i + j] = '\0';
/*
// Result stored in another location starting with pointer p
int len = MAXSIZ + MAXSIZ;
char *p;
p = (char *)malloc(len);
memset(p,'\0',len);

for(i = 0; str1[i] != '\0'; i++)
	p[i] = str1[i];

for(j = 0; str2[j] != '\0'; j++)
	p[i + j] = str2[j];

printf("%s\n",p);
*/
return 0;
}
//COMPARE STRING------------------------------------------------------------------
int compare(char *str1,char *str2)
{
	while(*str1 == *str2)
	{
		if(!(*str1))
		{
			printf("strings are equal ");
			return 0;
		}
		str1++;
		str2++;
	}


printf("strings are not equal ");
return (*str1 - *str2);
/*
 * ALTERNATIVE
int i;
for(i=0;((i<MAXSIZ)&& str1[i] != '\0' && str2[i] != '\0'); i++)
{
	if(str1[i] != str2[i])
	{
		printf("strings are not equal\n");
		return (str1[i] - str2[i]);
	}
}

printf("strings are equal\n");

return 0;
*/
}
//--------------------------------------------------------------------------------
