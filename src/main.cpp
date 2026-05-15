#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1200, 800, "Game Window");
	SetTargetFPS(60);
	rlImGuiSetup(true);

	std::cout << "Hello World\n";
	std::cout << "New Repo initiated\n";
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		rlImGuiBegin();

		ClearBackground(WHITE);
		DrawText("Hello World", 190, 200, 20, {255, 0, 200, 255});

		ImGui::Begin("test");

		ImGui::Text("Hi there");
		ImGui::Button("button");

		ImGui::End();
		rlImGuiEnd();
		EndDrawing();
	}

	rlImGuiShutdown();

	CloseWindow();
	return 0;
}