#include<stdio.h>
#define MAX 100
typedef struct {
    char id[5];
    int deadline, profit;
}Job;
int min(int a, int b) { return a < b ? a : b; }
void jobSeq(Job jobs[], int n) {
    int dmax = 0, profit = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > dmax) dmax = jobs[i].deadline;
    }
    int res[dmax + 1];
    for(int i = 1; i <= dmax; i++) res[i] = -1;
    for(int i = 0; i < n; i++) {
        for(int j = min(dmax, jobs[i].deadline); j >= 1; j--) {
            if(res[j] == -1) {
                res[j] = i;
                break;
            }
        }
    }
    printf("Selected Jobs : ");
    for(int i = 1; i <= dmax; i++) {
        if(res[i] != -1) {
            printf("%s ", jobs[res[i]].id);
            profit += jobs[res[i]].profit;
        }
    }
    printf("\nMax profit : %d\n",profit);
}
int main() {
    Job jobs[] = {
        {"j1", 2, 60}, {"j2", 1, 100}, {"j3", 3, 20},{"j4", 2, 40},{"j5", 1, 20}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    // sort
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    printf("Job\tDeadline\tPofit\n");
    for(int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    jobSeq(jobs, n);
    return 0;
}
