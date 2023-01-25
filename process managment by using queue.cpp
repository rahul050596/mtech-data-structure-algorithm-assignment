#include<iostream>
using namespace std;
struct process {  // define the node of the queue named as process
 int processid;
 int bursttime;
 int arrivaltime;
 struct process * nextprocess; // nextprocess is pointer of structure process of type struct
 
 };
 int insert_B(int list[][2],int number_of_processes)
 {
 	struct process * current_process=NULL;
 	for(int i=0;i<number_of_processes;i++)
 	{
 		current_process=(struct process *) malloc(sizeof(struct process *));
 		current_process->processid=i;
 		current_process->bursttime=list[i][0];
 		current_process->arrivaltime=list[i][1];
 		current_process->nextprocess=NULL;
 		if(i>0)
 		{
 			rear->nextprocess=current_process;
 			
 			
		} else if(i==0)
		
		{
			front=current_process;
	    }
	     rear=current_process;  
		current_process=NULL;
		free(current_process);
		
		
 		
	}
	rear->nextprocess=NULL;
	return 0;
 }
 int insert_c(int list[][2],int number_of_processes)
 {
 	int i,j,elapsedtime=0,time_difference,temp_elapsedtime,minprocess_bursttime;
 	struct process * current_process=NULL,* previous_process=NULL,*nextprocess=NULL,*minprocess=NULL;
 	previous_process=front;
 	for(i=0;i<number_of_processes;i++)
 	{
 		current_process=(struct process *) malloc(sizeof(struct process *));
 		current_process->processid=i;
 		current_process->bursttime=list[i][0];
 		current_process->arrivaltime=list[i][1];
 		current_process->nextprocess=NULL;
 		if(i>0)
 		{
 			time_difference=(current_process->arrivaltime) - elapsedtime;
 			if(time_difference<0)
 			{
 				previous_process=front;
 				nextprocess=front;
 				while(previous_process!=rear)
 				{
 				//	time_difference=
 					
				}
				
 				
			}
			else
			{
				rear->nextprocess=current_process;
				rear=current_process;
				elapsedtime=elapsedtime+time_difference+current_process->bursttime;
				
			}
		}
		else
		{
			front=current_process;
			rear=current_process;
			elapsedtime=(current_process->arrivaltime)+(current_process->bursttime);
			minprocess_bursttime=current_process->bursttime;
		}
 		current_process=NULL;
 		free(current_process);
	}
	return 0;
 }
 int print()
 {
 	if(front!=NULL)
 	{
 		struct process * current_process;
 		current_process=front;
 		cout<<"processid "<<"bursttime "<<"arrivaltime \n";
 		while(current_process->nextprocess!=NULL)
 		{
 			cout<<current_process->processid<<"     "<<current_process->bursttime<<"     "<<current_procees->arrivaltime<<"\n";
 			current_process=current_process->nextprocess;
		}
		cout<<current_process->processid<<"     "<<current_process->bursttime<<"     "<<current_process->arrivaltime<<"\n";
		
		
		
 		
    }
    return 0;
 }
 int main()
 {
 	// list of processis in array
 	int list[5][2]={
 		{2,0}, //{bursttime,arrivaltime} 
 		{4,3}, // array index is trated as processid
 		{8,0},
 		{4,2},
 		{5,4}
		 
      };
      
	insert_B(list,5);
	print();
	return 0;	 
		 
		 
	 
 }
