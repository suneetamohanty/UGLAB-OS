// CPP program to implement preemptive priority scheduling
#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int processID;
    int burstTime;
    int tempburstTime;
    int responsetime;
    int arrivalTime;
    int priority;
    int outtime;
    int intime;
};
void insert(Process Heap[], Process value, int *heapsize, int *currentTime)
{
    int start = *heapsize, i;
    Heap[*heapsize] = value;
    if (Heap[*heapsize].intime == -1)
        Heap[*heapsize].intime = *currentTime;
    ++(*heapsize);

    while (start != 0 && Heap[(start - 1) / 2].priority > Heap[start].priority)
    {
        Process temp = Heap[(start - 1) / 2];
        Heap[(start - 1) / 2] = Heap[start];
        Heap[start] = temp;
        start = (start - 1) / 2;
    }
}
void order(Process Heap[], int *heapsize, int start)
{
    int smallest = start;
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    if (left < *heapsize && Heap[left].priority < Heap[smallest].priority)
        smallest = left;
    if (right < *heapsize && Heap[right].priority < Heap[smallest].priority)
        smallest = right;
    if (smallest != start)
    {
        Process temp = Heap[smallest];
        Heap[smallest] = Heap[start];
        Heap[start] = temp;
        order(Heap, heapsize, smallest);
    }
}
Process extractminimum(Process Heap[], int *heapsize, int *currentTime)
{
    Process min = Heap[0];
    if (min.responsetime == -1)
        min.responsetime = *currentTime - min.arrivalTime;
    --(*heapsize);
    if (*heapsize >= 1)
    {
        Heap[0] = Heap[*heapsize];
        order(Heap, heapsize, 0);
    }
    return min;
}
bool compare(Process p1, Process p2)
{
    return (p1.arrivalTime < p2.arrivalTime);
}
void scheduling(Process Heap[], Process array[], int n, int *heapsize, int *currentTime)
{
    if (heapsize == 0)
        return;

    Process min = extractminimum(Heap, heapsize, currentTime);
    min.outtime = *currentTime + 1;
    --min.burstTime;
    printf("process id = %d current time = %d\n", min.processID, *currentTime);
    if (min.burstTime > 0)
    {
        insert(Heap, min, heapsize, currentTime);
        return;
    }

    for (int i = 0; i < n; i++)
        if (array[i].processID == min.processID)
        {
            array[i] = min;
            break;
        }
}
void priority(Process array[], int n)
{
    int *tTime;
    sort(array, array + n, compare);
    int totalwaitingtime = 0, totalbursttime = 0, totalturnaroundtime = 0, i, insertedprocess = 0,
        heapsize = 0, currentTime = array[0].arrivalTime,
        totalresponsetime = 0;
    Process Heap[4 * n];
    for (int i = 0; i < n; i++)
    {
        totalbursttime += array[i].burstTime;
        array[i].tempburstTime = array[i].burstTime;
    }
    do
    {
        if (insertedprocess != n)
        {
            for (i = 0; i < n; i++)
            {
                if (array[i].arrivalTime == currentTime)
                {
                    ++insertedprocess;
                    array[i].intime = -1;
                    array[i].responsetime = -1;
                    insert(Heap, array[i], &heapsize, tTime);
                }
            }
        }
        scheduling(Heap, array, n, &heapsize, tTime);
        ++currentTime;
        if (heapsize == 0 && insertedprocess == n)
            break;
    } while (1);

    for (int i = 0; i < n; i++)
    {
        totalresponsetime += array[i].responsetime;
        totalwaitingtime += (array[i].outtime - array[i].intime - array[i].tempburstTime);
        totalbursttime += array[i].burstTime;
    }
    printf("Average waiting time = %f\n", ((float)totalwaitingtime / (float)n));
    printf("Average response time =%f\n", ((float)totalresponsetime / (float)n));
    printf("Average turn around time = %f\n", ((float)(totalwaitingtime + totalbursttime) / (float)n));
}
int main()
{
    int n, i;
    cout << "Enter no of processes" << endl;
    cin >> n;
    Process a[n];
    cout << "Enter Arrival Time of each processes" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].processID = i + 1;
        cin >> a[i].arrivalTime;
    }
    cout << "Enter Priority of each process" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].priority;
    }
    cout << "Enter Burst Time of each process" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].burstTime;
    }
    priority(a, 5);
    return 0;
}
