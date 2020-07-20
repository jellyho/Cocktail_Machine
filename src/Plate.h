// Plate.h

#if 0
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Stepper.h> 
#include "Actuator.h"

//************* Coord 스트럭트 정의 ******************//
struct Coord {
    int pos_x, pos_y;
    Coord() { pos_x = 0;  pos_y = 0; }
    Coord(int ax, int ay) {
        pos_x = ax;  pos_y = ay;
    }
    Coord& set(int ax = 0, int ay = 0) {
        pos_x = ax;  pos_y = ay;
    }
};
//***************************************************//




class Plate {
private:
    const int STEPS_PER_REVOLUTION = 200;
    int STEPPER_SPEED = 30;

    Coord position; // 현재 자기의 위치

    // 핀 넘버는 생성자 함수에서 직접 전달하는거 어떻습니까? - 논의 필요
    const int PIN_ENDSTOP_X = 12;
    const int PIN_ENDSTOP_Y = 13;
    const int PIN_ENDSTOP_Z = 14;

    const int PIN_ACTUATOR_A = 12345;
    const int PIN_ACTUATOR_B = 67890;

    // void형 포인터를 사용해서, Steper를 생성하고 그 주소를 여기다 할당합시다.
    Stepper* p_stepper_x;
    Stepper* p_stepper_y;

    // 액츄에이터 관련 코드도 추가해야함.
    //=>모터드라이브 추가해야한다는 거죠??
    //설명 듣고 해야할 것 같습니다 일단 핀번호만 만듦

    /* 핀이름 바꿔야할듯
    const int MDPIN_1 = 4;//motordrive_1이라는 뜻..ㅎ
    const int MDPIN_2 = 5;
    const int VPIN = 6;//속도(velocity) pwm 제어 핀
    */



public:
    Plate();
    ~Plate();

    Coord get_current_position();
    void move_to(Coord a_des_pos);
    void move_to(int px, int py); // 함수 오버라이딩
    void move_to_initial_position();
    void set_stepper_speed(long a_speed);
    void push_dispenser(int a_amount);
};

#endif


/* 스테퍼 레퍼런스:
https://github.com/arduino-libraries/Stepper
https://www.arduino.cc/en/reference/stepper
*/