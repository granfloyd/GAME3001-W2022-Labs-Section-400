#pragma once
#ifndef __AGENT__
#define __AGENT__

#include <glm/vec4.hpp>
#include "NavigationObject.h"

class Agent : public NavigationObject
{
public:
	Agent();
	~Agent();

	// Inherited via GameObject
	void draw() override = 0;
	void update() override = 0;
	void clean() override = 0;

	// getters
	glm::vec2 getTargetPosition() const;
	glm::vec2 getCurrentDirection() const;
	float getLOSDistance() const;
	bool hasLOS() const;
	float getCurrentHeading() const;
	glm::vec4 getLOSColour() const;


	glm::vec2 getLeftLOSEndPoint()const;
	glm::vec2 getMiddleLOSEndPoint()const;
	glm::vec2 getRightLOSEndPoint()const;
	glm::vec2 Agent::getLeftzLOSEndPoint() const;
	glm::vec2 Agent::getRightzLOSEndPoint() const;
	bool* getCollisionWhiskers();//return the entire array
	glm::vec4 getLineColour(int index);
		float getWhiskerAngle()const;




	// setters
	void setTargetPosition(glm::vec2 new_position);
	void setCurrentDirection(glm::vec2 new_direction);
	void setLOSDistance(float distance);
	void setHasLOS(bool state);
	void setCurrentHeading(float heading);
	void setLOSColour(glm::vec4 colour);

	void setLeftLOSEndPoint(glm::vec2 point);
	void setMiddleLOSEndPoint(glm::vec2 point);
	void setRightLOSEndPoint(glm::vec2 point);
	void setLeftzLOSEndPoint(glm::vec2 point);
	void setRightzLOSEndPoint(glm::vec2 point);
	void setLineColour(int index,glm::vec4 colour);
	void setWhiskersAngle(float angle);

	void updateWhiskers(float angle);

private:
	void m_changeDirection();
	float m_currentHeading; // angle the ship is looking
	glm::vec2 m_currentDirection; // vector the ship is moving
	glm::vec2 m_targetPosition; // vector representing the target.position

	// LOS
	float m_LOSDistance;
	bool m_hasLOS;
	glm::vec4 m_LOSColour;

	//whiskers
	glm::vec2 m_leftLOSEndPoint;
	glm::vec2 m_middleLOSEndPoint;
	glm::vec2 m_rightLOSEndPoint;
	glm::vec2 m_leftzLOSEndPoint;
	glm::vec2 m_rightzLOSEndPoint;
	glm::vec4 m_lineColour[5];//change this to 5
	bool m_collisionWhiskers[5];//contact list for each whisker change to 5

	float m_whiskerAngle;//angle of the left and irght whisker relative to the front
};



#endif /* defined ( __AGENT__) */