#include "Agent.h"

#include <iostream>

#include "Util.h"

Agent::Agent()
{
	//int whisker coloour
	m_lineColour[0] = glm::vec4(0, 1, 0, 1);//left line colour
	m_lineColour[1] = glm::vec4(0, 1, 0, 1);//mid line color
	m_lineColour[2] = glm::vec4(0, 1, 0, 1);//right line color
	m_lineColour[3] = glm::vec4(0, 1, 0, 1);//right line color
	m_lineColour[4] = glm::vec4(0, 1, 0, 1);//right line color
	//int whisker collision
	m_collisionWhiskers[0] = false;
	m_collisionWhiskers[1] = false;
	m_collisionWhiskers[2] = false;
	//int whisker angle
	m_whiskerAngle = 45;
	//int the los distance
	m_LOSDistance = 300;//300 px 
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
	return m_leftLOSEndPoint;
}

glm::vec2 Agent::getMiddleLOSEndPoint() const
{
	return m_middleLOSEndPoint;
}

glm::vec2 Agent::getRightLOSEndPoint() const
{
	return m_rightLOSEndPoint;
}
glm::vec2 Agent::getLeftzLOSEndPoint() const
{
	return m_leftzLOSEndPoint;
}
glm::vec2 Agent::getRightzLOSEndPoint() const
{
	return m_rightzLOSEndPoint;
}

bool* Agent::getCollisionWhiskers()
{
	return m_collisionWhiskers;
}

glm::vec4 Agent::getLineColour(const int index)
{
	return m_lineColour[index];
}

float Agent::getWhiskerAngle() const
{
	return m_whiskerAngle;
}

void Agent::setLeftLOSEndPoint(const glm::vec2 point)
{
	m_leftLOSEndPoint = point;
}

void Agent::setMiddleLOSEndPoint(const glm::vec2 point)
{
	m_middleLOSEndPoint = point;
}

void Agent::setRightLOSEndPoint(const glm::vec2 point)
{
	m_rightLOSEndPoint = point;
}
void Agent::setLeftzLOSEndPoint(const glm::vec2 point)
{
	m_leftzLOSEndPoint = point;
}
void Agent::setRightzLOSEndPoint(const glm::vec2 point)
{
	m_rightzLOSEndPoint = point;
}

void Agent::setLineColour(const int index,const glm::vec4 colour)
{
	m_lineColour[index] = colour;
}

void Agent::setWhiskersAngle(const float angle)
{
	m_whiskerAngle = angle;
}

void Agent::updateWhiskers(const float angle)
{
	m_whiskerAngle = angle;
	//mid whisker
	setMiddleLOSEndPoint(getTransform()->position + getCurrentDirection() * getLOSDistance());

	//left whisker
	float x = sin((getCurrentHeading() - m_whiskerAngle + 90) * Util::Deg2Rad);
	float y = cos((getCurrentHeading() - m_whiskerAngle + 90) * Util::Deg2Rad);
	setLeftLOSEndPoint(getTransform()->position + glm::vec2(x,-y) * getLOSDistance() * 0.75f);

	//right whisker
	 x = sin((getCurrentHeading() + m_whiskerAngle + 90) * Util::Deg2Rad);
	 y = cos((getCurrentHeading() + m_whiskerAngle + 90) * Util::Deg2Rad);
	setRightLOSEndPoint(getTransform()->position + glm::vec2(x, -y) * getLOSDistance() * 0.75f);
	//leftz
	 x = sin((getCurrentHeading() - m_whiskerAngle + 75) * Util::Deg2Rad);
	 y = cos((getCurrentHeading() - m_whiskerAngle + 75) * Util::Deg2Rad);
	 setLeftzLOSEndPoint(getTransform()->position + glm::vec2(x, -y) * getLOSDistance() *0.85f);

	//rightz
	 x = sin((getCurrentHeading() + m_whiskerAngle + 75) * Util::Deg2Rad);
	 y = cos((getCurrentHeading() + m_whiskerAngle + 75) * Util::Deg2Rad);
	 setRightzLOSEndPoint(getTransform()->position + glm::vec2(x, -y) * getLOSDistance() *0.85f);
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



void Agent::m_changeDirection()
{
	const auto x = cos(m_currentHeading * Util::Deg2Rad);
	const auto y = sin(m_currentHeading * Util::Deg2Rad);
	m_currentDirection = glm::vec2(x, y);
}
