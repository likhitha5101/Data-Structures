#include"stack.h"
int main()
{
	char ch;
	do
	{
		char str1[50],str[50]="(", post[50];
		int op[50];
		node * top=NULL;
		printf("Enter the expression:\n");
		scanf(" %[^\n]",str1);
		strcat(str,str1);
		strcat(str,")");
		int f=postfix(top,str,post);
        if(f!=1)
        {
            float ans=evaluate(post);
            printf("\nEvaluation of postfix: %.2f",ans);
        }
        printf("\n");
        printf("\nDo you want to continue?(y/n): ");
        scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
