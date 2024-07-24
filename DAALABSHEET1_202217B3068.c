#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100000
#define MAX_TIME 1000
#define MAX_FINE 10000

typedef struct {
    int time; // time required to complete the job
    int fine; // fine for each day of delay
    int index; // original index of the job
} Job;

int compareJobs(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;

    long long ratio1 = (long long)job1->fine * job2->time;
    long long ratio2 = (long long)job2->fine * job1->time;

    if (ratio1 > ratio2) {
        return -1;
    } else if (ratio1 < ratio2) {
        return 1;
    } else {
        // If ratios are same, sort based on job index in ascending order
        return job1->index - job2->index;
    }
}

int main() {
    int N; // number of jobs
    scanf("%d", &N);

    Job jobs[N]; // array of jobs
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jobs[i].time, &jobs[i].fine);
        jobs[i].index = i + 1; // store the original index of the job
    }

    // Sort jobs based on the ratio of fine to time in descending order
    qsort(jobs, N, sizeof(Job), compareJobs);

    // Print the sequence of jobs
    for (int i = 0; i < N; i++) {
        printf("%d\n", jobs[i].index);
    }

    return 0;
}
