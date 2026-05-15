#include <iostream>
#include <raylib.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "Game Window");
	SetTargetFPS(60);

	std::cout << "Hello World\n";
	std::cout << "New Repo initiated\n";
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		// ClearBackground(WHITE);
		DrawRectangle(50, 50, 100, 100, {255, 0, 0, 255});
		DrawRectangle(75, 75, 100, 100, {0, 255, 0, 255});
		EndDrawing();
	}

	CloseWindow();
	return 0;
}