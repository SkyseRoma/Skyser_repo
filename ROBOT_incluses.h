/* Radio init
 - CONNECTIONS: nRF24L01 Modules See:
 http://arduino-info.wikispaces.com/Nrf24L01-2.4GHz-HowTo
   1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED 
//-----Nrf_recieve-----
#define CE_PIN   9
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL; // transmit pipe
RF24 radio(CE_PIN, CSN_PIN); // Create a  */

//----lightStrip_2812-----
#define PIN 8
int r,g,b;
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);

// IR
int controlvar;
//вход ик приёмника к А8
const int IR_PIN = A8;
IRrecv irrecv(IR_PIN);
decode_results results;

// Motor
#define D1 2          // Направление   in4
#define M1 3          // ШИМ           in3
#define D2 4          // Направление   in2
#define M2 5          // ШИМ           in1
int spda = 150;  
int spdb = 150;
bool dira = 1; 
bool dirb = 1;
int movdir;

//Servo
 Servo Headservo;
 int pos = 90;
 
//Ultrasonic_sensor
int echoPin = 45; 
int trigPin = 47; 
int fDistance;                // distance in front of the robot
int lDistance;                // distance on the left side of the robot
int rDistance;                // distance on the right side of the robot
unsigned int duration, cm; 

/* Buttons
const int buttonPin1 = 53;
const int buttonPin2 = 51;
const int buttonPin3 = 49;
const int buttonPin4 = 47;
const int buttonPin5 = 45;
bool but1 = 0; 
bool but2 = 0; 
bool but3 = 0; 
bool but4 = 0; 
bool but5 = 0; 
*/
    
//Controll variables
int joystick[3];  // 2 element array holding Joystick readings
int x;
int y;
int pwm_x;
int pwm_y;
int mode = 2;
int IrButton;

// IR-motion detector
#define MotionSense 39
bool motionsense;

//Odometry
int encoder_pin_l = 20;
int encoder_pin_r = 21;// The pin the encoder is connected           
unsigned int rpml;     // rpm reading
unsigned int rpmr;
volatile byte pulsesl;  // number of pulses6+
volatile byte pulsesr;
unsigned long timeoldl; 
unsigned long timeoldr;
// The number of pulses per revolution
// depends on your index disc!!
unsigned int pulsesperturn = 20;

