#pragma once
#ifndef __TILE__
#define __TILE__

#include "NavigationObject.h"
#include "TileStatus.h"
#include "Label.h"
#include "NeighbourTile.h"

class Tile :public NavigationObject
{

public:
	//constuctor
	Tile();
	//destuctor
	~Tile();
	//lifecycle func
	void draw()override;
	void update()override;
	void clean()override;
	//getters and setters(accessors and mutators)
	Tile* getNegibourTile(NeighbourTile position);
	void setNegibourTile(NeighbourTile position,Tile* tile);

	float getTileCost()const;
	void setTileCost(float const);

	TileStatus getTileStatus()const;
	void setTileStatus(TileStatus status);

	void addLabels();
	void setLabelsEnabled(bool state);
private:
	//private instance members 
	float m_cost;
	TileStatus m_status;
	Label* m_costLabel;
	Label* m_statusLabel;

	Tile* m_neighbours[NUM_OF_NEIGHBOUR_TILES];
};
#endif