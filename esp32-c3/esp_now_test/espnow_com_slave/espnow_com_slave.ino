#include <esp_now.h>
#include <WiFi.h>

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


  if (myData.forward == true) {
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }

  if (myData.backward == true) {
    digitalWrite(19, HIGH);
  }
  else {
    digitalWrite(19, LOW);
  }

  if (myData.right == true) {
    digitalWrite(1, HIGH);
  }
  else {
    digitalWrite(1, LOW);
  }

  if (myData.left == true) {
    digitalWrite(0, HIGH);
  }
  else {
    digitalWrite(0, LOW);
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


  pinMode(5, OUTPUT);  //forward
  pinMode(19, OUTPUT); //backward
  pinMode(1, OUTPUT);  //right
  pinMode(0, OUTPUT);  //left
}
 
void loop() {

}
