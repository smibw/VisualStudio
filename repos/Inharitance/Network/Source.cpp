#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");

	char number[10] = {};
	char src_filename[_MAX_FNAME] = {};
	char wal_filename[_MAX_FNAME] = {};
	char dhcpd_filename[_MAX_FNAME] = {};
	std::cout << "¬ведите номер аудитории: "; std::cin >> number;
	strcat(src_filename, number);
	strcat(src_filename, " Raw.txt");

	strcat(wal_filename, number);
	strcat(wal_filename, " ready.txt");

	strcat(dhcpd_filename, number);
	strcat(dhcpd_filename, ".dhcpd");

	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;

	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};

	ofstream fout(wal_filename);
	ifstream fin(src_filename);
	
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			std::cout << sz_ip_buffer << "\t\t" << sz_mac_buffer << std::endl;
			fout << sz_ip_buffer << "\t\t" << sz_mac_buffer << std::endl;
		}
		//fin.close();
	}
	else
	{
		cerr << "Error: File not found" << std::endl;
	}

	fout.close();
	char sz_command[_MAX_FNAME] ="notepad ";
	strcat(sz_command, wal_filename);

	system(sz_command);

	fin.clear();
	fin.seekg(0);
	std::cout << fin.tellg();
	std::cout << std::endl;
	fout.open(dhcpd_filename);

	if (fin.is_open())
	{
		for (int i = 1; (!fin.eof());i++)	
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (sz_ip_buffer[0] == 0 || sz_mac_buffer == 0)continue;
			for (int i = 0; sz_mac_buffer[i]; i++)
				if (sz_mac_buffer[i] == '-') sz_mac_buffer[i] = ':';
			std::cout<<"host " << number << "-" << i << std::endl;
			std::cout << "{\n";
			std::cout << "\thardware ethernet\t"<<sz_mac_buffer<<";\n";
			std::cout << "\tfixed-adress\t" << sz_ip_buffer << ";\n";
			std::cout << "}\n";

			fout <<"host " << number << "-" << i << std::endl;
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			fout << "\tfixed-adress\t" << sz_ip_buffer << ";\n";
			fout << "}\n";
		}
		fin.close();
	}
	else
	{
		std::cerr <<"Error: File not found" << std::endl;
	}
	strcpy(sz_command + strlen("notepad "), dhcpd_filename);
	system(sz_command);
}