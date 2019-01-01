/*
 * Example code Techman83's Growing Heart Lib
 */

#include <Arduino.h>
#include <Adafruit_DotStarMatrix.h>
#include <DotMatrix_GrowingHeart.h>
#include <SPI.h>

Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
  8, 8,  // Width, height
  23, 18, // Data pin, clock pin
  DS_MATRIX_BOTTOM  + DS_MATRIX_LEFT +
  DS_MATRIX_ROWS + DS_MATRIX_PROGRESSIVE,
  DOTSTAR_BRG);

DotMatrix_GrowingHeart heart;

void setup() {
  Serial.begin(115200);
  Serial.println("Main Setup");
  heart.setMatrix(&matrix)
    .matrixBegin();
}

void loop() {
  if (! heart.increase()) {
    delay(3000);
    heart.reset();
  }
  delay(200);
}
