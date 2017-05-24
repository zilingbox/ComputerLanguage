#include <Windows.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE L"�ڿ͵�������־"

//ȫ�ֺ�����������ֹδ�����ı�ʶϵ�д���
//���ڹ��̺���
LRESULT CALLBACK WndProc( HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam );

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//�����Ĳ���֮һ�����һ��������
	WNDCLASSEX wndClass = { 0 };//ʵ��һ��������
	wndClass.cbSize = sizeof(WNDCLASSEX);//���ýṹ����ֽ�����С
	wndClass.style = CS_HREDRAW | CS_VREDRAW;//���ô��ڵ���ʽ
	wndClass.lpfnWndProc = WndProc;//����ָ�򴰿ڹ��̺�����ָ��
	wndClass.cbClsExtra = 0;//������ĸ����ڴ棬ȡ0�Ϳ�����
	wndClass.cbWndExtra = 0;//���ڵĸ����ڴ棬Ҳȡ0����
	wndClass.hInstance = hInstance;//ָ���������ڹ��̵ĳ����ʵ�����
	wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.ico", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);//���ؼ����Զ���iconͼ��
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);//ָ��������Ĺ����
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);//ΪhbrBackground��Աָ��һ����ɫ��ˢ���
	wndClass.lpszMenuName = NULL;//��һ���Կ���ֹ���ַ�����ָ���˵���Դ������
	wndClass.lpszClassName = L"ForTheDreamOfGameDevelop";

	//�����Ĳ���֮����ע�ᴰ����
	if (!RegisterClassEx(&wndClass))
		return -1;

	//�����Ĳ���֮������ʽ��������
	HWND hwnd = CreateWindow(L"ForTheDreamOfGameDevelop", WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);


	//�����Ĳ���֮�ģ������ƶ�����ʾ�����
	MoveWindow(hwnd, 250, 80, WINDOW_WIDTH, WINDOW_HEIGHT, true);//����������ʾλ�ã��ô����ڣ�250��80��λ�ô�
	ShowWindow(hwnd, nShowCmd);//����ShowWindow��������ʾ����
	UpdateWindow(hwnd);


	//��Ϣѭ������
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	//�������ע��
	UnregisterClass(L"ForTheDreamOfGameDevelop", wndClass.hInstance);
	return 0;
}

//WinProc(������,���ڹ��̺������Դ�����Ϣ���д���
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