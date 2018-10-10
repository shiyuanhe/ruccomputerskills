#include "cvector.hpp"

CVector CVector::operator+ (const CVector& rhs) {
    CVector temp;
    temp.x = x + rhs.x;
    temp.y = y + rhs.y;
    return temp;
}
