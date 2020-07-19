// 
// 왜인지는 모르겠지만 Stepper 인스턴스가 생성이 안돼!! ㅅㅂ
// 차라리 깃헙에 있는 코드를 내가 쓰는 것도 나쁘지 않음

#include "Plate.h"

Coord Plate::get_current_position() {
    return position;
}


void Plate::set_stepper_speed(long a_speed) {
    stepper_x.setSpeed(a_speed);
    stepper_y.setSpeed(a_speed);
}


void Plate::move_horizontally(Coord a_des_pos)
{
    // 인자로 목표 좌표를 받고 (a_des_pos)
    // 아래 함수로 현재 좌표를 받아 (current_position)
    Coord current_position = get_current_position();

    // x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
    // x 방향 이동
    int x_diff = a_des_pos.pos_x - current_position.pos_x;
    stepper_x.step(x_diff);
    this->position.pos_x += x_diff;

    // y 방향 이동
    int y_diff = a_des_pos.pos_y - current_position.pos_y;
    stepper_x.step(y_diff);
    this->position.pos_y += y_diff;
}


void Plate::move_to_initial_position()
{
    // 필요한 플래그 & 속도 선언 및 초기화
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1;

    // x 방향의 초기화
    while (!x_touch) {
        stepper_x.step(move_speed);
        if (digitalRead(PIN_ENDSTOP_X))
            x_touch = true;
        this->position.pos_x -= move_speed;
    }

    // y 방향의 초기화
    while (!y_touch) {
        stepper_y.step(move_speed);
        if (digitalRead(PIN_ENDSTOP_Y))
            y_touch = true;
        this->position.pos_y -= move_speed;
    }

}
