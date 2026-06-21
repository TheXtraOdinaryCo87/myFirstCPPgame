#include <iostream>
#include <raylib.h>

#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>

struct GameData
{
	GameMap gameMap;

}gameData;

AssetManager assetManager;

bool initGame()
{
	assetManager.loadAll();

	

	gameData.gameMap.create(30, 10);

	gameData.gameMap.getBlocUnsafe(0, 0).type = Block::dirt;
	gameData.gameMap.getBlocUnsafe(1, 1).type = Block::dirt;
	gameData.gameMap.getBlocUnsafe(1, 2).type = Block::dirt;
	gameData.gameMap.getBlocUnsafe(1, 3).type = Block::dirt;
	gameData.gameMap.getBlocUnsafe(0, 4).type = Block::dirt;

	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	Color Bg = {40, 42, 54, 255};
	ClearBackground(Bg);

	for (int y = 0; y < gameData.gameMap.h; y++)
	{
		for (int x = 0; x < gameData.gameMap.w; x++)
		{
			auto& b = gameData.gameMap.getBlocUnsafe(x, y);

			if (b.type != Block::air)
			{
				float size = 32;
				float posX = x * size;
				float posY = y * size;

				DrawTexturePro(
					assetManager.dirt,
					Rectangle{ 0.f, 0.f, (float)assetManager.dirt.width, (float)assetManager.dirt.height },
					{ posX, posY, size, size },
					{ 0, 0 },
					0.f,
					WHITE
				);
			}
		}
	}

	return true;
}

void closeGame()
{
}