#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void print_gantt_chart(int p[], int n);
int p[MAX],n,
bt[MAX],wt[MAX],tat[MAX],r[50];
int k=0,quantum=0;
// Function to calculate turn around time
int turnarroundtime(int p[], int n,
int bt[], int wt[], int tat[]) {
   // calculating turnaround time by adding
   // bt[i] + wt[i]
   for (int i = 0; i < n ; i++)
   tat[i] = bt[i] + wt[i];
   return 1;
}
// Function to find the waiting time for all
// processes
int waitingtime(int p[], int n,
int bt[], int wt[], int quantum) {
   // Make a copy of burst times bt[] to store remaining
   // burst times.
   int rem_bt[n];
   for (int i = 0 ; i < n ; i++)
   rem_bt[i] = bt[i];
   int t = 0; // Current time
   // Keep traversing processes in round robin manner
   // until all of them are not done.

   while (1) {
      int done = 1;
      // Traverse all processes one by one repeatedly
      for(int i = 0 ; i < n; i++) {
         // If burst time of a process is greater than 0
         // then only need to process further
         if(rem_bt[i] > 0) {
            done = 0; // There is a pending process
            if(rem_bt[i] > quantum) {
               // Increase the value of t i.e. shows
               // how much time a process has been processed
               r[k]=p[i];
               k++;
               t += quantum;
               // Decrease the burst_time of current process
               // by quantum
               rem_bt[i] -= quantum;
            }
            // If burst time is smaller than or equal to
            // quantum. Last cycle for this process
            else {
               // Increase the value of t i.e. shows
               // how much time a process has been processed
               t = t + rem_bt[i];
               // Waiting time is current time minus time
               // used by this process
               wt[i] = t - bt[i];
               // As the process gets fully executed
               // make its remaining burst time = 0
               rem_bt[i] = 0;
            }
         }
      }
      // If all processes are done
      if (done == 1)
         break;
   }
   return 1;
}
// Function to calculate average time
int findavgTime(int p[], int n, int bt[],
int quantum) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   // Function to find waiting time of all processes
   waitingtime(p, n, bt, wt, quantum);
   // Function to find turn around time for all processes
   turnarroundtime(p, n, bt, wt, tat);
   // Display processes along with all details
   int i;

    printf("+-----+------------+--------------+-----------------+\n");
    printf("| PID | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("+-----+------------+--------------+-----------------+\n");

    for(i=0; i<n; i++) {
    printf("| %d   |    %d       |      %d        |        %d        |\n"
               , p[i], bt[i], wt[i], tat[i]);
        printf("+-----+------------+--------------+-----------------+\n");
    }
    print_gantt_chart(p,n);

   for (int i=0; i<n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
   }
   printf("Average waiting time = %f", (float)total_wt / (float)n);
   printf("\nAverage turnaround time = %f\n", (float)total_tat / (float)n);
   return 1;
}
void print_gantt_chart(int p[], int n)
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=0; i<k; i++) {
        for(j=0; j<=quantum; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<k; i++) {
        for(j=0; j<quantum; j++) printf(" ");
        printf("P%d", r[i]);
        for(j=0; j<quantum; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // printing bottom bar
    for(i=0; i<k; i++) {
        for(j=0; j<=quantum; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    // printing the time line
    int h=0;
    printf("0");
    int q=k+1;
    for(i=0; i<k; i++) {
            if(h<10)
            {
                for(j=0; j<=quantum; j++) printf("  ");
                q--;
                h=h+quantum;
                printf("%d",h);

            }
            else{

            }
    printf("\n");

}
// main function
int main() {
    int i, j;

    printf("Enter total number of process:");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        p[i]= i;
        printf("P[%d] : ", i);
        scanf("%d", &bt[i]);
        wt[i]=tat[i]=0;
    }
    printf("Enter the quantum size");
    scanf("%d",&quantum);
   int quantum = 2;
   findavgTime(p, n, bt, quantum);
   return 0;
}
