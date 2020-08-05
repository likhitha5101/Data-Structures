#include<stdio.h>
int linearsearch(int arr[],int n,int x)
{
	for(int i=0;i<n;++i)
	{
		if(arr[i]==x)
			return i+1;
	}
	return -1;
}
void bubblesort(int arr[],int n)
{
	int temp;
	for(int i=0;i<n-1;++i)
		for(int j=0;j<n-i-1;++j)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
}	
int binarysearch(int arr[],int n,int x)
{
	int ul,ll,mid;
	ll=0;
	ul=n-1;
	bubblesort(arr,n);
	while(ll<=ul)
	{
		mid=(ul+ll)/2;
		if(arr[mid]==x)
			return mid+1;
		else if(arr[mid]<x)
			ll=mid+1;
		else
			ul=mid-1;
	}
	return -1;
}

void selectionsort(int arr[],int n)
{
	int small,pos,temp;
	for(int i=0;i<n;++i)
	{
		small=arr[i];
		pos=i;
		for(int j=i+1;j<n;++j)
		{
			if(arr[j]<small)
			{
				small=arr[j];
				pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
}
int main()
{
	int arr[20],n,op,x,res;
	char ch;
	printf("\nENTER NO. OF ELEMENTS: ");
	scanf(" %d",&n);
	printf("\nENTER ELEMENTS: ");
	for(int i=0;i<n;++i)
		scanf(" %d",&arr[i]);
	do
	{
		printf("\n MENU\n");
		printf("\n1.LINEAR SEARCH");
		printf("\n2.BINARY SEARCH");
		printf("\n3.BUBBLE SORT");
		printf("\n4.SELECTION SORT");
		printf("\nENTER YOUR CHOICE(1-4): ");
		scanf(" %d",&op);
		switch(op)
		{
			case 1:printf("\nLINEAR SEARCH");
					printf("\nENTER ELEMENT TO SEARCH: ");
					scanf(" %d",&x);
					res=linearsearch(arr,n,x);
					if(res==-1)
						printf("\nELEMENT NOT FOUND");
					else
						printf("\nELEMENT FOUND AT POSITION %d",res);
					break;
			case 2: printf("\nBINARY SEARCH");
					printf("\nENTER ELEMENT TO SEARCH: ");
					scanf(" %d",&x);
					res=binarysearch(arr,n,x);
					if(res==-1)
						printf("\nELEMENT NOT FOUND");
					else
						printf("\nELEMENT FOUND");
					break;
			case 3: printf("\nBUBBLE SORT");
					bubblesort(arr,n);
					printf("\nELEMENTS SORTED SUCCESSFULLY!!");
					printf("\nSORTED ARRAY: ");
					for(int i=0;i<n;++i)
						printf("%d ",arr[i]);
					break;
			case 4: printf("\nSELECTION SORT");
					selectionsort(arr,n);
					printf("\nELEMENTS SORTED SUCCESSFULLY!!");
					printf("\nSORTED ARRAY: ");
					for(int i=0;i<n;++i)
						printf("%d ",arr[i]);
					break;
		}
		printf("\nDO YOU WANT TO CONTINUE? (Y/N): ");
		scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
