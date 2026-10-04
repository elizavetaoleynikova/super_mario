/**
	- Какому паттерну проектирования соответствует UIFactory? - паттерн абстрактная фабрика
	- В каких случаях используется этот паттернн проектирования? - когда надо создавать семейства связанных объектов, 
	не привязывая код к конкретным классам. То есть если вдруг появится еще другая фабрика помимо Console, то создание
	объектов уровня можно будет не менять
*/

#pragma once

#include "game.hpp"
#include "game_map.hpp"
#include "mario.hpp"

namespace biv {
	class UIFactory {
		protected:
			Game* game = nullptr;
			
		protected:
			UIFactory(Game* game) : game(game) {}

		public:
			virtual void clear_data() = 0;
			virtual void create_box(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_enemy(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_jumpable_enemy(
				const Coord& top_left,
				const int width,
				const int height
			) = 0;

			virtual void create_flyable_enemy(
				const Coord& top_left,
				const int width,
				const int height
			) = 0;
			virtual void create_full_box(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_mario(
				const Coord& top_left, const int width, const int height) = 0;
			virtual void create_money(
				const Coord& top_left, const int width, const int height) = 0;
			
			virtual GameMap* get_game_map(const int height, const int width) = 0;
			virtual Mario* get_mario() = 0;

			virtual void create_moving_ship(
				const Coord& top_left,
				const int width,
				const int height,
				const float hspeed,
				const float left_border,
				const float right_border
			) = 0;

			virtual Rect* create_ship(
				const Coord& top_left,
				const int width,
				const int height
			) = 0;

			virtual void set_level_end_platform(Rect* obj) = 0;
	};
}
