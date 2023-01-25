#include<iostream>
using namespace std;
struct process
{
	int processid;
	int bursttime;
	int arrivaltime;
}; struct process processqueue[4];
int insert(int list[][2],int number_of_processes)
{
	int i;
	for(i=0;i<number_of_processes;i++)
	{
		processqueue[i].processid=i;
		processqueue[i].bursttime=list[i][0];
		processqueue[i].arrivaltime=list[i][1];
	}
	return 0;
}
int print(int number_of_processes)
{
	cout<<"process id  "<<"burst time  "<<"arrival time \n";
	for(int i=0;i<number_of_processes;i++)
	{
		cout<<processqueue[i].processid<<"        "<<processqueue[i].bursttime<<"       "<<processqueue[i].arrivaltime<<"\n";
		
	}
	return 0;
}
intdelete(int number_of_processes)
{
	int i,j,avail_process,currentprocess_arrivaltime,minprocess_arrivaltime,minprocess_bursttime,minprocess_index,elapsedtime=0;
     struct process current_process,min_process;
	 avail_process=number_of_processes;
	 for(i=0;i<number_of_processes;i++)
	 {
	 	
	 	print(number_of_processes);
	 	j=0;
	 	min_process=processqueue[j];
	 	minprocess_index=j;
	 	minprocess_arrivaltime=min_process.arrivaltime;
	 	currentprocess_arrivaltime=minprocess_arrivaltime;
	 	while(currentprocess_arrivaltime>elapsedtime)
	 	{
	 		if(j+1<avail_process)
	 		{
	 			j++;
	 			currentprocess_arrivaltime=processqueue[j].arrivaltime;
	    	}
	    	else
	    	{
	    		cout<<"no min process at time"<<elapsedtime<<"\n";
	    		elapsedtime=minprocess_arrivaltime;
	    		currentprocess_arrivaltime=minprocess_arrivaltime;
	    		cout<<"time elapsed :"<<elapsedtime<<"\n";
	    		print(number_of_processes);
	    		
			}
	 		if(currentprocess_arrivaltime<minprocess_arrivaltime)
	 		{
	 			min_process=processqueue[j];
	 			minprocess_index=j;
	 			minprocess_arrivaltime=currentprocess_arrivaltime;
	 			
			}
			
    	}
    	j=minprocess_index;
    	minprocess_bursttime=min_process.bursttime;
    	for(;j<avail_process;j++)
    	{
    		current_process=processqueue[j];
    		if((current_process.arrivaltime<=elapsedtime)&&(current_process.bursttime<=minprocess_bursttime))
    		{
    			min_process=current_process;
    			minprocess_index=j;
    			minprocess_bursttime=min_process.bursttime;
			}
		}
		avail_process--;
		elapsedtime=elapsedtime+minprocess_bursttime;
		cout<<"min process: "<<min_process.processid<<" "<<min_process.bursttime<<" "<<min_process.arrivaltime<<"\n";
		cout<<"time elapsed: "<<elapsedtime<<"\n";
		for(j=minprocess_index;j<number_of_processes;j++)
		{
			processqueue[j]=(j+1!=number_of_processes ? processqueue[j+1]: min_process); // this ternary operator
		}
     } 
	 print(number_of_processes);
	 cout<<"no process available: ";
	 return 0; 
}
int main()
{
	int number_of_processes=4;
	// list of processes is array
	int list[][2]={
	// {bursttime, arrivaltime}
	//Array index is treated as process id
	{3,1},
	{6,0},
	{4,5},
	{8,0}
};
insert(list,number_of_processes);
intdelete(number_of_processes);
return 0;
}
