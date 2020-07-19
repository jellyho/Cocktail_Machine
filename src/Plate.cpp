// 
// 왜인지는 모르겠지만 Stepper 인스턴스가 생성이 안돼!! ㅅㅂ
// 차라리 깃헙에 있는 코드를 내가 쓰는 것도 나쁘지 않음

#include "Plate.h"

//************* 생성자 및 소멸자 함수 ****************//
Plate::Plate()
{
    position = Coord(0, 0, 0);

    Stepper stepper_x(STEPS_PER_REVOLUTION, 2, 3, 4, 5);
    Stepper stepper_y(STEPS_PER_REVOLUTION, 6, 7, 8, 9);

    stepper_x.setSpeed(STEPPER_SPEED);
    stepper_y.setSpeed(STEPPER_SPEED);
    // parameter notation: 
    // steps per revolution, driver pin 1, driver pin 2, driver pin 3, driver pin 4

    // 동적할당 해주고 클래스의 포인터 멤버변수에 대입
    p_stepper_x = (Stepper*)malloc(sizeof(stepper_x));
    p_stepper_y = (Stepper*)malloc(sizeof(stepper_y));

    *(p_stepper_x) = stepper_x;
    *(p_stepper_y) = stepper_y;

    // 엔드스탑의 핀모드 설정
    pinMode(PIN_ENDSTOP_X, INPUT);
    pinMode(PIN_ENDSTOP_Y, INPUT);
}

Plate::~Plate()
{
    // 동적으로 할당해 준 Stepper 의 해제를 위해 존재
    free(p_stepper_x);
    free(p_stepper_y);
    // 만약 Actuator 클래스를 상속받았다면 그거 고려해!
    // 우선은 스텝모터 테스트 용이므로 단순히 해제만 해주겠음.
}
//******************************************************//



//****************** public 지정자 함수 ******************//

// 현재의 위치를 Coord로 리턴해줌.
Coord Plate::get_current_position()
{
    return position;
}


// 말그대로 스피드를 설정해줌.
void Plate::set_stepper_speed(long a_speed) {
    (p_stepper_x)->setSpeed(a_speed);
    (p_stepper_y)->setSpeed(a_speed);
}


// 목표 위치를 Coord 스트럭트로 입력해주면 현재 위치에 따라 그 차만큼 움직임.
void Plate::move_to(Coord a_des_pos)
{
    // 인자로 목표 좌표를 받고 (a_des_pos)
    // 아래 함수로 현재 좌표를 받아 (current_position)
    Coord current_position = get_current_position();

    // x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
    // x 방향 이동
    int x_diff = a_des_pos.pos_x - current_position.pos_x;
    (p_stepper_x)->step(x_diff);
    this->position.pos_x += x_diff;

    // y 방향 이동
    int y_diff = a_des_pos.pos_y - current_position.pos_y;
    (p_stepper_y)->step(y_diff);
    this->position.pos_y += y_diff;
}

void Plate::move_to(int px, int py)
{
    // 인자의 인트를 받아 목표 좌표로 설정
    Coord a_des_pos(px, py);
    // 아래 함수로 현재 좌표를 받아 (current_position)
    Coord current_position = get_current_position();

    // x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
    // x 방향 이동
    int x_diff = a_des_pos.pos_x - current_position.pos_x;
    (p_stepper_x)->step(x_diff);
    this->position.pos_x += x_diff;

    // y 방향 이동
    int y_diff = a_des_pos.pos_y - current_position.pos_y;
    (p_stepper_y)->step(y_diff);
    this->position.pos_y += y_diff;
}


// 호출되면 (0,0)으로 돌아가고, 좌표도 초기화됨.
void Plate::move_to_initial_position()
{

    // note: 스위치 모양이 /(우상향) 이렇게 되어 있을 때 왼쪽부터 차례대로,
    // 인풋 핀, VCC, GND 순서대로 연결한다.

    // 필요한 플래그 & 속도 선언 및 초기화
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1; // 설정 필요!

    // x 방향의 초기화
    while (!x_touch) {
        (p_stepper_x)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_X))
            x_touch = true;
        this->position.pos_x -= move_speed;
    }

    // y 방향의 초기화
    while (!y_touch) {
        (p_stepper_y)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_Y))
            y_touch = true;
        this->position.pos_y -= move_speed;
    }

}


// 양을 건네주면서 호출하면, 액츄에이터가 올라가고 해당 시간만큼 기다렸다가 액츄에이터가 내려옴.
void Plate::push_dispenser(int a_amount)
{
    // 선언 및 초기화, 딜레이 타임
    Actuator a(PIN_ACTUATOR_A, PIN_ACTUATOR_B);
    const int SECONDS_PER_AMOUNT = 10;  // ************* 설정 필요!
    int delay_time = a_amount * 1000 / SECONDS_PER_AMOUNT;
    bool z_touch = false;

    // 작동 코드
    a.up();
    delay(delay_time);
    a.down();

    // 맨 끝에 도달하면 액츄에이터 인가 전압 해제
    while (!z_touch) {
        if (digitalRead(PIN_ENDSTOP_Z)) {
            a.idle();
            z_touch = true;
        }
    }

}