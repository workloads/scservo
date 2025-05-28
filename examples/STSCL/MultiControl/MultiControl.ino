#include <SCServo.h>

#if defined(CONFIG_IDF_TARGET_ESP32C3) || defined(CONFIG_IDF_TARGET_ESP32C6) || defined(CONFIG_IDF_TARGET_ESP32S3)
#define COMSerial Serial0
#else
#define COMSerial Serial1
#endif

#if defined(NRF52840_XXAA) && defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h>
#endif

#define S_RXD D7
#define S_TXD D6
#define Servo_Num 6

SMS_STS st;
byte ID[Servo_Num] = {1, 2, 3, 4, 5, 6};
u16 Speed[Servo_Num] = {3400, 3400, 3400, 3400, 3400, 3400};
byte ACC[Servo_Num] = {253, 253, 253, 253, 253, 253};
s16 Pos[Servo_Num] = {0, 0, 0, 0, 0, 0};

int getPos(int id)
{
  return st.ReadPos(id);
}

void setup()
{
  Serial.begin(115200);

  COMSerial.begin(1000000, SERIAL_8N1);
  st.pSerial = &COMSerial;
  delay(1000);

  Serial.println("Calibration of all Servo");
  for (int i = 0; i < Servo_Num; i++) {
    st.CalibrationOfs(ID[i]);
  }

  for (int i = 0; i < Servo_Num; i++) {
    Pos[i] = getPos(ID[i]);
  }

  delay(1000);
}

void loop()
{
  if (!Serial.available()) {
    delay(100);
    return;
  }

  String input = Serial.readString();
  input.trim();

  if(input.startsWith("j")) {
    Serial.println("Reduce the angle");

    for (int i = 0; i < Servo_Num; i++) {
      if (Pos[i] == 0) {
        Serial.print(i);
        Serial.println(" It's already in the minimum position.");
        continue;
      }

      Pos[i] -= 1024;
      if (Pos[i] < 0) Pos[i] = 0;
    }
  } else if(input.startsWith("k")) {
    Serial.println("Increase the angle");

    for (int i = 0; i < Servo_Num; i++) {
      if (Pos[i] == 4095) {
        Serial.print(i);
        Serial.println(" It's already in the maximum position.");
        continue;
      }

      Pos[i] += 1024;
      if (Pos[i] > 4095) Pos[i] = 4095;
    }
  }

  st.SyncWritePosEx(ID, Servo_Num, Pos, Speed, ACC);
  delay(600);
}
