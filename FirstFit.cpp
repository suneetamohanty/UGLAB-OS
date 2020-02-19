// C++ implementation of First - Fit algorithm
#include <bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];

                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
int main()
{
    int m;
    int n;
    cout << "Enter the number of process" << endl;
    cin >> n;
    int processSize[n];
    cout << "Enter the number of blocks" << endl;
    cin >> m;
    int blockSize[m];
    cout << "Enter the Size of each process" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }
    cout << "Enter the size of each block" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }
    firstFit(blockSize, m, processSize, n);
    return 0;
}
