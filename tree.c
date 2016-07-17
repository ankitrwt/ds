#include<stdio.h>
#include<stdlib.h>


struct data{
	int val;
	struct data *left;
	struct data *right;
};


typedef struct data node;

void create(node *,int);
void pre_order(node *);
void in_order(node *);
void post_order(node *);

int main()
{
node *start;
int x,mode;
	start = (node *)malloc(sizeof(node));
	printf("Enter the data at root node: ");
	scanf("%d",&start->val);
	start->left = NULL;
	start->right= NULL;
while(1){

	printf("\n\nENTER CHOICE\n");
	printf("1. Create tree\n");
	printf("2. pre order\n");
	printf("3. in order\n");
	printf("4. post order\n");
	printf("5. exit\n");

	scanf("%d",&mode);

	switch(mode){
		case 1:
			printf("enter the data: ");
			while((scanf("%d",&x)) != -1){
				create(start,x);
				printf("enter the data: ");
			}
		break;
		case 2:
			pre_order(start);
		break;
		case 3:
			in_order(start);
		break;
		case 4:
			post_order(start);
		break;
		case 5:
			exit(EXIT_SUCCESS);
		break;
		default:
			printf("Read Choice Carefully\n");
	}

}

return 0;
}

//CREATE TREE------------------------------------------------------------------------
void create(node *record, int x){

	if(record != NULL){
		if(x > record->val){
			if(record->right == NULL){
				record->right = (node *)malloc(sizeof(node));
				record = record->right;
				record -> val = x;
				record -> right = NULL;
				record -> left  = NULL;
			}
			else{
				create(record->right,x);
			}
		}
		else if(x < record->val){
			if(record->left == NULL){
				record->left = (node *)malloc(sizeof(node));
				record = record->left;
				record -> val = x;
				record -> right = NULL;
				record -> left  = NULL;
			}
			else{
				create(record->left,x);
			}
		}
		else{
			printf("DATA DUPLICACY NOT ALLOWED\n");
		}
	
	}
}

//PRE ORDER--------------------------------------------------------------------------
void pre_order(node * record){
	if(record != NULL){
		printf("data = %d\n",record->val);
		pre_order(record->left);
		pre_order(record->right);
	}
}
	
//IN ORDER---------------------------------------------------------------------------
void in_order(node * record){
	if(record != NULL){
		in_order(record->left);
		printf("data = %d\n",record->val);
		in_order(record->right);
	}
}
//POST ORDER-------------------------------------------------------------------------
void post_order(node * record){
	if(record != NULL){
		post_order(record->left);
		post_order(record->right);
		printf("data = %d\n",record->val);
	}
}
//-----------------------------------------------------------------------------------
