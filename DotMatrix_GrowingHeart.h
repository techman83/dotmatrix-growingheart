#ifndef __DOTMATRIX_GROWINGHEART_H
#define __DOTMATRIX_GROWINGHEART_H

#include <Adafruit_DotStarMatrix.h>
#include <cstdlib>

class DotMatrix_GrowingHeart {
private:
  Adafruit_DotStarMatrix* matrix;
  uint16_t PIXELS;
  uint16_t CUR_INDEX;
  uint32_t COLOUR; //RED
  uint32_t OFF; //BLACK
  void displayImage(uint64_t image);

public:
  DotMatrix_GrowingHeart();
  DotMatrix_GrowingHeart& setMatrix(Adafruit_DotStarMatrix* matrix);
  void matrixBegin();
  bool increase();
  void reset();
};

#endif
