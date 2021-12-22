#include "Stone.h"

Stone::Stone()
{

}

Stone::~Stone()
{

}

void Stone::Initialize(GDIEngine* _pGDIEngine, Player* _pPlayer)
{
	m_GDIEngine = _pGDIEngine;
	m_Player = _pPlayer;
}

void Stone::DrawMyTurn()
{
	// WndProc�� ���콺 �̵� ��ǥ ���� �޾Ƽ� �� �׸���
	if (m_Player->MyTurnStoneType == StoneType::STONE_BLACK)
	{
		m_GDIEngine->DrawElliBlack(m_Player->CurrMousePos.x, m_Player->CurrMousePos.y);
	}
	else if (m_Player->MyTurnStoneType == StoneType::STONE_WHITE)
	{
		m_GDIEngine->DrawElli(m_Player->CurrMousePos.x, m_Player->CurrMousePos.y);
	}
}