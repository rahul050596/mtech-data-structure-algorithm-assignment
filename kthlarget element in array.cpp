#include<iostream>
using namespace std;
int partition(int a[],int low,int high)
{
	int temp;
	int i=low;
	int j=high+1;
	a[j]=12000;
	int x=a[low];
	do
	{
		do
		{
			i=i+1;
		}while(x<a[i]&&i<=j);
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
int kthlargest(int a[],int low,int high,int k)
{
	int j;
 if(low>=high)
 {
	if(k==low&&low==high)
	return (k);
	else
	return (false);
	
 }
 else
 {
		 j=partition(a,low,high);
		
		if(k<j)
		{
	
		   return kthlargest(a,j+1,high,k);
		}
	    
	    
	    if(k>j)
		{
				 	 	
		  return kthlargest(a,low,j-1,k);
		  
        }
		else
		{
		
		   return (k);
		}
		
		 
  }
}
int main()
{
	int n,k,i;
	int a[60];
	cout<<"enter the index of array \n";
	cin>>n;
	cout<<"enter the element of array: \n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"unsorted array is : \n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"enter the kth largest index of element:\n";
	cin>>k;
	cout<<"\n kth element is:"<<k;
	
int y=	kthlargest(a,0,n-1,k);
cout<<"\n the kth largest element in the given array is : "<<a[y];
	return 0;

	
}
