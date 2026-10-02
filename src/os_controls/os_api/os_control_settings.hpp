#pragma once // подключить один раз 

namespace biv {
	class OSControlSettings {
		public:
			virtual void init() = 0; // у этого класса нет реализации init(). Каждый конкретный класс-наследник должен её предоставить.
			virtual void set_cursor_start_position() = 0; // виртуальный метод без реализации
	};
}
