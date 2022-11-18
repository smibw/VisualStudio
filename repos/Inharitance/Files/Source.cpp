#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;		//1) ������� �����
	fout.open("File.txt", std::ios::app);	//2) ��������� �����
	//std::ios::app - append, �� ������������� ����, � ���������� � ����� �����.
	fout << "Hello Files!" << endl;//3) ����� � �����:
	fout.close();			//4) ��������� �����

	system("notepad File.txt");	//������� system() ��������� ����� ��������� � ������� ���� PATH � Windows
	//system("start qmmp.exe");  
#endif // WRITE_TO_FILE

	ifstream fin("File.txt");	//����� ����������� ����� ��� ��������
	if (fin.is_open())
	{
		//����� ������ ����
		const int SIZE = 1024;
		char buffer[SIZE] = {};
		//cout << typeid(fin.tellg()).name() << endl;
		//std::fpos<_Mbstatet> pos = fin.tellg();
		while (!fin.eof())
		{
			//fin >> buffer;
			//cout << fin.tellg() << "\t";
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		cout << fin.tellg() << "\n";	//���������� ������� �������
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
}