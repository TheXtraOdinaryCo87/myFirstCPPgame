#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>

int main()
{
#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // no log output to the console by raylib
#endif

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "Game Window");
	SetExitKey(KEY_NULL); // To Disable Esc from closing the entire window
	SetTargetFPS(240);

#pragma region imgui
	rlImGuiSetup(true);
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2.5;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
#pragma endregion

	std::cout << "Hello World\n";
	std::cout << "New Repo initiated\n";

	if (!initGame())
	{
		return 0;
	}
	
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);
#pragma region imgui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
#pragma endregion

		if (!updateGame())
		{
			CloseWindow();
		}

#pragma region imgui windows

		rlImGuiEnd();
#pragma endregion
		EndDrawing();
	}

	CloseWindow();
	closeGame();
#pragma region imgui
	rlImGuiShutdown();
#pragma endregion

	return 0;
}