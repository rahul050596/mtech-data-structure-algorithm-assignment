#include<iostream>
using namespace std;
void MaxSecondMax(int a[], int n)
{
	int Max=0;
	int S_max=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]>Max)
		{
			S_max=Max;
			Max=a[i];
			
		}
		else if(a[i]>S_max&&a[i]!=Max)
		{
			S_max=a[i];
		}
	}
	if(S_max==0)
	{
		S_max=-1;
	}
	cout<<"\n maximum value of array is :"<<Max;
	cout<<"\n second max value is :"<< S_max;
}
void MinSecondMin(int a[],int n)
{
	int Min=a[0];
	int S_min=0;
	for(int i=0;i<n;++i)
	{
		if(a[i]<Min)
		{
			S_min=Min;
			Min=a[i];
		}
		else if(a[i]<S_min&&a[i]!=Min)
		{
			S_min= a[i];
		}
	}
	if(S_min==0)
	{
		S_min=-1;
	}
	cout<<"\n minimum value in array is: "<<Min;
	cout<<"\n second minimum value in array is: "<<S_min;
}
int main()
{
	int a[60];
	int n,i;
	cout<<"enter the number  n :";
	cin>>n;
	cout<<"enter the element of array a:\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"array element is :";
	
	for( i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	MaxSecondMax(a,n);
	MinSecondMin(a,n);
	
}
