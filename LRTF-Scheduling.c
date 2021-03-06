//Three students (a, b, c) are arriving in the mess at the same time. The id numbers of these students are 2132, 2102, 2453 and the food taken time from the mess table is 2, 4 and 8 minutes. 
//If the two students have same remaining time so it is broken by giving priority to the students with the lowest id number. 
//Consider the longest remaining time first (LRTF) scheduling algorithm and calculate the average turnaround time and waiting time.

//Project done by S.venkat
#include <stdio.h>
struct stu
{
    int StuId;
    int FdTim;
    int wTim;
    int tuarTim;
};

void accept(struct stu list[], int s);
void display(struct stu list[], int s);
void scheduling(struct stu list[], int s);
void wTim(struct stu list[], int n);
void tuarTim(struct stu list[], int n);

int main()
{
    struct stu data[20];
    int n,i;
    char c='n';
    do
	{
    printf("Please enter the No. of students Who wants to eat in mess ? : ");
    scanf("%d", &n);
    accept(data, n);
    scheduling(data, n);
    wTim(data,n);
    tuarTim(data,n);
    display(data, n);
    printf("If you wish to continue press 'y'  : ");
    scanf("%s",&c);
    }while(c=='y');
    return 0;
} 

void accept(struct stu list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\n\nEnter data for students #%d", i + 1);
        
        printf("\nEnter student id : ");
        scanf("%d", &list[i].StuId);

        printf("Enter time taken for food in (minuts): ");
        scanf("%d", &list[i].FdTim);
    } 
}

void display(struct stu list[80], int s)
{
    int i,AvgwTim=0,AvgtuarTim=0;
	int totWaTim=0,TotaltuarTim=0;
    printf("\n\n\t\t\tOutput according to Longest remaining time Fist(LRTF)\n");
    printf("\n\t\t\t|===============================================================|");
    printf("\n\t\t\t|Student id\tFoodTakenTime\tWaitingTime\tTurnAroundTime  |");
    printf("\n\t\t\t|===============================================================|");    
    for (i = 0; i < s; i++)
    {
        printf("\n\t\t\t|%d\t\t%d\t\t%d\t\t%d\t\t|", list[i].StuId, list[i].FdTim,list[i].wTim,list[i].tuarTim);
        printf("\a\n\t\t\t|---------------------------------------------------------------|");
		totWaTim= totWaTim+list[i].wTim;
		TotaltuarTim= TotaltuarTim+list[i].tuarTim;
	} 
	printf("\n\n\t\t\tTotal Waiting Time is: = %d",totWaTim);
	printf("\n\t\t\tTotal Turn around Time is: = %d\n\n",TotaltuarTim);
	printf("\n\n\t\t\tAverage Waiting Time is: = %d",totWaTim/s);
	printf("\n\t\t\tAverage Turn around Time is: = %d\n\n",TotaltuarTim/s);
}

void scheduling(struct stu list[80], int s)
{
    int i, j;
    struct stu temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].FdTim < list[j + 1].FdTim)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
            else if(list[j].FdTim == list[j + 1].FdTim)
            {
            	if(list[j].StuId > list[j + 1].StuId)
            	{
            	temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                }
			}
        }
    }
}


void wTim(struct stu list[80], int n)
{
	int j,total;
    list[0].wTim=0;
    for(j=1;j<n;j++)
    {
        list[j].wTim=list[j-1].wTim+list[j-1].FdTim;
    }
}


void tuarTim(struct stu list[80], int n)
{
	int j,total;
    
    for(j=0;j<n;j++)
    {
        list[j].tuarTim=list[j].wTim+list[j].FdTim;
    }
}
