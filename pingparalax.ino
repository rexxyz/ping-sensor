include <NewPing.h>
// Include the library:
include <SharpIR.h>

// Define model and input pin:
float Infrader_depan = A0;
float Infrader_kanan = A1;
float Infrader_kiri = A2;
define model 1080

float ping_depan = 24;
float ping_kiri_Depan = 12;
float ping_kiri_belakang = 29;
float ping_kiri = 13;
float ping_kanan = 9;
float ping_kanan_belakang = 11;
float ping_kanan_depan = 4;
float ping_belakang = 46; 
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

// Create variable to store the distance:
int distance0_cm;
int distance1_cm;
int distance2_cm;
//line sensor
int dataAnalog0 = 0;
int dataAnalog1 = 1;
//flames sensor
int dataAnalog2 = 2;
int dataAnalog3 = 3;
int dataAnalog4 = 4;

// Create a new instance of the SharpIR class:
SharpIR mySensor0 = SharpIR(Infrader_depan, model);
SharpIR mySensor1 = SharpIR(Infrader_kanan, model);
SharpIR mySensor2 = SharpIR(Infrader_kiri, model);

NewPing sonar1(ping_depan, ping_depan, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(ping_kiri_Depan, ping_kiri_Depan, MAX_DISTANCE);
NewPing sonar3(ping_kiri_belakang, ping_kiri_belakang, MAX_DISTANCE);
NewPing sonar4(ping_kiri, ping_kiri, MAX_DISTANCE);
NewPing sonar5(ping_kanan, ping_kanan, MAX_DISTANCE);
NewPing sonar6(ping_kanan_belakang, ping_kanan_belakang, MAX_DISTANCE);
NewPing sonar7(ping_belakang, ping_belakang, MAX_DISTANCE);
NewPing sonar8(ping_kanan_depan, ping_kanan_depan, MAX_DISTANCE);

//pin for communication with openCM///
#define pin_bit4  20
#define pin_bit3  21
#define pin_bit2  24
#define pin_bit1  5
#define pin_bit0  7

void setup() {
  Serial.begin(115200);
  pinMode(pin_bit0, 1);
  pinMode(pin_bit1, 1);
  pinMode(pin_bit2, 1);
  pinMode(pin_bit3, 1);
  pinMode(pin_bit4, 1); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  // Get a distance measurement and store it as distance_cm:
  distance0_cm = mySensor0.distance();
  distance1_cm = mySensor1.distance();
  distance2_cm = mySensor2.distance();


  //delay(100);                    
  Serial1.println("*");//sensor ping depan 
  Serial1.print(sonar1.ping_cm()); 
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("#");//sensor ping kiri depan
  Serial1.print(sonar2.ping_cm()); 
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("%");//sensor ping kiri belakang
  Serial1.print(sonar3.ping_cm());
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("/");//sensor ping kiri
  Serial1.print(sonar4.ping_cm());
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("@");//sensor ping kanan
  Serial1.print(sonar5.ping_cm()); 
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("a");//sensor ping kanan depan
  Serial1.print(sonar7.ping_cm());
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println("c");
  Serial1.println(distance1_cm);

  Serial1.println("d");
  Serial1.println(distance2_cm);
  delay(1000);
  
   //line sensor
  Serial1.println("f");
  dataAnalog0 = analogRead(A3); // Konversi pin A0 ke digital
  Serial1.println(dataAnalog0/10); // Kirim datanya
  //delay(1000); // delay 200 ms 

    //flame sensor
  Serial1.println("g");//sensor kiri
  int sensorValue2 = analogRead(A4);
  Serial1.println(sensorValue2);
  //  delay(70); 

  Serial1.println("i");//sensor depan
  int sensorValue3 = analogRead(A5);
  Serial1.println(sensorValue3);
  //delay(70); 

  Serial1.println("h");//sensor kanan
  int sensorValue4 = analogRead(A6);
  Serial1.println(sensorValue4);
  //delay(100); 

}
