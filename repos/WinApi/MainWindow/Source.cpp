#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>

CONST INT g_INTERVAL = 5;
CONST INT g_BUTTON_SIZE = 50;
CONST INT g_DISPLAY_WIDTH = 400;
CONST INT g_DISPLAY_HEIGHT = 20;
CONST INT g_START_X = 10;
CONST INT g_START_Y = 10;

CONST CHAR gsz_MY_WINDOW_CLASS[] = "MyWindowClass";
CONST CHAR gsz_WINDOW_NAME[] = "My First Window";

INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//1) Регистрация класса окна
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));

	wc.cbSize = sizeof(wc);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = 0;
	wc.hIcon = (HICON)LoadImage(hInstance, "Message.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE,LR_LOADFROMFILE);
	wc.hIconSm = (HICON)LoadImage(hInstance, "Rocket.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);
	wc.hCursor = (HICON)LoadCursorFromFile("Block.ani");
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = gsz_MY_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
	}
	//2) Создание окна

	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);
	//int window_width = screen_width * 3 / 4;
	//int window_height = screen_width * 3 / 4;
	int window_width = g_START_X * 3.5 + (g_BUTTON_SIZE + g_INTERVAL) * 5;
	int window_height = g_START_Y + (g_BUTTON_SIZE + g_INTERVAL) * 4 + g_INTERVAL * 2 + 55;
	int start_x = screen_width / 8;
	int start_y = screen_height / 8;

	HWND hwnd = CreateWindowEx
	(
		NULL,	//ExStyle
		gsz_MY_WINDOW_CLASS,	//Class name
		gsz_WINDOW_NAME,		//Window name
		//WS_OVERLAPPEDWINDOW,	//dwStyle
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,	//dwStyle
		start_x, start_y,	//Начальная позиция окна
		window_width, window_height,	//Размер окна
		NULL,		//HWND родительского окна. У главного окна НЕТ родительского окна
		NULL,		//Menu отсутствует
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);	//Задает режим отображения окна( свернуто в окно, развернуто на весь экран, свернуто на панель задач и т.д.)
	UpdateWindow(hwnd);			// Прорисовывает содержимое окна
	//3) Запуск цикла сообщений
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
INT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:break;
	case WM_COMMAND:break;
	case WM_MOVE:
	{
		RECT rect;
		GetWindowRect(hwnd, &rect);
		CONST INT SIZE = 256;
		CHAR sz_buffer[SIZE] = {};
		sprintf(sz_buffer, "%s, Position:%dx%d, Size:%dx%d", gsz_WINDOW_NAME,
			rect.left, rect.top,
			rect.right - rect.left, rect.bottom - rect.top);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer);
	}		
		break;
	case WM_DESTROY: PostQuitMessage(0); break;
	case WM_CLOSE:
		switch (MessageBox(hwnd, "Вы действительно хотите закрыть окно", "Мне очень надо получить ответ", MB_YESNO | MB_ICONQUESTION))
		{
		case IDYES:
			MessageBox(hwnd, "Проваливай", "Даже окно закрыть не можешь нормально", MB_OK | MB_ICONINFORMATION);
			DestroyWindow(hwnd);
			break;
		}
		DestroyWindow(hwnd);
		break;
	default:return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}