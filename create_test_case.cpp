#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;
double randomm()
{
	int int_part = rand(), dec_part = rand();
	return (double)int_part/dec_part;
}
void increase()
{
	double x = 0;
	for (int i = 0; i < MAX; ++i)
	{
		x += randomm();
		cout<<x<<' ';
	}
	cout<<endl;
}
void decrease()
{
	double x = rand() % 10;
	for (int i = 0; i < MAX; ++i)
	{
		x -= randomm();
		cout<<x<<' ';
	}
	cout<<endl;
}
int main()
{
	freopen("text.inp","w",stdout);
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		if (i == 0) increase();
		else if (i == 1) decrease();
		else 
		{
			for(int j = 0; j < MAX; j++)
				cout<<randomm()<<' ';
			cout<<endl;
		}
	}
	return 0;
}