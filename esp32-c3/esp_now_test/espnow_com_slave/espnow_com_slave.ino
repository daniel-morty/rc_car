#include <esp_now.h>
#include <WiFi.h>
#include "config.hpp"
#include "stepper_motor.h"


#define POS_RIGHT 1
#define POS_LEFT 2
#define POS_CENTER 0
uint8_t wheel_pos = 0;

// Structure example to receive data
// Must match the sender structure
typedef struct struct_message {
    bool forward;
    bool backward;
    bool right;
    bool left;
} struct_message;

// Create a struct_message called myData
struct_message myData;

// callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("forward: ");
  Serial.println(myData.forward);
  Serial.print("backward: ");
  Serial.println(myData.backward);
  Serial.print("right: ");
  Serial.println(myData.right);
  Serial.print("left: ");
  Serial.println(myData.left);
  Serial.println();



	//both forward and backward are pressed or not pressed
	if ((myData.forward && myData.backward) || (!myData.forward && !myData.backward)){
		digitalWrite(FORWARD_PIN,  LOW);
		digitalWrite(BACKWARD_PIN, LOW);
	}

	//forward is pressed and back is not
	if (myData.forward && !myData.backward){
		digitalWrite(FORWARD_PIN,  HIGH);
		digitalWrite(BACKWARD_PIN, LOW);
	}

	//backward is pressed forward is not
	if (!myData.forward && myData.backward){
		digitalWrite(FORWARD_PIN,  LOW);
		digitalWrite(BACKWARD_PIN, HIGH);
	}

	//right is pushed, left is not
  if (myData.right && !myDate.left) {
	switch (wheel_pos){
		case POS_RIGHT:
			break;
		case POS_LEFT:
			turn_right();
			turn_right();
			break;
		case POS_CENTER:
			turn_right();
			break;
		defualt:
			break;
	}//end switch wheel_pos
	wheel_pos = POS_RIGHT;
  } //endif right=true, left=false




	//both left and right are pressed or neither are pressed
	if ((myData.right && myData.left) || (!myData.right && !myData.left)){
		switch (wheel_pos){
			case POS_RIGHT:
				turn_left();
				break;
			case POS_LEFT:
				turn_right();
				break;
			case POS_CENTER:
				break;
			defualt:
				break;
		}//end switch wheel_pos
		wheel_pos = POS_CENTER;
	}

	//left is pressed, right is not
	if (!myData.right && myData.left){
		switch (wheel_pos){
			case POS_RIGHT:
				turn_left();
				turn_left();
				break;
			case POS_LEFT:
				break;
			case POS_CENTER:
				turn_left();
				break;
			defualt:
				break;
		}//end switch wheel_pos
		wheel_pos = POS_LEFT;
	}
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);


  pinMode(FORWARD_PIN, OUTPUT);  //forward
  pinMode(BACKWARD_PIN, OUTPUT); //backward
  pinMode(RIGHT_PIN, OUTPUT);  //right
  pinMode(LEFT_PIN, OUTPUT);  //left
}
 
void loop() {

}
