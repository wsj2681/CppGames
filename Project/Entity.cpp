#include "Entity.h"

CEntity::CEntity()
{
	this->shape.setSize(Vector2f(50.f, 50.f));
	this->shape.setFillColor(Color::Red);
}

CEntity::~CEntity()
{
}

void CEntity::Move(const float& deltatime, const float dirX, const float dirY)
{
	this->shape.move(dirX * this->moveSpeed * deltatime, dirY * this->moveSpeed * deltatime);
}

void CEntity::Update(const float& deltatime)
{


}

void CEntity::Render(RenderTarget* target)
{
	target->draw(this->shape);
}