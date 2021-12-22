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
class Stone
{
public:
	Stone();
	~Stone();

private:
	GDIEngine* m_GDIEngine;
	Player* m_Player;

public:


public:
	void Initialize(GDIEngine* _pGDIEngine, Player* _pPlayer);
	void DrawMyTurn();
};