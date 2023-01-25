#include<iostream>
using namespace std;
struct process 
{
	int processid;
	int bursttime;
};struct process processqueue[5];
// array of structures
int heapify(int parent_index,int number_of_processes,struct process temp)
{
	//left child = 2*parentindex
	int child_index=parent_index*2+1;
	//check left child exists or not.
	while(child_index<number_of_processes)
	{
		if((child_index+1<number_of_processes)&&(processqueue[child_index].bursttime>processqueue[child_index+1].bursttime))
		{
			child_index++;
		}
		if(temp.bursttime>processqueue[child_index].bursttime)
		{
			processqueue[(child_index-1)/2]=processqueue[child_index];
			child_index=child_index*2+1;
		}
		else
		{
			break;
		}
	} 
	processqueue[(child_index-1)/2]=temp;
    return 0;
} 
int print(int number_of_processes) // this is used for print the process from queue
{
	cout<<"processid "<<"bursttime \n";
	for(int i=0;i<number_of_processes;i++)
	{
		cout<<processqueue[i].processid<<"      "<<processqueue[i].bursttime<<"\n";
		
	}
	return 0;
}
int print_heap(int number_of_processes) //print process from heap
{
	int i,j,power,current_index=0;
	i=0;
	while(i<number_of_processes&&current_index<number_of_processes)
	{
		power=2^i;
		
		//when current_index== no of process  means looparrived on leaf node
		j=0;
		while(j<power&&current_index<number_of_processes)
		{
			cout<<processqueue[current_index].processid<<"  "<<processqueue[current_index].bursttime;
			current_index++;
			j++;
		}
		cout<<"\n";
		i++;
	}
	return 0;
}
int insert_A(int list[],int number_of_processes) //insert new process in ascending order to a sorted queue using insertion sort
{
	for(int i=0;i<number_of_processes;i++)
	{
		processqueue[i].processid=i;
		processqueue[i].bursttime=list[i];
	}
	return 0;
}
int insert_B(int list[],int number_of_processes) //insert new process
{
	int i,j,current_index,current_bursttime;
	i=0;
	while(i<number_of_processes)
	{
		current_bursttime=list[i];
		j=0;
		while(j<i && processqueue[i].bursttime>current_bursttime)
		{
			j++;
		}
		current_index=j;
		for(j=i;j>current_index;j--) //shift the process to right and makes slot for new process
		{
			processqueue[j]=processqueue[j-1];
		}
		
		// insert new process
		processqueue[current_index].processid=i;
		processqueue[current_index].bursttime=current_bursttime;
		i++;
	}
	
	return 0;
}
int insert_C(int list[],int number_of_processes) //insert new process in descending order using insertion sort
{
	int i,j,avail_process,current_index,current_bursttime;
	i=0;
	while(i<number_of_processes)
	{
		j=number_of_processes-1;
		avail_process=number_of_processes-(i+1);
		current_bursttime=list[i];
		//find the location of where process insertedbut starts looking from last index
		while(j>avail_process && processqueue[1].bursttime<=current_bursttime)
		{
			j--;
		}
		current_index=j;
		for(j=avail_process;j<current_index;j++)
		{
			processqueue[j]=processqueue[j+1];
		}
		processqueue[current_index].processid=i;
		processqueue[current_index].bursttime=current_bursttime;
		i++;
		
	}
	return 0;
}
int insert_D(int list[],int number_of_processes) //mode insert into queue and heapify into min heap
{
	int i,child_index;
	struct process temp;
	for(i=0;i<number_of_processes;i++)
	{
		processqueue[i].processid=i;
		processqueue[i].bursttime=list[i];
	}
	for(i=(number_of_processes-1)/2;i>0;i--)
	{
		heapify(i,number_of_processes,processqueue[i]);
	}
	return 0;
}
int delete_A(int number_of_processes) // finding location of minimum burst time
{
	int i,j,min_index,min_bursttime,elapsedtime=0,avail_process=number_of_processes;
	struct process min_process;
	i=0;
	while(i<number_of_processes)
	{
		print(number_of_processes);
		min_process=processqueue[0];
		min_index=0;
		min_bursttime=min_process.bursttime;
		j=1;
		while(j<avail_process && processqueue[j].bursttime<min_bursttime)
		{
			min_process=processqueue[j];
			min_index=j;
			min_bursttime=min_process.bursttime;
			j++;
		}
		elapsedtime=elapsedtime+min_bursttime;
		cout<<"min process: "<<min_process.processid<<min_bursttime<<"\n";
		cout<<"time elapsed: "<<elapsedtime<<"\n";
		for(j=min_index;j>number_of_processes;j++)
		{
			processqueue[j]=(j+1!=number_of_processes ? processqueue[j+1] : min_process);
		}
	  avail_process--;
	  i++;	
	}
	print(number_of_processes);
	cout<<" no processes available \n";
	return 0;
}
int delete_B(int number_of_processes) // delete process from the start of the queue
{
	int i,j,elapsedtime=0;
	struct process min_process;
	i=0;
	while(i<number_of_processes)
	{
		print(number_of_processes);
		min_process=processqueue[0];
		elapsedtime=elapsedtime+min_process.bursttime;
		cout<<"minmum process:"<<min_process.processid<<" "<<min_process.bursttime<<"\n";
		cout<<"time elapsed:"<<elapsedtime<<"\n";
		j=0;
		while(j<number_of_processes)
		{
			processqueue[j]=(j+1!=number_of_processes ? processqueue[j+1]:min_process); // ternary operator
		}
		i++;
	}
	print(number_of_processes);
	cout<<"no process available:\n";
	return 0;
}
int delete_C(int number_of_processes) // deletes process from the start of the queue
{
	int i,elapsedtime=0;
	for(i=number_of_processes;i>0;i--)
	{
		print(number_of_processes);
		elapsedtime=elapsedtime+processqueue[i].bursttime;
		cout<<"min process: "<<processqueue[i].processid<<" "<<processqueue[i].bursttime<<"\n";
		cout<<"time elapsed: "<<elapsedtime<<"\n";
	}
	return 0;
}
int delete_D(int number_of_processes) //deletes process from the heap
{
	int i,child_index,elapsedtime=0;
	struct process temp;
	for(i=number_of_processes;i>0;i--)
	{
		print_heap(number_of_processes);
		elapsedtime=elapsedtime+processqueue[0].bursttime;
		cout<<"min process: "<<processqueue[0].processid<<" "<<processqueue[0].bursttime<<"\n";
		cout<<"time elapsed: "<<elapsedtime<<"\n";
		temp=processqueue[i];
		processqueue[i]=processqueue[0];
		heapify(0,i,temp); 
	}
	return 0;
}

int main()
{
	int number_of_processes=5,entry;
	// list of processes is given as an array
	int list[]={3,5,6,10,4};
	do 
	{
		cout<<"choice of the processor that will insert the job in queue \n  1 as of arriving sequence \n 2 shortest job on front \n 3 shortest job on rear \n 4 using min-heap\n eneter the entry ";
		cin>>entry;
		switch(entry)
		{
			case 1: insert_A(list,number_of_processes);
			        delete_A(number_of_processes);
			        break;
			case 2: insert_B(list,number_of_processes);
			        delete_B(number_of_processes);
			        break;
			case 3: insert_C(list,number_of_processes);
			        delete_C(number_of_processes);
			        break;
			case 4: insert_D(list,number_of_processes);
			        delete_D(number_of_processes);
			        break;
		    default: cout<<" entry is invalid, choose entry again\n";	        
		}
		
		
	}while(entry<1||entry>4);
	return 0;
}
