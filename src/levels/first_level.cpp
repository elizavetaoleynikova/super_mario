#include "first_level.hpp"

#include "second_level.hpp"

using biv::FirstLevel;

FirstLevel::FirstLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* FirstLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::SecondLevel(ui_factory);
	}

	return next;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void FirstLevel::init_data() {

	
	ui_factory->create_mario({ 39, 10 }, 3, 3);

	ui_factory->create_ship({ 20, 25 }, 40, 2);

	ui_factory->create_full_box({ 30, 15 }, 5, 3);
	ui_factory->create_full_box({ 50, 15 }, 5, 3);

	ui_factory->create_moving_ship(
		{ 131, 23 },
		12,
		2,
		0.3f,
		130,
		150
	);

	ui_factory->create_ship({ 60, 20 }, 40, 7);

	ui_factory->create_box({ 60, 10 }, 10, 3);
	ui_factory->create_full_box({ 70, 10 }, 5, 3);
	ui_factory->create_box({ 75, 10 }, 5, 3);
	ui_factory->create_full_box({ 80, 10 }, 5, 3);
	ui_factory->create_box({ 85, 10 }, 10, 3);

	ui_factory->create_ship({ 100, 25 }, 20, 2);
	ui_factory->create_ship({ 120, 20 }, 10, 7);
	ui_factory->create_ship({ 150, 25 }, 40, 2);
	ui_factory->create_ship({ 210, 20 }, 15, 7);

	Rect* finish = ui_factory->create_ship({ 210, 20 }, 15, 7);
	ui_factory->set_level_end_platform(finish);

	ui_factory->create_enemy({ 25, 23 }, 3, 2);
	ui_factory->create_enemy({ 35, 23 }, 3, 2);

	ui_factory->create_enemy({ 70, 18 }, 3, 2);

	ui_factory->create_enemy({ 125, 18 }, 3, 2);
	ui_factory->create_enemy({ 160, 23 }, 3, 2);

	ui_factory->create_jumpable_enemy({ 21, 23 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 55, 23 }, 3, 2);
	ui_factory->create_jumpable_enemy({ 155, 23 }, 3, 2);

	ui_factory->create_flyable_enemy({ 95, 10 }, 3, 2);
	ui_factory->create_flyable_enemy({ 175, 12 }, 3, 2);
	ui_factory->create_flyable_enemy({ 195, 7 }, 3, 2);

}