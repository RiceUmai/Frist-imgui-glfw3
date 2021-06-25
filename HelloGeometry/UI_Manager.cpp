#include "UI_Manager.h"

UI_Manager::UI_Manager(GLFWwindow* window) : BackGroundColor(0.2f, 0.3f, 0.3f, 1.0f), faceNormalColor(1.0f), normal_length(0)
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	const char* glsl_version = "#version 130";
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	// Our state
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

}

UI_Manager::~UI_Manager()
{
}

void UI_Manager::Update(float delta)
{
	//game->Update(delta);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	{
		//ImGui::SliderFloat3("Color", &test.x, 0.0f, 1.0f);
		ImGui::ColorEdit4("Back Ground Color", &BackGroundColor.x);

		ImGui::ColorEdit3("faceNormal", &faceNormalColor.x);
		
		ImGui::SliderFloat("normal_length", &normal_length, 0.0f, 5.0f);

		static int counter;

		if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
			counter++;
		ImGui::SameLine();
		ImGui::Text("counter = %d", counter);

		ImGui::GetWindowPos();

		ImGui::Text("(%.1f FPS)", ImGui::GetIO().Framerate);
		ImGui::End();
	}

	{
		ImGui::Begin("Position");
		ImGui::Text("(%.3f,%.3f,%.3f)", cameraPositionText.x,
			cameraPositionText.y,
			cameraPositionText.z);
		ImGui::End();
	}
}

void UI_Manager::Draw()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

float* UI_Manager::getBackGroundColor1()
{
	glm::vec4 vec(BackGroundColor);
	float* data = glm::value_ptr(vec);
	return data;
}
