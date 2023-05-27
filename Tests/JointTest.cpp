#include "JointTest.h"
#include "../Engine/CircleShape.h"
#include "../Physics/Body.h"
#include "../Physics/Joint.h"

#define SPRING_STIFFNESS 100
#define SPRING_LENGTH 2
#define BODY_DAMPING 10
#define CHAIN_SIZE 3


void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

	auto prevBody = m_anchor;
	auto prevBody1 = m_anchor;
	auto prevBody2 = m_anchor;

	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		//chain -> for
		auto body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 });
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;

		/*auto body1 = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 200, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		body1->gravityScale = 250;
		body1->damping = BODY_DAMPING;
		m_world->AddBody(body1);

		auto joint1 = new Joint(prevBody1, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint1);

		auto body2 = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 600, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		body2->gravityScale = 250;
		body2->damping = BODY_DAMPING;
		m_world->AddBody(body2);

		auto joint2 = new Joint(prevBody2, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint2);
		
		auto joint3 = new Joint(body1, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint3);
		
		auto joint4 = new Joint(prevBody1, body2, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint4);
		
		auto joint5 = new Joint(prevBody2, body1, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint5);


		prevBody1 = body1;
		prevBody2 = body2;*/
	}
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
