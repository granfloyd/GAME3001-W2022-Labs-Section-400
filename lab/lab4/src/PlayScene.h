#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Scene.h"
#include "Tile.h"
#include "Target.h"
#include "SpaceShip.h"
#include "Heuristic.h"

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
	
	//testtile
	/*Tile* m_pTile;*/
	//pathfinding
	std::vector<Tile*>m_pGrid;
	bool m_isGridEnabled;

	void m_buildGrid();
	bool m_getGridEnabled()const;
	void m_setGridEnabled(bool state);
	void m_computeTileCost();

	//convenience func to convert world to grid space
	Tile* m_getTile(int col, int row);
	Tile* m_getTile(glm::vec2 grid_position);
//heuristic
	Heuristic m_currentHeuristic;

	
};

#endif /* defined (__PLAY_SCENE__) */