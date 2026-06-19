#include <iostream>
#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>

struct GameData
{
	Texture dirtTexture;
}gameData;

AssetManager assetManager;

bool initGame()
{
	assetManager.loadAll();

	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	DrawTexturePro(gameData.dirtTexture, {0, 0, (float)gameData.dirtTexture.width, (float)gameData.dirtTexture.height}, {50, 50, 100, 100}, {}, 0, WHITE);

	return true;
}

void closeGame()
{
}