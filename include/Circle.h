#ifndef CIRCLE_CLASS_H
#define CIRCLE_CLASS_H


#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include "Vector2f.h"
#include "VAO.h"
#include "VBO.h"
#include <math.h>
#include <iostream>

class Circle{
    public:
    Circle(float mass, Vector2f center);
    Vector2f GetPos();
    void UpdatePos(Vector2f newPos);
    void UpdateForce(Vector2f newForce);
    void UpdateVelocity(double deltaTime);
    void CalculateAcc();
    void Update();
    float GetMass();
    void Draw();
    void Delete();
    
    private:
    Vector2f m_center;
    VAO m_VAO;
    VBO m_VBO;
    float m_mass;
    Vector2f m_force;
    Vector2f m_acc;
    Vector2f m_velocity;
};

#endif
