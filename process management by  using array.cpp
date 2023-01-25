#include<iostream>
using namespace std;
// list of processes is given as an array
 int processqueue[][3]={
  // {processid,burst time,arrival time}
  {0,2,1},
  {1,4,3},
  {2,8,0},
  {3,10,2},
  {4,6,4}
  
};

int print(int numberofprocesses)
{
	int i;
	cout<<"processid\tburst time\tarrival time \n";
	for(i=0;i<numberofprocesses;i++)
	{
		cout<<processqueue[i][0]<<"\t        "<<processqueue[i][1]<<"\t        "<<processqueue[i][2]<<"\n";
		
	}
	return 0;
}
  
int delete_without_shifting(int numberofprocesses)
{
	int i,j,minprocess_bursttime,minprocess_index,sum_of_bursttime=0;
	for(i=0;i<numberofprocesses;i++)
	{
		j=0;
		while((processqueue[j][1]==0)||(processqueue[j][2]>sum_of_bursttime))
		{
			j++;
		}
		minprocess_bursttime=processqueue[j][1];
		minprocess_index=j;
		for(j=j;j<numberofprocesses;j++)
		{
			if((processqueue[j][1]!=0)&&((processqueue[j][2]<=sum_of_bursttime)&&(processqueue[j][1]<=minprocess_bursttime)))
			{
				minprocess_bursttime=processqueue[j][1];
				minprocess_index=j;
			}
		}
		sum_of_bursttime=sum_of_bursttime+minprocess_bursttime;
		cout<<"min process: "<<processqueue[minprocess_index][0]<<"\t"<<minprocess_bursttime<<"\t"<<processqueue[minprocess_index][2]<<"\n";
		cout<<"time elapsed:"<<sum_of_bursttime<<"\n";
		processqueue[minprocess_index][1]=0;
		
	}
	return 0;
}
	
intdelete(int numberofprocesses)
{
	int i,j,availableprocesses,currprocess_arrivaltime,minprocess_arrivaltime,minprocess_bursttime,minprocess_index,elapsedtime=0;
	int * minprocess, * currprocess;
	int minprocess_values[3];
	availableprocesses=numberofprocesses;
	for(i=0;i<numberofprocesses;i++)
	{
		print(numberofprocesses);
		j=0;
		minprocess=processqueue[j];
		minprocess_index=j;
		minprocess_arrivaltime=minprocess[2];
		currprocess_arrivaltime=minprocess_arrivaltime;
		while(currprocess_arrivaltime>elapsedtime)
		{
			if(j+1<availableprocesses)
			{
				j++;
				currprocess_arrivaltime=processqueue[j][2];
			}
			else
			{
				cout<<"No min process at time:"<<elapsedtime<<"\n";
				elapsedtime=minprocess_arrivaltime;
				cout<<"time elapsed:"<<elapsedtime<<"\n";
				cout<<numberofprocesses;
			}
			if(currprocess_arrivaltime<minprocess_arrivaltime)
			{
				minprocess=processqueue[j];
				minprocess_index=j;
				minprocess_arrivaltime=minprocess[2];
			}
		}
		j=minprocess_index;
		minprocess_bursttime=minprocess[1];
		for(j=minprocess_index;j<availableprocesses;j++)
		{
	     	currprocess=processqueue[j];
	     	if((currprocess[2]<=elapsedtime)&&(currprocess[i]<=minprocess_bursttime))
	     	{
	     	minprocess=currprocess;
			 minprocess_index=j;
			 minprocess_bursttime=minprocess[1];	
	     		
			}
	     	
		}
		availableprocesses--;
		elapsedtime=elapsedtime+minprocess_bursttime;
		cout<<"min process: "<<minprocess[0]<<minprocess_bursttime<<minprocess[2]<<"\n";
		cout<<"time elapsed: "<<elapsedtime<<"\n";
		minprocess_values[0]=minprocess[0];
		minprocess_values[1]=minprocess_bursttime;
		minprocess_values[2]=minprocess[2];
	
	  for(j=minprocess_index;j<numberofprocesses;j++)
	  {
		if(j+1!=numberofprocesses)
		{
			processqueue[j][0]=processqueue[j+1][0];
			processqueue[j][1]=processqueue[j+1][1];
			processqueue[j][2]=processqueue[j+1][2];
		}
		else
		{
			processqueue[j][0]=minprocess_values[0];
			processqueue[j][1]=minprocess_values[1];
			processqueue[j][2]=minprocess_values[2];
		}
	  }
  }
 print(numberofprocesses);
 cout<<"there are  no more process available \n";
 return 0;
}
int main()
{

	int numberofprocesses=5;
	print(numberofprocesses);
   // delete_without_shifting(numberofprocesses);
	intdelete(numberofprocesses);
return 0;
}
 
