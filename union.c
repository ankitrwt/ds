#include<stdio.h>


union data{
	int num;
	char ch;
	char str[4];
}node;

int main(){

node.num = 1234;

printf("%d",node.str[3]);
printf("%d",node.str[4]);
printf("%d",node.str[1]);
printf("%d\n",node.str[0]);

return 0;
}
