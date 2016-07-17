#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZ 5

int insert(int *,int ,int);
int del(int *,int);
int reverse(int *);
int display(int *);
int search(int *,int);
int merging(int *,int *);
int sorting(int *);

int main()
{
int mode,i,temp_numb,temp_pos,arr1[MAXSIZ],arr2[MAXSIZ];
int *temp_arr;

while(1)
{
	printf("\nENTER YOUR CHOICE:\n");
	printf("1. Enter all Elements of array\n");
	printf("2. Enter single Element\n");
	printf("3. Display Array\n");
	printf("4. Replace Element\n");
	printf("5. Delete Element\n");
	printf("6. Reverse Array\n");
	printf("7. Search Element\n");
	printf("8. Sorting Array\n");
	printf("9. Merge arr1 & arr2\n");

	printf("\nEnter choice here: ");
	scanf("%d",&mode);
	
	temp_arr = NULL;
	if(mode != 9)
	{
		printf("Choose arr to you want to work on\n");
		printf("1. arr1\n2. arr2\nEnter: ");
		scanf("%d",&i);
		temp_arr = (i==1)?arr1:arr2;
	}

	switch(mode){
		case 1:
			printf("Enter array:\n");
			for(i = 0;i<MAXSIZ;i++){
				printf("Enter Element %d: ",(i+1));
				scanf("%d",&temp_numb);
				temp_arr[i] = temp_numb;
				if(i == (MAXSIZ - 1)){
					printf("\nArray MAXSIZ reached\n");
				}
			/*	if(insert(temp_arr,i,temp_numb) == -1){
					printf("ERROR: Element not Inserted\n");
				}
			*/
			}
		break;
		case 2:
			printf("Enter Element & Position:\n");
			printf("Element: ");
			scanf("%d",&temp_numb);
			printf("Position: ");
			scanf("%d",&temp_pos);
			if(insert(temp_arr,temp_pos,temp_numb) == -1){
				printf("ERROR: Element not Inserted\n");
				break;
			}
			display(temp_arr);

		break;
		case 3:
			display(temp_arr);
		break;
		case 4:
			printf("Enter Element & Position:\n");
			printf("Element: ");
			scanf("%d",&temp_numb);
			printf("Position: ");
			scanf("%d",&temp_pos);
			if(temp_pos == 0 || temp_pos > MAXSIZ){
				printf("ERROR: Invalid Position\n");
				break;
			}
			temp_arr[temp_pos-1] = temp_numb;
			display(temp_arr);
		break;
		case 5:
			printf("Enter Position:\n");
			printf("Position: ");
			scanf("%d",&temp_pos);
			if(del(temp_arr,temp_pos) == -1){
				printf("ERROR: Element not Deleted\n");
				break;
			}	
			display(temp_arr);
		break;
		case 6:
			reverse(temp_arr);
			display(temp_arr);
		break;
		case 7:
			printf("Enter Element\n");
			printf("Element: ");
			scanf("%d",&temp_numb);
			search(temp_arr,temp_numb);
		break;
		case 8:
			sorting(temp_arr);
			display(temp_arr);
		break;
		case 9:
			merging(arr1,arr2);
		break;
		default:
			printf("INVALID CHOICE\nENTER AGAIN\n");
		break;
	}
}
return 0;
}

//INSERT ELEMENT------------------------------------------------------

int insert(int *arr,int pos,int num)
{
int i;
if(pos == 0 || pos > MAXSIZ){
	printf("ERROR: Invalid Position\n");
	return -1;
}


for(i = (MAXSIZ - 1);i>(pos-1);i--)
{
	arr[i] = arr[i-1];
}
arr[i] = num;
return 0;
}

//DELETE ELEMENT------------------------------------------------------

int del(int *arr,int pos)
{
int i;
if(pos == 0 || pos > MAXSIZ){
	printf("ERROR: Invalid Position\n");
	return -1;
}
for(i=(pos-1);i<(MAXSIZ - 1);i++)
{
	arr[i] = arr[i+1];
}
arr[i] = 0;
return 0;
}

//REVERSE ARRAY-------------------------------------------------------

int reverse(int *arr)
{
int i,temp;

for(i = 0; i< MAXSIZ/2;i++)
{
	temp = arr[i];
	arr[i] = arr[(MAXSIZ - 1) -i];
	arr[(MAXSIZ - 1) - i] = temp;
}

return 0;
}

//SEARCH ELEMENT------------------------------------------------------
int search(int *arr,int num)
{
int i;

for(i = 0;i<MAXSIZ;i++)
{
	if(arr[i] == num)
	{
		printf("Element found at position %d\n",(i+1));
		return 0;
	}
}

printf("Element not present\n");
return 0;
}

//SORTING ARRAY-------------------------------------------------------

int sorting(int *arr)
{
int i,j,temp;

for(i = 1; i< MAXSIZ;i++){
	for(j = 0; j< i;j++){
		if(arr[j] > arr[i]){
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

return 0;
}

//MERGE ARRAYS--------------------------------------------------------
int merging(int *arr1, int *arr2)
{
int i,len,*p;
len = MAXSIZ + MAXSIZ ;

p = (int *)malloc(sizeof(int)*len);
printf("Array: ");
	for(i = 0;i<len;i++){
		if(i < 5)
			p[i] = arr1[i];
		else
			p[i] = arr2[i - 5];

		printf("%d ",p[i]);
	}
printf("\n");

}

//DISPLAY ARRAY-------------------------------------------------------
int display(int *arr)
{
int i;	
printf("Array:  ");
for(i = 0;i < MAXSIZ;i++){
	printf("%d ",arr[i]);
}
printf("\n");

return 0;
}

//--------------------------------------------------------------------




