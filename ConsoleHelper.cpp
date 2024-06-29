#include "pch.h"
#include "ConsoleHelper.h"


ConsoleHelper::~ConsoleHelper()
{
}

void ConsoleHelper::Init()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_curBufferIdx = 0;

	CONSOLE_CURSOR_INFO consoleCursor{ 1, FALSE };
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, };
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	consoleInfo.dwSize.X = 40;
	consoleInfo.dwSize.Y = 30;

	rtConsole.Width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
	rtConsole.Height = consoleInfo.srWindow.Top - consoleInfo.srWindow.Bottom;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], consoleInfo.dwSize);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &consoleInfo.srWindow);
	SetConsoleCursorInfo(hBuffer[0], &consoleCursor);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], consoleInfo.dwSize);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &consoleInfo.srWindow);
	SetConsoleCursorInfo(hBuffer[1], &consoleCursor);
}

void ConsoleHelper::Destory()
{
	if (hBuffer[0] != nullptr)
	{
		CloseHandle(hBuffer[0]);
	}

	if (hBuffer[1] != nullptr)
	{
		CloseHandle(hBuffer[1]);
	}
}

void ConsoleHelper::ClearScreen()
{
	COORD pos{ 0,0 };
	DWORD dwWritten = 0;
	uint32 size = rtConsole.Width * rtConsole.Height;

	FillConsoleOutputCharacter(hConsole, ' ', size, pos, &dwWritten);
	SetConsoleCursorPosition(hConsole, pos);
}

void ConsoleHelper::BufferFlip()
{
	SetConsoleActiveScreenBuffer(hBuffer[_curBufferIdx]);
	_curBufferIdx = _curBufferIdx ? 0 : 1;
}



void ConsoleHelper::GetKeyBoardInput()
{
	//HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	//DWORD fdwMode = ENABLE_WINDOW_INPUT;
	//SetConsoleMode(hStdin, fdwMode);

	//DWORD cNumRead;
	//INPUT_RECORD irInBuf[128];
	//int32 counter = 0;

	//while (true)
	//{
	//	if (ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
	//	{
	//		for (DWORD i = 0; i < cNumRead; i++)
	//		{
	//			if (irInBuf[i].EventType == KEY_EVENT)
	//			{
	//				KEY_EVENT_RECORD ker = irInBuf[i].Event.KeyEvent;
	//				if (ker.bKeyDown)
	//				{
	//					switch (ker.wVirtualKeyCode)
	//					{
	//					case VK_UP:
	//						cout << "Up arrow key pressed" << endl;
	//						break;
	//					case VK_DOWN:
	//						cout << "Down arrow key pressed" << endl;
	//						break;
	//					case VK_LEFT:
	//						cout << "Left arrow key pressed" << endl;
	//						break;
	//					case VK_RIGHT:
	//						cout << "Right arrow key pressed" << endl;
	//						break;
	//					default:
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
}

void ConsoleHelper::SetConsoleColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<int16>(color));
}