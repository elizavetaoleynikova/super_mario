/**
	- Зачем нужен этот файл? - определяет конретные типы и аргументы для шаблонной функции
	- Какие есть варианты реализации без такого подхода? -
	1) можно положить реализацию шаблона в format.hpp
	+ 
	это просто
	- 
	реализация доступна всем кто подключит hpp
	2) отдельные перегруженные функции
	+
	понятно, конкретные типы и аргументы
	-
	много дублирования
	- В чём + и - всех подходов?
*/

#include "format.hpp"
#include "format.cpp"

template std::string biv::format_string<int>(const std::string&, int);
template std::string biv::format_string<std::string>(const std::string&, std::string);
