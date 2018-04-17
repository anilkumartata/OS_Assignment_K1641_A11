# OS_Assignment_K1641_A11
Operating Systems Assignment

#include<stdio.h>
#include<unistd.h>
struct resource
{	
	int pen;
	int paper;
	int question_paper;
	int allot_id;		
};
struct t_resource
{	
	int pen_count ;
	int paper_count ;
	int question_paper_count ;
}; 
struct t_resource t[3];
void allotment(struct resource a)
{
	if(a.allot_id == 0)
{
		a.pen=1;
}
	else if(a.allot_id == 1){
		a.paper=1;
	}
	else if(a.allot_id == 2){
		a.question_paper=1;
	}
	
}
int main(){
	struct resource s[3];	
	int i,j,count=0;
	for(i=0;i<3;i++){
		s[i].allot_id=i;
		allotment(s[i]);
	}
	printf("\nAlloted Resouces  are :");
	for(i=0;i<3;i++)
	{
		if(s[i].allot_id == 0)
		printf("\nStudent Allocated Resource %d is : pen ",i+1);		
		if(s[i].allot_id==1)
		printf("\nStudent Allocated Resource %d is  : paper ",i+1);
		if(s[i].allot_id == 2)
		printf("\nStudent Allocated Resource %d is  : question paper ",i+1);
	}
	
	while(count <3){
		for(i=0;i<3;i++){
			if(i=0){
				t[i].paper_count=1;
				t[i].question_paper_count=1;
				for(j=0;j<3;j++){
					if(s[j].allot_id==0){
						printf("\nFirst  Student completed his job !");
					}
				}
				count++;
			}
			
			if(i=1)
			{
				t[i].question_paper_count=1;
				t[i].pen_count=1;
				for(j=0;j<3;j++)
				{
					if(s[j].allot_id==1)
					{
						printf("\nSecond Student completed his job !");
						
					}
				}
				count++;
			}
			
			if(i=2)
			{
				t[i].paper_count=1;
				t[i].pen_count=1;
				for(j=0;j<3;j++){
					if(s[j].allot_id==2){
						printf("\nThird Student completed his job !");
						
					}
				}
				count++;
			}
		}
		
	}
	return 0;
	
}
