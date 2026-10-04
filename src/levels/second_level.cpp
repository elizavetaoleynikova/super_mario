#include "second_level.hpp"

#include "third_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool SecondLevel::is_final() const noexcept {
	return false;
}

biv::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ThirdLevel(ui_factory);
	}

	return next;
}

// ----------------------------------------------------------------------------
//                                  PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {

	ui_factory->create_mario({ 10, 10 }, 3, 3);

	ui_factory->create_ship({ 0, 25 }, 35, 2);
	ui_factory->create_ship({ 42, 20 }, 10, 2);
	ui_factory->create_ship({ 58, 15 }, 8, 2);
	ui_factory->create_ship({ 72, 20 }, 10, 2);
	ui_factory->create_ship({ 150, 25 }, 30, 2);
	ui_factory->create_ship({ 185, 21 }, 12, 2);
	ui_factory->create_ship({ 202, 18 }, 12, 2);

	ui_factory->create_box({ 45, 14 }, 5, 3);
	ui_factory->create_box({ 65, 14 }, 5, 3);
	ui_factory->create_box({ 205, 12 }, 5, 3);


	ui_factory->create_enemy({ 12, 22 }, 3, 2);
	ui_factory->create_enemy({ 45, 17 }, 3, 2);
	ui_factory->create_enemy({ 155, 22 }, 3, 2);
	ui_factory->create_enemy({ 187, 18 }, 3, 2);
	ui_factory->create_enemy({ 230, 22 }, 3, 2);
	ui_factory->create_enemy({ 245, 22 }, 3, 2);


	ui_factory->create_jumpable_enemy({ 25, 22 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 35, 22 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 48, 17 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 72, 17 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 165, 22 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 190, 18 }, 3, 2);


	ui_factory->create_flyable_enemy({ 20, 10 }, 3, 2);
	ui_factory->create_flyable_enemy({ 55, 8 }, 3, 2);
	ui_factory->create_flyable_enemy({ 85, 12 }, 3, 2);
	ui_factory->create_flyable_enemy({ 140, 10 }, 3, 2);
	ui_factory->create_flyable_enemy({ 180, 8 }, 3, 2);
	ui_factory->create_flyable_enemy({ 215, 10 }, 3, 2);


	ui_factory->create_moving_ship({ 90, 22 }, 12, 2, 0.3f, 82, 150);


	ui_factory->create_full_box({ 190, 15 }, 5, 3);
	ui_factory->create_full_box({ 55, 10 }, 5, 3);


	// Финишная платформа
	Rect* finish = ui_factory->create_ship({ 220, 25 }, 40, 2);

	ui_factory->set_level_end_platform(finish);
}