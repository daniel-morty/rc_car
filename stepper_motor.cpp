#include "stepper_motor.hpp"

void turn_left() {
	for (int i = 0; i < MOTOR_CYCLE_COUNT; i++) {
		digitalWrite(N_ONE, HIGH);
		delay(10);
		digitalWrite(N_ONE, LOW);
		digitalWrite(N_TWO, HIGH);
		delay(10);
		digitalWrite(N_TWO, LOW);
		digitalWrite(N_THREE, HIGH);
		delay(10);
		digitalWrite(N_THREE, LOW);
		digitalWrite(N_FOUR, HIGH);
		delay(10);
		digitalWrite(N_FOUR, LOW);
	}
}

void turn_right() {
	for (int i = 0; i < MOTOR_CYCLE_COUNT; i++) {
		digitalWrite(N_FOUR, HIGH);
		delay(10);
		digitalWrite(N_FOUR, LOW);
		digitalWrite(N_THREE, HIGH);
		delay(10);
		digitalWrite(N_THREE, LOW);
		digitalWrite(N_TWO, HIGH);
		delay(10);
		digitalWrite(N_TWO, LOW);
		digitalWrite(N_ONE, HIGH);
		delay(10);
		digitalWrite(N_ONE, LOW);
	}
}
