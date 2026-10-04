/**
	- В стиле какого паттерна проектирования написан этот класс? - Это Singleton (Одиночка).
	- Почему здесь использован этот паттерн? - логгер должен быть единым для всей программы
	- Что такое LOG_INFO и для чего он сделан? - это макрос, позволяет сократить запись
	- Зачем в классе КпоУ и деструктор сделаны private, а КК, КП, ОПК, ОПП удалены? - так как логгер должен быть один и
	его нельзя удалить или создать снаружи
*/

#pragma once

#include <fstream>
#include <mutex>
#include <string>

#include "format.hpp"

#define LOG_INFO(...) biv::Logger::getInstance().log_info(biv::format_string(__VA_ARGS__))

namespace biv {
	class Logger {
		private:
			std::ofstream log_file;
			std::mutex log_mutex; 

			Logger();
			~Logger();

	public:
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		
		Logger(Logger&&) = delete;
		Logger& operator=(Logger&&) = delete;

		static Logger& getInstance();

		void log_info(const std::string& message);
	};
}
