#include "Collider.h"

RETURNVOID Collider::Update(SizeF s, Point2F p)
{
    this->TopRight.x = p.x + s.Width / 2;
    this->TopRight.y = p.y + s.Height / 2;


    this->BottomLeft.x = p.x - s.Width / 2;
    this->BottomLeft.y = p.y - s.Height / 2;



    return RETURNVOID();
}

bool Collider::Check(const Collider other)
{


    if (this->TopRight.x < other.BottomLeft.x || other.TopRight.x < this->BottomLeft.x) {
        return false;
    }
    if (this->BottomLeft.y > other.TopRight.y || other.BottomLeft.y > this->TopRight.y) {
        return false;
    }




    return true;

 
}
