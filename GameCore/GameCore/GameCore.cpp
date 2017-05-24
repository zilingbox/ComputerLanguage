#include <Windows.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE L"黑客的自由意志"

//全局函数声明，防止未声明的标识系列错误
//窗口过程函数
LRESULT CALLBACK WndProc( HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam );

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//创建四部曲之一：设计一个窗口类
	WNDCLASSEX wndClass = { 0 };//实例一个窗口类
	wndClass.cbSize = sizeof(WNDCLASSEX);//设置结构体的字节数大小
	wndClass.style = CS_HREDRAW | CS_VREDRAW;//设置窗口的样式
	wndClass.lpfnWndProc = WndProc;//设置指向窗口过程函数的指针
	wndClass.cbClsExtra = 0;//窗口类的附加内存，取0就可以了
	wndClass.cbWndExtra = 0;//窗口的附加内存，也取0就行
	wndClass.hInstance = hInstance;//指定包含窗口过程的程序的实例句柄
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);//本地加载自定义icon图标
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//指定窗口类的光标句柄
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//为hbrBackground成员指定一个灰色画刷句柄
	wndClass.lpszMenuName = NULL;//用一个以空终止的字符串，指定菜单资源的名字
	wndClass.lpszClassName = L"ForTheDreamOfGameDevelop";

	//创建四部曲之二：注册窗口类
	if (!RegisterClassEx(&wndClass))
		return -1;

	//创建四部曲之三：正式创建窗口
	HWND hwnd = CreateWindow(L"ForTheDreamOfGameDevelop", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);


	//创建四部曲之四：窗口移动、显示与更新
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);//调整窗口显示位置，让窗口在（250，80）位置处
	ShowWindow(hwnd, nShowCmd);//调用ShowWindow函数来显示窗口
	UpdateWindow(hwnd);


	//消息循环过程
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	//窗口类的注销
	UnregisterClass(L"ForTheDreamOfGameDevelop", wndClass.hInstance);
	return 0;
}

//WinProc(）函数,窗口过程函数，对窗口信息进行处理
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
		ValidateRect(hwnd, NULL);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
			DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}