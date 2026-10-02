#include "windows_control_settings.hpp"

#include <windows.h>

using biv::WindowsControlSettings;

void WindowsControlSettings::init() { // скрытие мигающего курсора
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);//текущее состояние курсора этой консоли идет в переменную
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

void WindowsControlSettings::set_cursor_start_position() { // перемещаем курсор
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
