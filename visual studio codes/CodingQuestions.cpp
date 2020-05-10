#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
/*
int main()
{
	int t; 
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		char str[100000];
		fflush(stdin);
		fgets(str, n, stdin);
		fflush(stdin);
		int m = 0, j = 1;
		for (int x = 0; x < n; x++)
		{
			if (str[x] == '1')
			{
				m = x;
				break;
			}
		}
		j = m + 1;
		while (j < n && k > 0)
		{
			if (str[j] == '0')
			{
				if (k > j - m)
				{
					swap(str[m], str[j]);
					k = k - j - m;
					i += 1;
				}
				else
				{
					swap(str[j], str[j - k]);
					k = 0;
					i += 1;
				}
			}
			j += 1;
		}
		cout << str << endl;
	}
}*/