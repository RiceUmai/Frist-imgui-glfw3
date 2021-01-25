#include "UI_Manager.h"

UI_Manager::UI_Manager(GLFWwindow* window, Game* game)
{
	_game = game;
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
		static float Speed = 0.0f;
		static glm::vec3 RotatDir = glm::vec3(0.0f, 0.1f, 0.0f);
		static glm::vec3 Color = glm::vec3(0.0f ,0.0f ,0.0f);
		
		ImGui::Begin("Controller Panel");                          // Create a window called "Hello, world!" and append into it.
		
		ImGui::ColorEdit3("Color", &Color.x);
		_game->SetColor(Color);

		ImGui::SliderFloat("Speed", &Speed, 0.0f, 5.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
		_game->SettestFloat(Speed);

		ImGui::SliderFloat3("RotatDir", &RotatDir.x, 0.0f, 1.0f);
		_game->SetRotatDir(RotatDir);
		
		//ImGui::SliderFloat3("Color", &Color.x, 0.0f, 1.0f);
		//_game->SetColor(Color);

		//if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
		//	counter++;
		//ImGui::SameLine();
		//ImGui::Text("counter = %d", counter);

		ImGui::GetWindowPos();

		ImGui::Text("(%.1f FPS)", ImGui::GetIO().Framerate);
		ImGui::End();
	}

	{
		ImGui::Begin("Position");
		ImGui::Text("(%.3f,%.3f,%.3f)", _game->camera.Position.x, 
										_game->camera.Position.y, 
										_game->camera.Position.z);              
		ImGui::End();
	}

}

void UI_Manager::Draw()
{
	//game->Draw();
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
