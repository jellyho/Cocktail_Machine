// 
// 왜인지는 모르겠지만 Stepper 인스턴스가 생성이 안돼!! ㅅㅂ
// 차라리 깃헙에 있는 코드를 내가 쓰는 것도 나쁘지 않음

#include "Plate.h"

//************* 생성자 및 소멸자 함수 ****************//
Plate::Plate()
{

    Serial.println("생성자 함수 입성"); //************************************************************** test

    position = Coord(0, 0, 0);

    Stepper stepper_x(STEPS_PER_REVOLUTION, 2, 3, 4, 5);
    Stepper stepper_y(STEPS_PER_REVOLUTION, 6, 7, 8, 9);
    // parameter notation: steps per revolution, driver pin 1, driver pin 2, driver pin 3, driver pin 4

    // 동적할당 해주고 클래스의 포인터 멤버변수에 대입
    p_stepper_x = (Stepper*)malloc(sizeof(stepper_x));
    p_stepper_y = (Stepper*)malloc(sizeof(stepper_y));

    // 엔드스탑의 핀모드 설정
}

Plate::~Plate()
{
    // 동적으로 할당해 준 Stepper 의 해제를 위해 존재
    free(p_stepper_x);
    free(p_stepper_y);

    Serial.println("소멸자 함수 입성");

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
    ((Stepper*)p_stepper_x)->setSpeed(a_speed);
    ((Stepper*)p_stepper_y)->setSpeed(a_speed);
}


// 목표 위치를 Coord 스트럭트로 입력해주면 현재 위치에 따라 그 차만큼 움직임.
void Plate::move_horizontally(Coord a_des_pos)
{

    Serial.println("move horizontally 함수 입성"); //************************************************************** test

      // 인자로 목표 좌표를 받고 (a_des_pos)
      // 아래 함수로 현재 좌표를 받아 (current_position)
    Coord current_position = get_current_position();

    // x방향, y방향 각각 차이를 계산하고 그만큼 움직인다.
    // x 방향 이동
    int x_diff = a_des_pos.pos_x - current_position.pos_x;

    Serial.println(x_diff);

    ((Stepper*)p_stepper_x)->step(x_diff);
    this->position.pos_x += x_diff;

    // y 방향 이동
    int y_diff = a_des_pos.pos_y - current_position.pos_y;

    Serial.println(y_diff);

    ((Stepper*)p_stepper_y)->step(y_diff);
    this->position.pos_y += y_diff;
}


// 호출되면 (0,0)으로 돌아가고, 좌표도 초기화됨.
void Plate::move_to_initial_position()
{
    // 필요한 플래그 & 속도 선언 및 초기화
    bool x_touch = false;
    bool y_touch = false;
    const int move_speed = -1; // 설정 필요!

    // x 방향의 초기화
    while (!x_touch) {
        ((Stepper*)p_stepper_x)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_X))
            x_touch = true;
        this->position.pos_x -= move_speed;
    }

    // y 방향의 초기화
    while (!y_touch) {
        ((Stepper*)p_stepper_y)->step(move_speed);
        if (digitalRead(PIN_ENDSTOP_Y))
            y_touch = true;
        this->position.pos_y -= move_speed;
    }

}


// 양을 건네주면서 호출하면, 액츄에이터가 올라가고 해당 시간만큼 기다렸다가 액츄에이터가 내려옴.
void Plate::push_dispenser(int a_amount) {
    return;
    // 액츄에이터 클래스 인클루드 해와서 work_pump 함수 바로 사용하면 됨.

}
