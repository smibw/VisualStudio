#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	int n,k,s;
	k = 0;
	s = 0;
	std::cout << "Введите размерность шахматной доски: "; cin >> n;
	for (int i = 0; i < n*n; i++)
	{
		s++;
		for (int j=0; j < n*n; j++)
		{
			if(s<=n)		k<n? std::cout << "* " : std::cout << "  ";
			else  k<n ? std::cout << "  " : std::cout << "* ";
			k++;
		if (k == n*2 ) k -= n*2 ;
		if (j == n * n - 1) k = 0;
		}
		std::cout << endl;
		if (s == n * 2) s -= n * 2;
	}
}