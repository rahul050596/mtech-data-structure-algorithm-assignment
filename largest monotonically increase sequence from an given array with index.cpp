#include<iostream>
using namespace std;
int main()
{
	int a[60];
	int n,i,j;
	int max_length=0;
	int start_index=-1;
	cout<<"enter the index of array : ";
	cin>>n;
	cout<<"\n enter the element ofARRAY: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\n ARRAY element is: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	for(i=0;i<n;i++)
	{
		int length=1; //start couting from current element
	 for(j=i+1;j<n;j++)
	 {
	 	if(a[j]>a[j-1])
	 	{
	 		length++;
		 }
		 else
		 {
		 	break;
		 }
      }
	 if(length>max_length)
	 {
	 	max_length=length;
	 	start_index=i;
	 }
	}
	int end_index;
    cout<<"\n Largest mototonically increasing sequence: ";
	for(i=start_index;i<start_index+max_length;i++)
	{
		cout<<a[i]<<"\t";
	
	}
	end_index=i-1;
	cout<<"\n start index: "<<start_index;
	cout<<"\n end index : "<<end_index;
	return 0;
}
