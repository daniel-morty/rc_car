#ifndef CONFIG_H
#define CONFIG_H

#define esp32_c3

#ifdef esp32_c3
	#define RIGHT_PIN		1
	#define FORWARD_PIN 	2
	#define BACKWARD_PIN	3
	#define LEFT_PIN		4
#endif


#ifdef esp8266
	#define RIGHT_PIN		2
	#define FORWARD_PIN 	0
	#define LEFT_PIN		4
	#define BACKWARD_PIN	5
#endif

#endif //CONFIG_H
