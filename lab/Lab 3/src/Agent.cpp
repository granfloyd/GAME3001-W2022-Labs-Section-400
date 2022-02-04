#include "Agent.h"

#include <iostream>

#include "Util.h"

Agent::Agent()
{
}

Agent::~Agent()
= default;

glm::vec2 Agent::getTargetPosition() const
{
	return m_targetPosition;
}

glm::vec2 Agent::getCurrentDirection() const
{
	return m_currentDirection;
}

float Agent::getLOSDistance() const
{
	return m_LOSDistance;
}

bool Agent::hasLOS() const
{
	return m_hasLOS;
}

float Agent::getCurrentHeading() const
{
	return m_currentHeading;
}

glm::vec4 Agent::getLOSColour() const
{
	return m_LOSColour;
}

glm::vec2 Agent::getLeftLOSEndPoint() const
{
	return glm::vec2();
}

glm::vec2 Agent::getMiddleLOSEndPoint() const
{
	return glm::vec2();
}

glm::vec2 Agent::getRightLOSEndPoint() const
{
	return glm::vec2();
}

bool* Agent::getCollisionWhiskers()
{
	return nullptr;
}

glm::vec4 Agent::getLineColour(int index)
{
	return glm::vec4();
}

float Agent::getWhiskersAngle() const
{
	return 0.0f;
}

void Agent::setTargetPosition(const glm::vec2 new_position)
{
	m_targetPosition = new_position;
}

void Agent::setCurrentDirection(const glm::vec2 new_direction)
{
	m_currentDirection = new_direction;
}

void Agent::setLOSDistance(const float distance)
{
	m_LOSDistance = distance;
}

void Agent::setHasLOS(const bool state)
{
	m_hasLOS = state;
	m_LOSColour = (m_hasLOS) ? glm::vec4(0, 1, 0, 1) : glm::vec4(1, 0, 0, 1);
}

void Agent::setCurrentHeading(const float heading)
{
	m_currentHeading = heading;
	m_changeDirection();
}

void Agent::setLOSColour(const glm::vec4 colour)
{
	m_LOSColour = colour;
}

glm::vec2 Agent::setLeftLOSEndPoint(glm::vec2 point)
{
	return glm::vec2();
}

glm::vec2 Agent::setMiddleLOSEndPoint(glm::vec2 point)
{
	return glm::vec2();
}

glm::vec2 Agent::setRightLOSEndPoint(glm::vec2 point)
{
	return glm::vec2();
}

void Agent::setLineColour(int index, glm::vec4 colour)
{
}

void Agent::setWhiskersAngle(float angle)
{
}

void Agent::updateWhiskers(float angle)
{
}

glm::vec4 Agent::setLineColour(int index)
{
	return glm::vec4();
}

float Agent::setWhiskersAngle() const
{
	return 0.0f;
}

void Agent::m_changeDirection()
{
	const auto x = cos(m_currentHeading * Util::Deg2Rad);
	const auto y = sin(m_currentHeading * Util::Deg2Rad);
	m_currentDirection = glm::vec2(x, y);
}
