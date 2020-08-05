#include"prototypes.h"
int main()
{
	stud obj[15],newobj;
	int n,op,reg;
	char ch;
	printf("Enter no. of Records; \n");
	scanf(" %d",&n);
	for(int i=0;i<n;++i)
	{
		printf("Record %d\n",i+1);
		printf("Enter Reg.No: ");
		scanf(" %d",&obj[i].regno);
		printf("Enter Name: ");
		scanf(" %[^\n]",obj[i].name);
		printf("Enter Marks in 5 subjects\n");
		for(int j=0;j<5;++j)
			scanf(" %d",&obj[i].marks[j]);
	}
	do
	{
		printf("Menu\n");
		printf("1.Insert Front\n");
		printf("2.Insert End\n");
		printf("3.Insert Middle\n");
		printf("4.Search\n");
		printf("5.Delete a Record\n");
		printf("6.Display all Records\n");
		printf("7.Display Previous and Next\n");
		printf("Enter your choice(1-7): \n");
		scanf(" %d",&op);
		printf("\n*****************\n");
		switch(op)
		{
			case 1:
					printf("New Record\n");
					printf("Enter Reg.No: ");
					scanf(" %d",&newobj.regno);
					printf("Enter Name: ");
					scanf(" %[^\n]",newobj.name);
					printf("Enter Marks in 5 subjects\n");
					for(int j=0;j<5;++j)
						scanf(" %d",&newobj.marks[j]);
					insertfront(obj,newobj,&n);
					break;
			case 2:
					printf("New Record\n");
					printf("Enter Reg.No: ");
					scanf(" %d",&newobj.regno);
					printf("Enter Name: ");
					scanf(" %[^\n]",newobj.name);
					printf("Enter Marks in 5 subjects\n");
					for(int j=0;j<5;++j)
						scanf(" %d",&newobj.marks[j]);
					insertend(obj,newobj,&n);
					break;
			case 3:
					printf("New Record\n");
					printf("Enter Reg.No: ");
					scanf(" %d",&newobj.regno);
					printf("Enter Name: ");
					scanf(" %[^\n]",newobj.name);
					printf("Enter Marks in 5 subjects\n");
					for(int j=0;j<5;++j)
						scanf(" %d",&newobj.marks[j]);
					printf("Enter Register after which to insert: \n");
					scanf(" %d",&reg);
					insertmiddle(obj,newobj,&n,reg);
					break;
			case 4:
					printf("Enter Name to search: ");
					char name[30];
					scanf(" %[^\n]",name);
					search(obj,n,name);
					break;
			case 5: 
					printf("Enter Reg.no. to delete: ");
					//int reg;
					scanf(" %d",&reg);
					del(obj,&n,reg);
					break;
			case 6: 
					display(obj,n);
					break;
			case 7:
					printf("Enter Reg.no. : ");
					//int reg;
					scanf(" %d",&reg);
					prevnext(obj,n,reg);
					break;

		}
		printf("\nDo you want to continue?(y/n): ");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;	

}
