#pragma once
#include "Test.h"

class ForceTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Render() override;

protected:
	class Body* m_test{ nullptr };
};