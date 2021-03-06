#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include "SpaceShip.h"
// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	drawDisplayList();
	
	if (m_bDebugView)
	{
		Util::DrawCircle(m_pTarget->getTransform()->position, m_pTarget->getWidth() * 0.5f);

		if (m_pSpaceShip->isEnabled())
		{
			Util::DrawCircle(m_pSpaceShip->getTransform()->position, Util::max(m_pSpaceShip->getWidth() * 0.5f, m_pSpaceShip->getHeight() * 0.5f));
		}
	}
	
	
	
	SDL_SetRenderDrawColor(Renderer::Instance().getRenderer(), 255, 255, 255, 255);
}

void PlayScene::update()
{
	updateDisplayList();
	CollisionManager::squaredRadiusCheck(m_pSpaceShip, m_pTarget);
	
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	



	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance().quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance().changeSceneState(START_SCENE);
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2))
	{
		TheGame::Instance().changeSceneState(END_SCENE);
	}
}

void PlayScene::start()
{
	// Set GUI Title
	m_guiTitle = "Play Scene";
	m_bDebugView = false;

	m_pTarget = new Target();//instantuatung a new target object - allocating memory on the heap
	
	addChild(m_pTarget);
	m_pSpaceShip = new SpaceShip();
	m_pSpaceShip->setCurrentHeading(0.0);
	m_pSpaceShip->setTargetPosition(m_pTarget->getTransform()->position);	
	m_pSpaceShip->getRigidBody()->acceleration = m_pSpaceShip->getCurrentDirection() * m_pSpaceShip->getAccelerationRate();
	m_pSpaceShip->setEnabled(false);
	addChild(m_pSpaceShip);

	ImGuiWindowFrame::Instance().setGUIFunction(std::bind(&PlayScene::GUI_Function, this));
}

void PlayScene::GUI_Function()
{
	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();
	
	ImGui::Begin("lab2 debug properites", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove);

	ImGui::Separator();
	static bool toggleDebug = false;
	if (ImGui::Checkbox("Toggle debug draw", &toggleDebug))
	{
		m_bDebugView = toggleDebug;
	}

	ImGui::Separator();

	//target properties

	static float position[2] = { m_pTarget->getTransform()->position.x,m_pTarget->getTransform()->position.y};
	if (ImGui::SliderFloat2("Target position", position, 0.0f, 800.0f))
	{
		m_pTarget->getTransform()->position = glm::vec2(position[0], position[1]);
		m_pSpaceShip->setTargetPosition(m_pTarget->getTransform()->position);
	}
	
	ImGui::Separator();
	//spaceship properties
	static bool toggleSeek = m_pSpaceShip->isEnabled();
	if (ImGui::Checkbox("Toggle Seek", &toggleSeek))
	{
		m_pSpaceShip->setEnabled(toggleSeek);
	}
	static float speed = m_pSpaceShip->getMaxSpeed();
	if (ImGui::SliderFloat("Max Speed", &speed, 0.0f, 100.0f))
	{
		m_pSpaceShip->setMaxSpeed(speed);
		
	}

	static float acceleration = m_pSpaceShip->getAccelerationRate();
	if (ImGui::SliderFloat("Acceleration Rate", &acceleration, 0.0f, 50.0f))
	{
		m_pSpaceShip->setAccelerationRate(acceleration);
		m_pSpaceShip->getRigidBody()->acceleration = m_pSpaceShip->getCurrentDirection() * m_pSpaceShip->getAccelerationRate();
	}

	static float turn_rate = m_pSpaceShip->getTurnRate();
	if (ImGui::SliderFloat("Turn Rate", &turn_rate, 0.0f, 20.0f))
	{
		m_pSpaceShip->setTurnRate(turn_rate);
		
	}
	if(ImGui::Button("Reset"))
	{
		//reset ships position
		m_pSpaceShip->getTransform()->position = glm::vec2(100.0f, 400.0f);
		//reset target position
		m_pTarget->getTransform()->position = glm::vec2(500.0f, 100.0f);

		//reset current heading (orientation)velocity and acc
		m_pSpaceShip->setCurrentHeading(0.0);		
		m_pSpaceShip->getRigidBody()->velocity = glm::vec2(0, 0);
		m_pSpaceShip->getRigidBody()->acceleration = m_pSpaceShip->getCurrentDirection() * m_pSpaceShip->getAccelerationRate();
		
		m_pSpaceShip->setTargetPosition(m_pTarget->getTransform()->position);
	}

	ImGui::End();
}
