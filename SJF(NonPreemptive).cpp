#include <iostream>
#include <algorithm>
using namespace std;
struct pro
{
    int index;
    int bursttime;
    int waitingtime;
};
bool comp(pro a, pro b)
{
    return a.bursttime < b.bursttime;
}
int main()
{
    int n;
    cout << "Enter the number of process"
         << "\n";
    cin >> n;
    struct pro process[n];
    cout << "Enter the burst time of each process"
         << "\n";
    for (int i = 0; i < n; i++)
    {
        process[i].index = i + 1;
        process[i].waitingtime = 0;
        cin >> process[i].bursttime;
    }
    cout << "Arrival Time of all the process is considered as zero in Non Preemptive SJF" << endl;
    cout << "Process"
         << "\t"
         << "Arrival Time"
         << "\t"
         << "Burst Time"
         << "\t"
         << "Waiting Time"
         << "\n";
    sort(process, process + n, comp);
    process[0].waitingtime = 0;
    int waitsum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            process[i].waitingtime = process[i - 1].bursttime + process[i - 1].waitingtime;
        }

        cout << "P" << process[i].index << "\t"
             << "0"
             << "\t\t" << process[i].bursttime << "\t\t" << process[i].waitingtime << "\n";
        waitsum += process[i].waitingtime;
    }
    cout << "Average Waiting Time:-" << waitsum / n << endl;
    cout << "Order of execution:-" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "p" << process[i].index << "->";
    }
    cout << "p" << process[n - 1].index << "\n";
    return 0;
}