#include "../include/GravityEngine.h"

namespace GEN
{
    void CalculateGravityForce(std::vector<Circle>& objects, double deltaTime){
        float distanceX = std::abs(objects[0].GetPos().a - objects[1].GetPos().a);
        float distanceY = std::abs(objects[0].GetPos().b - objects[1].GetPos().b);
        float forceX = G * ((objects[0].GetMass() * objects[1].GetMass()) / (distanceX*distanceX));
        float forceY = G * ((objects[0].GetMass() * objects[1].GetMass()) / (distanceY*distanceY));
        std::cout << forceX << std::endl;
        objects[0].UpdateForce(Vector2f(forceX, forceY));
        objects[1].UpdateForce(Vector2f(forceX, forceY));
        objects[0].CalculateAcc();
        objects[1].CalculateAcc();
        objects[0].UpdateVelocity(deltaTime);
        objects[1].UpdateVelocity(deltaTime);
        std::cout << "0x: " << objects[0].GetPos().a << std::endl;
        std::cout << "0y: " << objects[0].GetPos().b << std::endl;
        std::cout << "1x: " << objects[1].GetPos().a << std::endl;
        std::cout << "1y: " << objects[1].GetPos().b << std::endl;
    }
    void CalculateTotalForce(){}
};
