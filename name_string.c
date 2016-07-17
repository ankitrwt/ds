#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZ 6

int enter_list(char *);
//int search(char *);
//int remove_name(char *);
//int replace(char *);
//int swap(char *);
//int arrange(char *);
int display(char *);



int main()
{
char i,j,flag,mode,name[MAXSIZ][20],temp_name[20];

while(1){
	printf("\n\nENTER YOUR CHOICE\n");
	printf("1. Enter List\n");
	printf("2. Search your Name\n");
	printf("3. Remove Name\n");
	printf("4. Replace Name\n");
	printf("5. Arrange Alphabetically\n");
	printf("6. Swap Name\n");
	printf("7. Display List\n");

	printf("\nEnter: ");
	scanf("%d",&mode);

	switch(mode){
	case 1:
		enter_list((char *)name);
	break;
	case 2:
		printf("Enter Your Name: ");
		scanf(" %[^\n]s",temp_name);
		for(i = 0;i < MAXSIZ;i++){
			if(strcmp(name[i],temp_name) == 0){
				printf("You are in list\n");
				break;
			}
			if(i == 5)
				printf("Sorry your bad luck\n");
		}
	break;
	case 3:
		printf("Enter Name: ");
		scanf(" %[^\n]s",temp_name);
		for(i = 0;i < MAXSIZ;i++){
			if(strcmp(name[i],temp_name) == 0){
				flag = 1;
			}
			if(flag == 1){
				strcpy(name[i],name[i+1]);
			}
		}
		memset(name[i - 1],'\0',20);
		printf("Name Removed\n");
	break;
	case 4:
		printf("Enter Name to be Replaced: ");
		scanf(" %[^\n]s",temp_name);
		for(i = 0;i<MAXSIZ;i++){
			if(strcmp(name[i],temp_name) == 0){
				printf("Enter Name: ");
				scanf(" %[^\n]s",name[i]);
				printf("Name Replaced\n");
				break;
			}
			if(i == 5)
				printf("Name Entered Not present in List\n");
		}
	break;
	case 5:
		for(i = 0;i < MAXSIZ; i++)
		    for(j = 0;j < MAXSIZ; j++){
			if(strcmp(name[i],name[j]) < 0)
			{
				strcpy(temp_name,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],temp_name);
			}
		    }
		 printf("List Arranged\n");
	break;
	case 6:
		flag = 0;
		printf("Enter Names to swap\n");
		printf("Enter first  Name: ");
		scanf(" %[^\n]s",temp_name);
		for(i = 1;i <= MAXSIZ; i++){
			if((strcmp(name[i - 1],temp_name) == 0) && (flag == 0)){
				printf("Enter Second Name: ");
				scanf(" %[^\n]s",name[i - 1]);
				flag = i;
				i = 0;
			}
			if((strcmp(name[i - 1],name[flag - 1]) == 0) && (i != flag )){
				strcpy(name[i - 1],temp_name);
				printf("Names Swapped\n");
			}
			if(i == 5){
				printf("Name Entered Not present in List\n");
				break;
			}
		}
	break;
	case 7:
		display((char *)name);
	break;
	default:
		printf("INVALID CHOICE\n");
	break;
	}

}

return 0;
}
//Enter List---------------------------------------------------------------
int enter_list(char *list)
{
int i;

for(i = 0; i < MAXSIZ; i++){
	printf("\nEnter %d Name: ",(i+1));
	scanf(" %[^\n]s",(list + (i * 20)));
}

return 0;
}

//Display List-------------------------------------------------------------
int display(char *list)
{
int i;
printf("\nName List: ");
for(i = 0; i < MAXSIZ; i++){
	printf("\n%d. %s",(i+1),(list + (i * 20)));
}

return 0;
}
//-------------------------------------------------------------------------
