#include "Collider.h"


bool BoxCollider::operator[](const BoxCollider& other) const {

    if (this->TopRight.x < other.BottomLeft.x || other.TopRight.x < this->BottomLeft.x) {
        return false;
    }

    if (this->BottomLeft.y > other.TopRight.y || other.BottomLeft.y > this->TopRight.y) {
        return false;
    }

    return true;



}