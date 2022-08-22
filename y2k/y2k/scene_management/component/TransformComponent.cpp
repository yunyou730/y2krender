#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
    
}

void TransformComponent::SetPos(const glm::vec3& pos)
{
    _pos = pos;
}

void TransformComponent::SetRot(const glm::vec3& axis,float degree)
{
    _rotDeg = degree;
    _rotByAxis = glm::normalize(axis);
}

void TransformComponent::SetScale(const glm::vec3& scale)
{
    _scale = scale;
}

glm::mat4 TransformComponent::CalcTransformMatrix()
{
    glm::mat4 transform(1.0);
    transform = glm::scale(transform,_scale);
    transform = glm::rotate(transform, glm::radians(_rotDeg), _rotByAxis);
    transform = glm::translate(transform,_pos);
    return transform;
    
}
