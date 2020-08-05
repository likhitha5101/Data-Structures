#include"prototypes.h"
int main(int argc, char const *argv[])
{
	node *h,*t,*temp;
	int ch=1,op;
	h=create();
	t=h->next;
	do
	{
		printf("\nMENU");
		printf("\n1.INSERT FRONT");
		printf("\n2.INSERT END");
		printf("\n3.INSERT AFTER A RECORD");
		printf("\n4.SEARCH A STUDENT");
		printf("\n5.DELETE A STUDENT");
		printf("\n6.DISPLAY ALL");
		printf("\n7.DISPLAY IN ALPHABETICAL ORDER");
		printf("\nENTER YOUR CHOICE(1-7): ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:front(h,t);
					break;
			case 2:last(h,t);
					break;
			case 3:middle(h,t);
					break;
			case 4:printf("\nEnter Name to search: ");
					temp=search(h,t);
					if(temp!=NULL)
						printf("\nRecord found!!!");
					else
						printf("\nRecord not found!!!");
					break;
			case 5:delet(h,t);
					break;
			case 6:display(h,t);
					break;
			case 7:alpha(h,t);
					break;

		}
		printf("\nEnter 1 to continue: ");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}
