#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

// ----------------------------------------------------------------------------
//                                  PROTECTED
// ----------------------------------------------------------------------------
void ThirdLevel::init_data() {
    // Марио
    ui_factory->create_mario({ 10, 20 }, 3, 3);

    // ------------------------------------------------------------
    // 1. Стартовая платформа
    // ------------------------------------------------------------
    ui_factory->create_ship({ 0, 25 }, 30, 2);

    ui_factory->create_enemy({ 18, 22 }, 3, 2);
    ui_factory->create_enemy({ 24, 22 }, 3, 2);

    // ------------------------------------------------------------
    // 2. Первый подъём
    // ------------------------------------------------------------
    ui_factory->create_ship({ 38, 21 }, 10, 2);
    ui_factory->create_ship({ 53, 17 }, 10, 2);
    ui_factory->create_ship({ 68, 21 }, 10, 2);

    ui_factory->create_jumpable_enemy({ 40, 18 }, 3, 3);
    ui_factory->create_enemy({ 55, 14 }, 3, 2);
    ui_factory->create_enemy({ 70, 18 }, 3, 2);

    // Блоки между платформами
    ui_factory->create_box({ 42, 14 }, 4, 3);
    ui_factory->create_full_box({ 57, 10 }, 4, 3);
    ui_factory->create_box({ 72, 14 }, 4, 3);

    // ------------------------------------------------------------
    // 3. Большая средняя площадка
    // ------------------------------------------------------------
    ui_factory->create_ship({ 83, 25 }, 30, 2);

    ui_factory->create_enemy({ 88, 22 }, 3, 2);
    ui_factory->create_jumpable_enemy({ 100, 21 }, 3, 3);
    ui_factory->create_enemy({ 112, 22 }, 3, 2);

    // Верхние блоки
    ui_factory->create_full_box({ 90, 17 }, 5, 3);
    ui_factory->create_box({ 100, 17 }, 5, 3);
    ui_factory->create_full_box({ 110, 17 }, 5, 3);

    // ------------------------------------------------------------
    // 4. Узкий участок
    // ------------------------------------------------------------
    ui_factory->create_ship({ 122, 20 }, 8, 2);
    ui_factory->create_ship({ 135, 16 }, 7, 2);
    ui_factory->create_ship({ 147, 21 }, 8, 2);

    ui_factory->create_enemy({ 124, 17 }, 3, 2);
    ui_factory->create_jumpable_enemy({ 136, 13 }, 3, 3);
    ui_factory->create_enemy({ 150, 18 }, 3, 2);

    // Блоки
    ui_factory->create_box({ 126, 12 }, 4, 3);
    ui_factory->create_full_box({ 138, 8 }, 4, 3);
    ui_factory->create_box({ 151, 13 }, 4, 3);

    // ------------------------------------------------------------
    // 5. Движущаяся платформа
    // ------------------------------------------------------------
    // Левая платформа заканчивается на x = 155.
    // Правая начинается на x = 180.
    // Движущаяся платформа проходит весь разрыв.
    ui_factory->create_moving_ship(
        { 158, 20 },
        10,
        2,
        0.25f,
        155,
        180
    );

    // ------------------------------------------------------------
    // 6. Платформа после движущейся
    // ------------------------------------------------------------
    ui_factory->create_ship({ 180, 21 }, 12, 2);

    ui_factory->create_enemy({ 183, 18 }, 3, 2);
    ui_factory->create_jumpable_enemy({ 190, 18 }, 3, 3);

    // Блоки
    ui_factory->create_full_box({ 184, 14 }, 4, 3);
    ui_factory->create_box({ 192, 11 }, 4, 3);

    // ------------------------------------------------------------
    // 7. Последний сложный участок
    // ------------------------------------------------------------
    ui_factory->create_ship({ 198, 18 }, 9, 2);
    ui_factory->create_ship({ 212, 22 }, 8, 2);
    ui_factory->create_ship({ 225, 17 }, 10, 2);

    ui_factory->create_enemy({ 200, 15 }, 3, 2);
    ui_factory->create_jumpable_enemy({ 214, 19 }, 3, 3);
    ui_factory->create_enemy({ 229, 14 }, 3, 2);

    // Препятствия
    ui_factory->create_ship({ 201, 11 }, 5, 7);
    ui_factory->create_full_box({ 216, 12 }, 4, 3);
    ui_factory->create_box({ 229, 10 }, 4, 3);

    // ------------------------------------------------------------
    // 8. Финишная платформа
    // ------------------------------------------------------------
    // Низкая, длинная, прямоугольная.
    // Это последняя платформа уровня.
    Rect* finish = ui_factory->create_ship(
        { 240, 25 },
        50,
        2
    );

    ui_factory->set_level_end_platform(finish);
}