#include <Windows.h>
#define width 640
#define height 480

static int count = 0;		// статическая перемена для подсчета количества дополнительных окон
WNDCLASSEX windowClass;		// Создали экземпляр класса
HWND window_mass[5];		// Дополнительный массив окон(дескриптор)
HWND hWindow;				// Наше главное окно
HINSTANCE hInst;			// дескриптор инфстанции
wchar_t counterString[1];

LRESULT APIENTRY WndProc(HWND hWnd, UINT UMsg, WPARAM wParam, LPARAM lParams);		// Функция обработки сообщений
ATOM	MyRegisterClass(WNDCLASSEX& MyWnd,HINSTANCE hInstance);						// Функция инициализации регистрирации класса окна.
BOOL	InitInstance(WNDCLASSEX windowClass, HINSTANCE hInstance, int nCmdShow);	// Фунция создания окна

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	MSG uMsg;
	BOOL bRet;

	MyRegisterClass(windowClass,hInstance);					// Инициализация + Регистрируем класс
	if (!InitInstance(windowClass, hInstance, nCmdShow))
		return FALSE;

	while ((bRet = GetMessage(&uMsg,hWindow , 0, 0)) != 0)
	{
		if (bRet == -1)
		{
			break;
		}
		else
		{
			TranslateMessage(&uMsg);
			DispatchMessage(&uMsg);
		}
	}

	return 0;
};

LRESULT APIENTRY WndProc(HWND hWnd, UINT UMsg, WPARAM wParam, LPARAM lParam)
{ 
	switch (UMsg)
	{
	case WM_RBUTTONDOWN://функция создания доп.окон по нажатию ПКМ
	{

		if (count < 5)
		{
			wsprintfW(counterString, L"%d", count + 1);
			SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
			window_mass[count] = CreateWindow(windowClass.lpszClassName, counterString, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, NULL,
				CW_USEDEFAULT, NULL, nullptr, nullptr, hInst, nullptr);
			ShowWindow(window_mass[count], 1);
			count++;
		}
		else
		{
			MessageBox(hWnd, L"Максимум пять окон", L"Ошибка !", MB_OKCANCEL | MB_ICONASTERISK);
		}
		break;
	}
	// Дейтсвия при нажатии левой клавиши мыши( текст + message box )
	case WM_LBUTTONDOWN:	SetWindowPos(hWnd, HWND_BOTTOM, 100, 100 , 300 , 300 , SWP_NOMOVE);
							SetWindowTextA(hWnd, "NEW WINDOW TEXT!");
							break;
	case WM_DESTROY://уничтожение окна
	{
		MessageBoxA(hWnd, "SAY HELLO!!!!", "My Message Box WINDOW!!!!", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON1);
		PostQuitMessage(WM_QUIT);
		break;
	}
	case WM_CHAR:
	{
		if (count > 0)
		{
			DestroyWindow(window_mass[count - 1]);
			count--;
		}
		break;
	}

	default:				return DefWindowProc(hWnd, UMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, UMsg, wParam, lParam);
}
ATOM	MyRegisterClass(WNDCLASSEX& MyWnd,HINSTANCE hInstance)
{
	hInst = hInstance;
	memset(&MyWnd, 0, sizeof(WNDCLASSEX));

	MyWnd.cbSize = sizeof(WNDCLASSEX);
	MyWnd.style = CS_HREDRAW | CS_VREDRAW;
	MyWnd.lpfnWndProc = WndProc;
	MyWnd.hInstance = hInstance;
	MyWnd.hIcon = LoadIcon(hInstance, IDI_SHIELD);
	MyWnd.hCursor = LoadCursor(NULL, IDC_HAND);
	MyWnd.hbrBackground = (HBRUSH)GetStockObject(DEVICE_DEFAULT_FONT);
	MyWnd.lpszClassName = L"My Window";
	MyWnd.lpszMenuName = L"Menu name";

	return RegisterClassEx(&MyWnd);
}
BOOL InitInstance(WNDCLASSEX windowClass,HINSTANCE hInstance, int nCmdShow)
{
	HINSTANCE hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

	hWindow = CreateWindow(windowClass.lpszClassName, L"My First C++ Trainer",								// Создали главное окно
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		(GetSystemMetrics(SM_CXSCREEN) - width) / 2, ((GetSystemMetrics(SM_CYSCREEN) - height) / 2),
		width, height, NULL, NULL, NULL, NULL);
	//создает перекрывающее, выскакивающее или дочернее окно. 
	//LPCTSTR lpClassName,   // указатель на зарегистрированное имя класса
	//LPCTSTR lpWindowName,  // указатель на имя окна
	//DWORD dwStyle,         // стиль окна
	//int x,                 // горизонтальная позиция окна
	//int y,                 // вертикальная позиция окна
	//int nWidth,            // ширина окна
	//int nHeight,           // высота окна
	//HWND hWndParent,       // дескриптор родительского или окна владельца
	//HMENU hMenu,           // дескриптор меню или ID дочернего окна
	//HANDLE hInstance,      // дескриптор экземпляра приложения
	//LPVOID lpParam         // указатель на данные создания окна
	

	if (!hWindow)
	{
		return FALSE;
	}

	ShowWindow(hWindow, nCmdShow);//устанавливает состояние показа определяемого окна, дескриптор окна, состояние показа окна
	UpdateWindow(hWindow);//обновляет клиентскую область указанного окна

	return TRUE;
}

