#include "../include/Circle.h"

Circle::Circle(float mass, Vector2f center) : m_center(center), m_VAO(), m_VBO(), m_mass(mass), m_force(Vector2f(0.f, 0.f)), m_acc(Vector2f(0.f, 0.f)), m_velocity(Vector2f(0.f, 0.f))
{
    m_VAO.Bind();
    m_VBO.Bind();
    m_VAO.LinkVBO(m_VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    m_VAO.LinkVBO(m_VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3*sizeof(float)));
    m_VAO.Unbind();
    m_VBO.Unbind();
}

Vector2f Circle::GetPos(){return m_center;}

void Circle::UpdatePos(Vector2f newPos) {m_center = newPos;}

void Circle::UpdateForce(Vector2f newForce){m_force = newForce;}

void Circle::CalculateAcc(){
    m_acc.a = m_force.a/m_mass;
    m_acc.b = m_force.b/m_mass;
}

void Circle::Update()
{
    m_VBO.Bind();
    GLfloat vertices[216]; 
    for (int i = 0; i < 36; ++i) {
        float angle = 2.0f * M_PI * i / 36;
        vertices[i * 6] = m_center.a + 0.1 * std::cos(angle);
        vertices[i * 6 + 1] = m_center.b + 0.1 * std::sin(angle);
        vertices[i * 6 + 2] = 0.0f;
        vertices[i * 6 + 3] = 0.5;
        vertices[i * 6 + 4] = 0.5;
        vertices[i * 6 + 5] = 0.5;
    }
    m_VBO.BindData(vertices, sizeof(vertices));
    m_VBO.Unbind();
}

void Circle::UpdateVelocity(double deltaTime){
    m_velocity.a = m_velocity.a + (deltaTime*m_acc.a);
    m_velocity.b = m_velocity.b + (deltaTime*m_acc.b);
    std::cout << "VELx: " << m_velocity.a << std::endl;
    std::cout << "VELy: " << m_velocity.b << std::endl;
    Circle::UpdatePos(Vector2f(m_center.a + m_velocity.a, m_center.b + m_velocity.b));
    Circle::Update();
}

float Circle::GetMass(){return m_mass;}

void Circle::Draw()
{
    m_VAO.Bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, 36);
    m_VAO.Unbind();
}

void Circle::Delete()
{
    m_VAO.Delete();
    m_VBO.Delete();
}
