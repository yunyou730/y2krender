#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TransformComponent
{
public:
    TransformComponent();
    
    glm::mat4 CalcTransformMatrix();
    
    void SetPos(const glm::vec3& pos);
    void SetRot(const glm::vec3& axis,float degree);
    void SetScale(const glm::vec3& scale);
    
    float GetRotDeg() const { return _rotDeg;}
    
protected:
    glm::vec3 _pos = glm::vec3(0.0f,0.0f,0.0f);

    float _rotDeg = 0.0f;
    glm::vec3 _rotByAxis = glm::vec3(0.0,0.0,1.0);
    
    glm::vec3 _scale = glm::vec3(1.0f);
    
};

