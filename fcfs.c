#include <stdio.h>
#include <stdlib.h>
typedef struct fcfs{
int p_id;
int at, ct, bt, tat, wt, rt;
} Process;
int comp(const void *a, const void *b){
return ((Process *)a)->at > ((Process *)b)->at;
}
int main(){
int n;
printf("Enter no. of process ");
scanf("%d", &n);
Process arr[n];
float idle = 0,waitingTime=0,responseTime=0;
for (int i = 0; i < n; i++){
printf("Enter arrival and bus time of process %d \n", i);
scanf("%d %d", &arr[i].at,&arr[i].bt);
}
qsort(arr, n, sizeof(Process), comp);
arr[0].ct =arr[0].at+ arr[0].bt;
arr[0].tat = arr[0].ct - arr[0].at;
arr[0].wt = arr[0].tat - arr[0].bt;
arr[0].rt = arr[0].at + arr[0].wt;
waitingTime+=arr[0].wt;
responseTime+=arr[0].rt;
for (int i = 1; i < n; i++){
if (arr[i - 1].ct < arr[i].at){
arr[i].ct = arr[i].at + arr[i].bt;
}
else
{
arr[i].ct = arr[i - 1].ct + arr[i].bt;
}
if (arr[i].at > arr[i - 1].ct) {
    idle = idle + arr[i].at - arr[i - 1].ct;
}
arr[i].tat = arr[i].ct - arr[i].at;
arr[i].wt = arr[i].tat - arr[i].bt;
arr[i].rt = arr[i].at + arr[i].wt;
waitingTime+=arr[i].wt;
responseTime+=arr[i].rt;
}
printf(" Arrival Time | Bus Time | Completion Time | Turn Around Time | Waiting Time | Response Time\n");
for (int i = 0; i < n; i++)
{
printf(" %d %d %d %d %d %d\n", arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
}
int cycleLength = arr[n-1].ct-arr[0].at;
float cpu_utlization = (((cycleLength - idle) / arr[n - 1].ct) * 100);
float averateWaitingTime=waitingTime/n;
float averateResponseTime=responseTime/n;
printf("Averate Response Time : %f \n", averateResponseTime);
printf("Average Waiting Time : %f \n", averateWaitingTime);
printf("IDLE TIME : %f \n", idle);
printf("CPU UTILIZATION : %f %%\n", cpu_utlization);
}