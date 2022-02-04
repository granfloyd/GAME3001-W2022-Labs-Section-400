#pragma once
#ifndef __AGENT__
#define __AGENT__

#include <glm/vec4.hpp>
#include "DisplayObject.h"

class Agent : public DisplayObject
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
	bool* getCollisionWhiskers();//return the entire array
	glm::vec4 getLineColour(int index);
		float getWhiskersAngle()const;




	// setters
	void setTargetPosition(glm::vec2 new_position);
	void setCurrentDirection(glm::vec2 new_direction);
	void setLOSDistance(float distance);
	void setHasLOS(bool state);
	void setCurrentHeading(float heading);
	void setLOSColour(glm::vec4 colour);


	glm::vec2 setLeftLOSEndPoint(glm::vec2 point);
	glm::vec2 setMiddleLOSEndPoint(glm::vec2 point);
	glm::vec2 setRightLOSEndPoint(glm::vec2 point);
	glm::vec4 setLineColour(int index);
	float setWhiskersAngle()const;

private:
	void m_changeDirection();
	float m_currentHeading; // angle the ship is looking
	glm::vec2 m_currentDirection; // vector the ship is moving
	glm::vec2 m_targetPosition; // vector representing the target.position

	// LOS
	float m_LOSDistance;
	bool m_hasLOS;
	glm::vec4 m_LOSColour;

	glm::vec2 m_leftLOSEndPoint;
	glm::vec2 m_middleLOSEndPoint;
	glm::vec2 m_rightLOSEndPoint;
	glm::vec4 m_lineColour[3];//change this to 5
	bool m_collisionWhiskers[3];//contact list for each whisker change to 5
};



#endif /* defined ( __AGENT__) */