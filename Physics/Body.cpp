#include "Body.h"
#include "../Engine/Shape.h"
#include "../Engine/Integrator.h"
#include "../Engine/World.h"
#include "../Engine/CircleShape.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	if (type != DYNAMIC) return;

	ApplyForce(World::gravity * gravityScale * mass);

	Integrator::ExplicitEuler(*this, dt);
	ClearForce();

	velocity *= (1.0f / (1.0f + (dt * damping)));
}

void Body::Draw(Graphics* graphics)
{
	shape->Draw(graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = body->position - position;
	float distance = glm::length(direction);
	float radius = dynamic_cast<CircleShape*>(body->shape)->radius + dynamic_cast<CircleShape*>(this->shape)->radius;
	return distance <= radius;
}
