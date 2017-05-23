#include <Windows.h>
#pragma comment(lib,"winmm.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	PlaySound(L"camera.wav", NULL, SND_FILENAME | SND_ASYNC);
	MessageBox(NULL, L"你今天日常做了吗？", L"消息窗口", 0);
	return 0;
}