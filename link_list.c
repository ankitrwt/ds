#include<stdio.h>
#include<stdlib.h>

typedef struct entry{

	char name[20];
	struct entry *link;
}node;


void append(node **);
void addbeg(node **);
void addaft(node *,int);
void display(node *);
int count(node *);
void del(node *,int);

int main(){
int i,j,mode,pos,node_no;
node *start,*record,*temp;
node_no =0;

start = NULL;

while(1){
	printf("\n\n ENTER CHOICE\n");
	printf("1. Append\n");
	printf("2. Add at Begining\n");
	printf("3. Add After\n");
	printf("4. Display\n");
	printf("5. Count\n");
	printf("6. Delete\n");

	printf("\nEnter: ");
	scanf("%d", &mode);


	switch(mode){
	case 1:
		//append(&start);	
		record = start;
		if(record == NULL){
			record = (node *)malloc(sizeof(node));
			start = record;
			record->link = NULL;
			scanf(" %[^\n]s",record->name);
			node_no++;
		}
		else{
			while(record->link != NULL){
				record = record->link;
			}
			record->link = (node *)malloc(sizeof(node));
			record = record->link;
			record->link = NULL;
			scanf(" %[^\n]s",record->name);
			node_no++;
		}
	break;
	case 2:
	//	addbeg(&start);
		record = start;
		if(record == NULL){
			record = (node *)malloc(sizeof(node));
			start = record;
			record->link = NULL;
			scanf(" %[^\n]s",record->name);
			node_no++;
		}
		else{
			start = (node *)malloc(sizeof(node));
			start->link = record;
			scanf(" %[^\n]s",start->name);
			node_no++;
		}	
	break;
	case 3:
		printf("Enter Position: ");
		scanf("%d",&pos);
		//addaft(start,pos);
		if((pos > node_no) || (pos == 0)){
			printf("Node not Exists\n");
			break;
		}
		else{
			record = start;
			while((pos-1) != 0){
				record = record -> link;
				pos--;
			}
			temp = record->link;
			record->link = (node *)malloc(sizeof(node));
			record = record->link;
			printf("Enter Name: ");
			scanf(" %[^\n]s",record->name);
			record->link = temp;
			node_no++;
		}
	break;
	case 4:
		//display(start);
		 i = 1;
		//node *record;
		record = start;
		if(record == NULL){
			printf("Nothing to Display\n");
		}
		else{	
			printf("\n%d. %s",i,record->name);
			while(record->link != NULL){
				i++;
				record = record->link;
				printf("\n%d. %s",i,record->name);
			}
		}
	break;
	case 5:
		printf("Number of Nodes: %d\n",node_no);
	break;
	case 6:
		printf("Enter Position: ");
		scanf("%d",&pos);
	//	del(start,pos);	
		if((pos > node_no) && (pos == 0)){
			printf("No Node Exists\n");
			break;
		}
		else{
			pos--;
			record = start;
			while((pos-1) != 0){
				record = record->link;
				pos--;
			}
			temp = record;
			record = record->link;
			temp->link = record->link;
			free(record);
			node_no--;
		}
	break;
	
	default:
		printf("INVALID CHOICE\n");
	break;
	}


}

return 0;
}

//APPEND---------------------------------------------------------------------------
void append(node **start){
node *record;

}
//ADD AT BEGINING------------------------------------------------------------------
void addbeg(node **start){

}
//ADD AFTER------------------------------------------------------------------------
void addaft(node *start,int pos){

}
//DISPLAY--------------------------------------------------------------------------
void display(node *start){

}
//COUNT NODES----------------------------------------------------------------------
int count(node *start){

}
//DELETE NODE----------------------------------------------------------------------
void del(node *start,int pos){

}
//---------------------------------------------------------------------------------
