/*
	Windows API
	API-Application Programming Interface
		(Прикладной интерфейс программиста)
	это набор функицй и других готовых инструментов для разработки приложений
*/
#include<Windows.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//#define MSG_BOX

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
// INT - тип возвращаемого значения 
// WINAPI - соглашение о вызове функции(Calling convention)
// Calling convention определяет какая функция очищает стек, вызывающая или вызываемая,
// а также определяет, как параметры передаются в функцию
// для обычных C/C++ приложений по умолчанию используются конвенция __cdecl,
// в WinApi всегда используется конвенция __stdcall
// caller - вызывающая функция(функция, которая вызывает другую функцию)
// callee - вызываемая функция(функция, которую вызывают)
{
	/*
		hInstance - *.exe-файл программы
		hPrevInst - прудыдущий экзепляр программы
		lpCmdLine - командная строка, которую приложение получает при запуске.
					Если это текстовый редактор, то в него можно передать открываемый файл,
					если это браузер, то в него можно передать загружаемую страницу и т.д.
					Командная строка представляет собой массив строк, нулевым элементом которого
					всегда является имя *.exe-файла.
					lp - long pointer(Венгерская нотация)
		nCmdShow -	режим отображения окна при запуске(развернуто на весь экран, свернуто в окно,
					свернуто на панель задач и т.д.)
					n - number (Венгерская нотация)
	*/
#ifdef MSG_BOX
	MessageBox(
		NULL,
		"Привет! Это наше первое сообщение",
		"Заголовок окна сообщения",
		MB_YESNOCANCEL | MB_HELP |  // Набор кнопок
		MB_ICONINFORMATION |		 // Значок
		MB_DEFBUTTON3 |			 // Кнопка по умолчанию
		MB_SYSTEMMODAL);		 // WS_EX_TOPMOST - поверх всех окон
	// IDYES IDNO  
#endif // MSG_BOX

	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);

	return 0;
}
/*
	У каждого окна есть своя процедура окна - это функция, которая вызывается при запуске окна
	и обрабатывает все действия связанные с этим окном.
	Любая процедура окна принимает 4 параметра:
	1. Окно
	2. Сообщение
	3, 4 Параметры сообщения
	Одна и та же процедура окна может использоваться сразу для нескольких окон

*/

CONST CHAR gsz_LOGIN_INVITATION[] = "Введите имя пользователя";
CONST CHAR gsz_PASSWORD_INVITATION[] = "Введите пароль";

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hicon = LoadIcon(GetModuleHandle(NULL), (LPSTR)IDI_ICON1);
		SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hicon);

		// Получаем обработчики окна текстовых полей
		// HWND - Handler to Window(Обработчик окна)
		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN1);
		HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD1);

		// Для того, чтобы установить текст в окна hEditLogin1 и hEditPassword1,
		// нужно отправить сообщение этим сообщениям
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)gsz_LOGIN_INVITATION);
		SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)gsz_PASSWORD_INVITATION);
	}
		break;					// нужен для создания элементов окна
	case WM_COMMAND:			// Обработка комманд нажатия кнопок
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN1:
		{
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN1);
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				if(strcmp(sz_buffer,gsz_LOGIN_INVITATION)==0)
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			}
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
					if (strlen(sz_buffer) == 0)
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)gsz_LOGIN_INVITATION);
			}
		}
		break;
		case IDC_BUTTON_COPY:
		{
			//Создаем буфер, через который будет производиться копирование:
			CONST INT SIZE = 256;
			CHAR buffer[SIZE] = {};
			//Получаем окна тактовых полей, для того, чтобы им можно было отправлять сообщения
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN1);
			HWND hEditPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD1);
			//Читаем содержимое тектового поля LOGIN:
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)buffer);
			//Загружаем текст из буфера в поле PASSWORD:
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)buffer);
		}
		break;
		case IDOK:MessageBox(NULL, "Была нажата кнопка ОК", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:EndDialog(hwnd, 0);
		}
		break;		
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}
/*
	1. hwnd - окно
	2. uMsg - сообщение
	3. wParam - Параметры сообщения
	4. lParam
*/