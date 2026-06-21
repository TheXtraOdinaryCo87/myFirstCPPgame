#include "gameMap.h"
#include <asserts.h>

void GameMap::create(int w, int h)
{
	*this = {}; //resets all the data
	mapData.resize(w * h);

	this->w = w;
	this->h = h;

	for (auto& e : mapData) { e = {}; } // clears all block data
}

Block& GameMap::getBlocUnsafe(int x, int y)
{
	permaAssertCommentDevelopement(mapData.size() == w * h, "Map data not initialised");

	permaAssertCommentDevelopement(x >= 0 && y >= 0 && x < w && y < h, "getBlocUnsafe out of bounds error");

	return mapData[x + y * w];
}

Block* GameMap::getBlocSafe(int x, int y)
{
	permaAssertCommentDevelopement(mapData.size() == w * h, "Map data not initialised");

	if (x < 0 || y < 0 || x >= w || y >= h) { return nullptr; }

	return &mapData[x + y * w];
}
