/**
	- К какому виду функций принадлежит 
		format_string(const std::string& format, T first, Args... rest)? - шаблонная функция с переменным количеством параметров
	- В чём + и - таких функций?
	+ 
	можно работать с разным количеством аргументов и их типами
	-
	более сложная реализация, ошибки при компиляции возможны
	- Что такое Args...? - хранит типы всех оставшихся аргументов
*/

#include "format.hpp"

#include <iostream>
#include <sstream>

std::string biv::format_string(const std::string& format) {
	return format;
}

template<typename T, typename... Args>
std::string biv::format_string(const std::string& format, T first, Args... rest) {
	std::ostringstream oss;
	oss << first;
	std::string first_str = oss.str();
	
	std::size_t pos = format.find("{}");
	if (pos != std::string::npos) {
		std::string result = format.substr(0, pos) + first_str + format.substr(pos + 2);
		return format_string(result, rest...);
	} else {
		return format;
	}
}
