#include "ParticleTest.h"
#include "../Physics/Body.h"
#include "../Engine/CircleShape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();

	m_test = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_test);
}

void ParticleTest::Update()
{
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
	m_test->velocity = position - m_test->position;
	m_test->position = position;

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle()* randomf(1, 3);
		float size = randomf(0.1f, 0.2f);

		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), position, velocity, size);
		body->damping = 0;
		body->gravityScale = 1;
		body->restitution = 1;

		m_world->AddBody(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
