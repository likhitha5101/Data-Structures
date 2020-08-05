#include"functions.h"
int main()
{
	tree * root=NULL;
	char str[50],m1[50],m2[50];
	printf("\n\nEnter English word: ");
	scanf(" %[^\n]",str);
	while(strcmp(str,"0"))
	{
		printf("\nEnter its Tamil meaning: ");
		scanf(" %[^\n]",m1);
		printf("\nEnter its Hindi meaning: ");
		scanf(" %[^\n]",m2);
		root=insert(root,str,m1,m2);
		printf("\n\nEnglish\t\tTamil\t\tHindi\n");
		inorder(root);
		printf("\n\nEnter English word: ");
		scanf(" %[^\n]",str);
	}
	strcpy(str,"");
	while(strcmp(str,"0"))
	{
		printf("\nFind meaning of: ");
		scanf(" %[^\n]",str);
		meaning(root,str);
	}
	return 0;
}
