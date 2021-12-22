#include "GameUI.h"

GameUI::GameUI()
{

}

GameUI::~GameUI()
{

}

void GameUI::Initialize(GDIEngine* pGDIEngine, Player* pPlayer)
{
	m_GDIEngine = pGDIEngine;
	m_Player = pPlayer;
}

void GameUI::CheckMyArea()
{
	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x < -1; x++)
		{
// 			if ()
// 			{
// 			}
		}
	}
}

void GameUI::DrawMyTurn()
{
	// WndProc의 마우스 이동 좌표 값을 받아서 원 그리기
	if (m_Player->MyTurnStoneType == StoneType::STONE_BLACK)
	{
		m_GDIEngine->DrawElliBlack(m_Player->CurrMousePos.x, m_Player->CurrMousePos.y);
	}
	else if (m_Player->MyTurnStoneType == StoneType::STONE_WHITE)
	{
		m_GDIEngine->DrawElli(m_Player->CurrMousePos.x, m_Player->CurrMousePos.y);
	}
}