#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_IS31FL3731.h>

Adafruit_IS31FL3731 matrix = Adafruit_IS31FL3731();

const unsigned char mog [] PROGMEM = {
  // 'mog2, 9x16px
  0x00, 0x00, 0x00, 0x00, 0x02, 0x21, 0xf0, 0xa8, 0x7e, 0x3c, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0xff
};

//static const uint8_t PROGMEM
//  test_bmp[] =
//  { B00000000,
//    B11111111,
//    B00000000,
//    B11111111,
//    B00000000,
//    B11111111,
//    B00000000,
//    B11111111 };

void setup() {

  if (! matrix.begin()) {
    while (1);
  }
  
}


void loop() {
  matrix.setRotation(0);

  matrix.clear();
  matrix.drawBitmap(0, 0, mog, 16, 8, 100);
  delay(500);

  //matrix.clear();
  for (int8_t x=0; x<=16; x++) {
    for (int8_t y=0; y<=8; y++) {
      matrix.drawPixel(x, y, 50);
      delay(50);  
    }
  }
  delay(500);

  for (int8_t x=16; x>=0; x--) {
    for (int8_t y=8; y>=0; y--) {
      matrix.drawPixel(x, y, 0);
      delay(50);  
    }
    
  }
  delay(500);

}
