/**
 * DotStarMatrix Growing Heart library for techman83's hug detector
 */

#include <DotMatrix_GrowingHeart.h>
#include <Arduino.h>

// Heart Matrix
const uint64_t HEART[] = {
  0x0000000000000000,
  0x0000000008000000,
  0x000000081c080000,
  0x0000001c1c1c0000,
  0x0000081c1c1c1400,
  0x0000081c3e3e1400,
  0x00001c3e3e3e3600,
  0x00001c3e3e7f3600,
  0x00081c3e7f7f7722
};
const int HEART_LEN = sizeof(HEART)/8;

DotMatrix_GrowingHeart::DotMatrix_GrowingHeart() {
  this->matrix    = nullptr;
  this->PIXELS = 0;
  this->COLOUR = 0;
  this->OFF    = 0;
}

DotMatrix_GrowingHeart& DotMatrix_GrowingHeart::setMatrix(Adafruit_DotStarMatrix* matrix) {
  if (matrix != nullptr) {
    this->matrix = matrix;
  }
  return *this;
}

void DotMatrix_GrowingHeart::matrixBegin() {
  matrix->begin();
  matrix->show(); // Initialize all pixels to 'off'
  matrix->setBrightness(96); // brightness (max 255)
  PIXELS = matrix->numPixels();
  COLOUR = matrix->Color(255, 0, 0); //RED
  OFF    = matrix->Color(0, 0, 0); //BLACK
  Serial.println("Matrix Ready");
}

void DotMatrix_GrowingHeart::displayImage(uint64_t image) {
  for (int i = 0; i < 64; i++) {
	  matrix->setPixelColor(i, bitRead(image, i) ? COLOUR : OFF);
  }
  matrix->show();
}

bool DotMatrix_GrowingHeart::increase() {
  if (++CUR_INDEX >= HEART_LEN) {
    Serial.println("Max Heart Reached <3");
    return false;
  }
  Serial.println("Increasing Heart <3");
  displayImage(HEART[CUR_INDEX]);
  return true;
}

void DotMatrix_GrowingHeart::reset() {
  CUR_INDEX = 0;
  displayImage(HEART[CUR_INDEX]);
}
