# OS_Assignment_K1641_A11
Operating Systems Assignment

#include<stdio.h> 
#include<conio.h>
void thirdIteration(int number,int remaining_time[10],int current_time,int arrival_time[10], int burst_time[10]);
int main() 
{
	int pno,j,number,currentTime,remainingProcess,flag,time_quantum,waiting_time,turn_around_time,arrival_time[10],burst_time[10],remaining_time[10],iterator=1;
	waiting_time = 0;
	flag = 0;
	turn_around_time = 0;
	printf("Enter no of processes"); 
	scanf("%d",&number);
	remainingProcess = number;
	printf("\nEnter details of the processes\n");
	for(pno = 0;pno < number;pno++) 
	{
		printf("\nProcess P%d\n\t",pno+1);
		printf("Arrival time = "); 
		scanf("%d",&arrival_time[pno]);
		printf("\tBurst time = "); 
		scanf("%d",&burst_time[pno]); 
		remaining_time[pno]=burst_time[pno]; 
	} 
	
	printf("\nFirst iteration (time quantum = 6)\n"); 
	time_quantum=6;
	currentTime=0;
	for(pno=0;remainingProcess!=0;) 
	{
		if(remaining_time[pno]<=time_quantum && remaining_time[pno]>0)	
		{ 
			currentTime+=remaining_time[pno]; 
			remaining_time[pno]=0; 
			flag=1; 
		} 
		else if(remaining_time[pno]>0)
		{ 
			remaining_time[pno]-=time_quantum; 
			currentTime+=time_quantum; 
		} 
		if(remaining_time[pno]==0 && flag==1)			
		{ 
			remainingProcess--;			
			printf("P%d",pno+1); 
			printf("\t\t\t%d",currentTime-arrival_time[pno]);
			printf("\t\t\t%d\n",currentTime-burst_time[pno]-arrival_time[pno]);
			waiting_time+=currentTime-arrival_time[pno]-burst_time[pno]; 
			turn_around_time+=currentTime-arrival_time[pno]; 
			flag=0; 
		} 
		if(pno==number-1){
			iterator++;
			if(iterator==2){
				pno=0;
				time_quantum=10;
				printf("\nComplited the First Iteration");
				printf("\nStarts the Second Iteration (time quantum 10)\n\n");
			}
			else{
				printf("\n\nCompletes the Seconds Iteration");
				break;
			}
		}
		else if(currentTime >= arrival_time[pno+1]){
			pno++;
		}
		else{
			pno=0;
		}
	}
	
	thirdIteration(number,remaining_time,currentTime,arrival_time,burst_time);
	
	return 0;
}


void thirdIteration(int number,int remaining_time[10],int current_time,int arrival_time[10], int burst_time[10]){

	float average_weight,average_tut;
    int i,j,n=number,temp,btime[20],pno[20],wtime[20],tutime[20],total=0,loc;
    
    printf("\nStarts the Third Iteration(least burst time)\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=remaining_time[i];
        wtime[i]=current_time-arrival_time[i]-btime[i];
		pno[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=pno[i];
        pno[i]=pno[loc];
        pno[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	wtime[i]+=btime[j];
        }
        total+=wtime[i];
    }
 
    average_weight=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tutime[i]=btime[i]+wtime[i];
        total=total + tutime[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",pno[i],btime[i],wtime[i],tutime[i]);
    }
    average_tut=(float)total/n;
    printf("\n\nExecution of Average Time wait = %f",average_weight);
    printf("\n Execution of Average turnaround time  = %f\n",average_tut);
	
}
