#include "clickable.h"
void Clickable::mousePressEvent(QMouseEvent* event) {
  if (isClicked == 1) {
    isClicked = 0;
  } else {
    isClicked = 1;
  }
  emit clicked();
}
