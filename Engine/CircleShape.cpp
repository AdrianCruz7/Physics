#include "CircleShape.h"
#include "Graphics.h"

void CircleShape::Draw(Graphics* graphics, const glm::vec2& position)
{

	int r = graphics->WorldToPixels(radius);
	graphics->DrawFilledCircle(graphics->WorldToScreen(position), (int)r, color);
}
