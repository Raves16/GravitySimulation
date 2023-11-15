#ifndef GRAVITY_ENGINE_H
#define GRAVITY_ENGINE_H
#define G 0.00066743

#include <math.h>
#include <vector>
#include "Circle.h"
#include "Vector2f.h"


namespace GEN
{
    void CalculateGravityForce(std::vector<Circle>& objects, double deltaTime);
    void CalculateTotalForce();
};

#endif
