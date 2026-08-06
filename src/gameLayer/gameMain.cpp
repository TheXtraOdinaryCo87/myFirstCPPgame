#include <iostream>
#include <raylib.h>

#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>
#include "helpers.h"

struct GameData
{
	GameMap gameMap;
	Camera2D camera;

}gameData;

AssetManager assetManager;

bool initGame()
{
	assetManager.loadAll();

	

	gameData.gameMap.create(30, 10);

	gameData.gameMap.getBlocUnsafe(0, 0).type = Block::dirt;
	gameData.gameMap.getBlocUnsafe(1, 1).type = Block::grassBlock;
	gameData.gameMap.getBlocUnsafe(1, 2).type = Block::glass;
	gameData.gameMap.getBlocUnsafe(1, 3).type = Block::goldBlock;
	gameData.gameMap.getBlocUnsafe(0, 4).type = Block::platform;

	gameData.camera.target = {0, 0};
	gameData.camera.rotation = 0.0f;
	gameData.camera.zoom = 100.0f;
	return true;
}

bool updateGame()
{
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

	gameData.camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	Color Bg = {40, 42, 54, 255};
	ClearBackground(Bg);

	if (IsKeyDown(KEY_LEFT)) gameData.camera.target.x -= 3.f * deltaTime;
	if (IsKeyDown(KEY_RIGHT)) gameData.camera.target.x += 3.f * deltaTime;
	if (IsKeyDown(KEY_UP)) gameData.camera.target.y -= 3.f * deltaTime;
	if (IsKeyDown(KEY_DOWN)) gameData.camera.target.y += 3.f * deltaTime;

	BeginMode2D(gameData.camera);
	for (int y = 0; y < gameData.gameMap.h; y++)
	{
		for (int x = 0; x < gameData.gameMap.w; x++)
		{
			auto& b = gameData.gameMap.getBlocUnsafe(x, y);

			if (b.type != Block::air)
			{
				DrawTexturePro(
					assetManager.textures,
					getTextureAtlas(b.type, 0, 32, 32),
					{ (float)x, (float)y, 1, 1 },
					{ 0, 0 },
					0.f,
					WHITE
				);
			}
		}
	}
	EndMode2D();

	return true;
}

void closeGame()
{
}