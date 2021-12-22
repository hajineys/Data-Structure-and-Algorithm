#pragma once

#include "GDIEngine.h"
#include "Player.h"

// Player Ŭ���� ���漱��(�� �ϴ��� �� �𸣰ڴ�)
class Player;

/// <summary>
/// �ٵϵ� Ŭ���� ����
/// 
/// 2020. 12. 11 Hacgeum
/// </summary>
class GameUI
{
public:
	GameUI();
	~GameUI();

private:
	GDIEngine* m_GDIEngine;
	Player* m_Player;

public:
	void Initialize(GDIEngine* pGDIEngine, Player* pPlayer);

	void CheckMyArea();

	// �׸���
	void DrawMyTurn();
};