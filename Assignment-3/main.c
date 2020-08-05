#include"prototypes.h"
int main()
{
	node * head1,*head2;
	head1=createlist();
	char ch,op;
	printf("Enter Polynomial 1: \n");
	getpolynomial(head1);
	printf("**************\n");
	head2=createlist();
	printf("Enter Polynomial 2: \n");
	getpolynomial(head2);
	printf("**************\n");	
	do
	{
		printf("\nMenu\n1.Add polynomials \n2.Multipy polynomials");
		printf("\nEnter your choice: ");
		scanf(" %c",&op);
		if(op=='1')
		{
			node * res;
			res=createlist();
			printf("\n\nPolynomial 1: ");
			output(head1);
			
			printf("\n\nPolynomial 2: ");
			output(head2);
			add(head1,head2,res);
			printf("\n\nAddition Result: ");
			output(res);
		}
		else if(op=='2')
		{
			node * res;
			res=createlist();
			printf("\n\nPolynomial 1: ");
			output(head1);
			printf("\n\nPolynomial 2: ");
			output(head2);
			printf("\n\nMultiplication Result: ");
			multipy(head1,head2,res);
			output(res);

		}
		printf("\nDo you want to continue?(y/n): ");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
