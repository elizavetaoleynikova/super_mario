/**
	- Почему класс Rect наследуется виртуальным образом? - Из-за множественного наследования и
	возможного появления нескольких копий Rect

	- Что такое паттерн адаптер? - совмещает два класса с несовместимыми интерфейсами, не ихменяя их
	- Для чего он применяется здесь? - Чтобы геометрический объект мог перемещаться по карте
	- Какую ещё роль выполняет этот класс? - адаптер задает движение по карте, наследникам не надо реализовывать его
*/

#pragma once

#include "map_movable.hpp"
#include "rect.hpp"

namespace biv {
	class RectMapMovableAdapter : virtual public Rect, public MapMovable {
		public:
			RectMapMovableAdapter(const Coord& top_left, const int width, const int height);
			
			void move_map_left() noexcept override;
			void move_map_right() noexcept override;
	};
}
