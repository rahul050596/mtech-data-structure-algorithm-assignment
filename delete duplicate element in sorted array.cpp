#include<iostream>
using namespace std;
int main()
{
	int a[50];
	int i,n;
	int j=0;
   cout<<"enter the index of sorted ARRAY :";
   cin>>n;
   cout<<"\n enter the element of Sorted ARRAY: ";
   for(i=0;i<n;i++)
   {
   	cin>>a[i];

   }
   cout<<"\n Sorted ARRAY is: ";
   for(i=0;i<n;i++)
   {
   	cout<<a[i]<<"\t";
   }
   for(i=0;i<n;i++)
   {
   	if(a[i]!=a[i+1])
   	{
   	  a[j]=a[i];
	   	j++;
    }
   }
   a[j]=a[n-1];
   cout<<"\n distinct sorted ARRAY is: ";
   for(i=0;i<j;i++)
   {
   	cout<<a[i]<<"\t";
   }
   return 0;
}
