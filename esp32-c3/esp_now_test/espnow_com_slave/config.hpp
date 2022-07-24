#ifndef CONFIG_H
#define CONFIG_H

//define which microcontroller you are using
#define esp32_c3

#ifdef esp32_c3
	#define FORWARD_PIN		18
	#define BACKWARD_PIN	19
	#define N_ONE			1
	#define N_TWO			2
	#define N_THREE			3
	#define N_FOUR			4
#endif


#ifdef esp8266
//TODO define these pins to better values
	#define FORWARD_PIN		2 
	#define BACKWARD_PIN	0
	#define RIGHT_PIN		4
	#define LEFT_PIN		5
	#define N_ONE			14
	#define N_TWO			12
	#define N_THREE			13
	#define N_FOUR			15
#endif

//for stepper motor stuff
#define MOTOR_CYCLE_COUNT 34

#endif //CONFIG_H
