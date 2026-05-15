#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

int main()
{
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(1200, 800, "Game Window");
	SetTargetFPS(60);

#pragma region imgui
	rlImGuiSetup(true);
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2.5;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
#pragma endregion

	std::cout << "Hello World\n";
	std::cout << "New Repo initiated\n";

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(WHITE);
#pragma region imgui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
#pragma endregion

		DrawText("Hello World", 190, 200, 20, { 255, 0, 200, 255 });

#pragma region imgui windows
		ImGui::Begin("test");

		ImGui::Text("Hi there");
		ImGui::Button("button");
		ImGui::SameLine();
		if (ImGui::Button("Button 2"))
		{
			std::cout << "Second Button\n";
		}
		ImGui::End();

		ImGui::Begin("test 2");

		ImGui::Text("Sup'!");
		ImGui::Separator();
		ImGui::NewLine();
		static float a = 0;
		ImGui::SliderFloat("slider", &a, 0, 1);
		ImGui::Button("button");

		ImGui::End();
#pragma endregion

#pragma region imgui
		rlImGuiEnd();
#pragma endregion
		EndDrawing();
	}

#pragma region imgui
	rlImGuiShutdown();
#pragma endregion

	CloseWindow();
	return 0;
}