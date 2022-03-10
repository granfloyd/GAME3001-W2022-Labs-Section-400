#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Heuristic.h"
#include "Scene.h"
//#include "Obstacle.h"
#include "Target.h"
#include "SpaceShip.h"
#include "Tile.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	// Scene LifeCycle Functions
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
private:
	// IMGUI Function
	void GUI_Function();
	std::string m_guiTitle;
	
	glm::vec2 m_mousePosition;

	// Game Objects
	Target* m_pTarget;
	SpaceShip* m_pSpaceShip;
	//Obstacle* m_pObstacle;

	//Pathfinding objects and functions
	std::vector<Tile*> m_pGrid;
	bool m_isGridEnabled;

	void m_buildGrid();
	void m_setGridEnabled(bool state);
	bool m_getGridEnabled() const;
	void m_computeTileCosts();

	///calculate the shortest path
	void m_findShortestPath();
	void m_displayPathList();
	void m_resetPathFinding();
	void m_resetSimulation();

	///tile lists for pathfinding
	std::vector<Tile*> m_pOpenList;
	std::vector<Tile*> m_pClosedList;
	std::vector<Tile*> m_pPathList;


	//Convenience functions
	Tile* m_getTile(int col, int row);
	Tile* m_getTile(glm::vec2 grid_position);

	//Heuristic
	Heuristic m_currentHeuristic;

	//ship movement
	int m_moveCounter = 0;
	bool m_shipIsMoving = false;
	void m_moveShip();


	static int start_position[2];
	static int goal_position[2];
};

#endif /* defined (__PLAY_SCENE__) */