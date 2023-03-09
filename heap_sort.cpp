#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6;
double arr[10][MAX];
void heapify(int index, int N, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && arr[index][l] > arr[index][largest])
        largest = l;
    if (r < N && arr[index][r] > arr[index][largest])
        largest = r;
    if (largest != i) {
        swap(arr[index][i], arr[index][largest]);
        heapify(index, N, largest);
    }
}
void heapSort(int index, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(index, N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[index][0], arr[index][i]);
        heapify(index, i, 0);
    }
}
int main()
{
	clock_t start;
    vector <double> duration;
	freopen("text.inp","r",stdin);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			cin>>arr[i][j];
		}
	}
	start = clock();
	for (int i = 0; i < 10; ++i)
	{
		heapSort(i,MAX);
		// for (int j = 0; j < 10; ++j)
		// {
		// 	cout<<arr[i][j]<<' ';
		// }
		// cout<<endl;
		duration.push_back((clock() - start ) / (double) CLOCKS_PER_SEC);
		cout << "Time for array "<<i<<": "<<((i == 0) ? duration[i] : duration[i] - duration[i-1])<<"s\n";
	}
    return 0;
}