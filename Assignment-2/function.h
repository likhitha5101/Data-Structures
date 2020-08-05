#include<stdio.h>
#include<string.h>
typedef struct student
{
	int regno,marks[5];
	char name[30];
}stud;
void insertfront(stud obj[],stud newobj,int *n)
{
	int i;
	for(i=*n;i>0;--i)
		obj[i]=obj[i-1];
	obj[i]=newobj;
	(*n)++;
}
void insertend(stud obj[],stud newobj,int *n)
{
	obj[*n]=newobj;
	(*n)++;
}
void insertmiddle(stud obj[],stud newobj,int *n,int rno)
{
	int pos,i;
	for(pos=*n;obj[pos-1].regno!=rno&&pos>=0;--pos);
	
	if(pos>=0)
	{
		for(i=*n;i>pos;--i)
		obj[i]=obj[i-1];
		obj[i]=newobj;
		(*n)++;
	}
	else
		printf("Register no. not found\n");
}
void search(stud obj[],int n,char name[])
{
	int flag=0;
	for(int i=0;i<n;++i)
	{
		if(strcmp(name,obj[i].name)==0)
		{
			printf("Record found!!\n");
			printf("Reg.No: %d\n",obj[i].regno);
			printf("Name: %s\n",obj[i].name);
			printf("Marks in 5 subjects :\n");
			for(int j=0;j<5;++j)
				printf("%d\t",obj[i].marks[j]);
			flag=1;
		}
	}
	if(flag==0)
		printf("Record not found!!!\n");
}
void del(stud obj[],int *n,int rno)
{
	int flag=0;
	for(int i=0;i<*n;++i)
		if(rno==obj[i].regno)
		{
			while(i<*n-1)
			{
				obj[i]=obj[i+1];
				i++;
			}
			flag=1;
		}
	if(flag==0)
		printf("Record not found!!");
	else
		(*n)--;
}
void display(stud obj[],int n)
{
	printf("Reg.No\tName\tSub1\tSub2\tSub3\tSub4\tSub5\n");
	for(int i=0;i<n;++i)
	{
		printf("\n%d\t",obj[i].regno);
		printf("%s\t",obj[i].name);
		for(int j=0;j<5;++j)
			printf("%d\t",obj[i].marks[j]);
	}
}
void disp(stud obj)
{
	printf("Reg.No: %d\n",obj.regno);
	printf("Name: %s\n",obj.name);
	printf("Marks in 5 subjects\n");
	for(int j=0;j<5;++j)
		printf("%d\t",obj.marks[j]);
	printf("\n");
}
void prevnext(stud obj[],int n,int regno)
{
	for(int i=0;i<n;++i)
	{
		if(regno==obj[i].regno)
			{if(i==0)
			{
				printf("No Previous Record\n");
				printf("Record\n");
				disp(obj[i]);
				if(n>i)
					disp(obj[i+1]);
			}
			else if(i==n-1)
			{
				printf("Previous Record\n");
				disp(obj[i-1]);
				printf("Record\n");
				disp(obj[i]);
				printf("No Next Record\n");

			}
			else
			{
				printf("Previous Record\n");
				disp(obj[i-1]);
				printf("Record\n");
				disp(obj[i]);
				printf("Next Record\n");
				disp(obj[i+1]);
			}}
	}
}
