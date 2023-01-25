#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
	int temp;
int i=low;
int j=high+1;
int x=a[low];
do
{
	do
	{
		i=i+1;
		
	}while(a[i]<x);
	do
	{
		j=j-1;
	}while(a[j]>x);
	if(i<j)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;		
	}

}while(i<j);
a[low]=a[j];
a[j]=x;
return (j);
}
void quicksort(int a[],int low,int high)
{
	int j;
if(low<high)
{
	 j=partition(a,low,high);
		
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);
	
	}
	
	
}
int main()
{
	int n;
	int a[60];
	
	int i;
	cout<<"enter the index of array \n";
	cin>>n;
	cout<<"\n index of array is n:"<<n;
	cout<<"\n enter the unsorted array element";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\n unsorted aaray is: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	quicksort(a,0,n-1);
	cout<<"\n sorted array is :";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" \t";
	}
	return 0;
}
