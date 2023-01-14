#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include"resource.h"

CONST CHAR* list[] = { "1","2","3" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		for (int i = 0; i < sizeof(list) / sizeof(list[0]); i++)
		{
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)list[i]);
		}
	}
	break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			HWND hList = GetDlgItem(hwnd,IDC_LIST1);
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			CHAR sz_output_buffer[SIZE] = {};
			int i = SendMessage(hList, LB_GETCURSEL, 0, 0);	
			SendMessage(hList, LB_GETTEXT, i, (LPARAM)sz_buffer);
			sprintf(sz_output_buffer, "Вы выбрали строку № %i со значением\"%s\"", i, sz_buffer);
			MessageBox(hwnd, sz_buffer, "Selected Item", MB_OK | MB_ICONINFORMATION);
		}
		case IDCANCEL:EndDialog(hwnd, 0); break;
		}
	}break;
	case WM_CLOSE:EndDialog(hwnd,0);
	}
	return FALSE;
}