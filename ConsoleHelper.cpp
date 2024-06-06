#include "pch.h"
#include "ConsoleHelper.h"



void ConsoleHelper::GetKeyBoardInput()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwMode = ENABLE_WINDOW_INPUT;
	SetConsoleMode(hStdin, fdwMode);

	DWORD cNumRead;
	INPUT_RECORD irInBuf[128];
	int32 counter = 0;

	while (true)
	{
		if (ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead))
		{
			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInBuf[i].EventType == KEY_EVENT)
				{
					KEY_EVENT_RECORD ker = irInBuf[i].Event.KeyEvent;
					if (ker.bKeyDown)
					{
						switch (ker.wVirtualKeyCode)
						{
						case VK_UP:
							cout << "Up arrow key pressed" << endl;
							break;
						case VK_DOWN:
							cout << "Down arrow key pressed" << endl;
							break;
						case VK_LEFT:
							cout << "Left arrow key pressed" << endl;
							break;
						case VK_RIGHT:
							cout << "Right arrow key pressed" << endl;
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}

void ConsoleHelper::SetConsoleColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<int16>(color));
}
