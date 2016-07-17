#include<stdio.h>
#include<stdlib.h>

#define MAXSIZ 3

int create(int*);
int display(int*);
int replace(int*,int,int);
int mul(int*,int*);
int add(int*,int*);
int transpose(int*);

int main()
{
int i,j,mode,m1[MAXSIZ][MAXSIZ],m2[MAXSIZ][MAXSIZ],m3[MAXSIZ][MAXSIZ],*temp_m;

int (*tem)[3];

while(1){
	printf("\nENTER CHOICE\n");
	printf("1. Create Matrix\n");
	printf("2. Display Matrix\n");
	printf("3. Replace Element\n");
	printf("4. Multiplication\n");
	printf("5. Addition\n");
	printf("6. Transpose\n");

	printf("\nEnter: ");
	scanf("%d",&mode);

	if((mode != 4) || (mode != 5) || (mode != 6)){
		printf("Enter Matrix\n1. Matrix1\n2. Matrix2\nEnter: ");
		scanf("%d",&i);
		temp_m =(int *) ((i==1)?m1:m2);
		printf("\n");
	}

	switch(mode){
	case 1:
		if(create(temp_m) == -1){
			printf("ERROR: Matrix Creation fails\n");
			break;
		}		
	break;
	case 2:
		if(dispaly(temp_m) == -1){
			printf("ERROR: Can't Display Matrix\n");
			break;
		}
	break;
	case 3:
		printf("Enter Row ,Col & Element: \n");
		printf("Row: ");
		scanf("%d",&i);
		printf("Col: ");
		scanf("%d",&j);
		if(((i > MAXSIZ) ||(i == 0)) || ((j > MAXSIZ) || (j == 0))){
			printf("ERROR: INVALID LOCATION\n");
			break;
		}
		printf("Element: ");
		scanf("%d",((temp_m+((i-1)*3))+j));
	break;
	default:
		printf("INVALID CHOICE\nTRY AGAIN\n");
	break;
	}

}
return 0;
}

//Create Matrix--------------------------------------------------------------------
int create(int *m)
{
int i,j;

for(i = 0;i< MAXSIZ;i++){
	m += i*3;
	for(j = 0;j< MAXSIZ;j++){
		printf("Row %d Col %d: ",(i+1),(j+1));
		scanf("%d",m+j);
	}
}

return 0;
}
//Display Matrix-------------------------------------------------------------------
int dispaly(int *m)
{
int i,j;
printf("Matrix: \n\n");
for(i = 0;i< MAXSIZ;i++){
	m += i*3;
	for(j = 0;j<MAXSIZ;j++){
		printf("\t%d",*(m+j));
	}
	printf("\n");
}

return 0;
}

//---------------------------------------------------------------------------------







