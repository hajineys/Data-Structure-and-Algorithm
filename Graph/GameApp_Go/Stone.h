#pragma once

#include "GDIEngine.h"
#include "Player.h"

// Player 클래스 전방선언(왜 하는지 잘 모르겠다)
class Player;

/// <summary>
/// 바둑돌 클래스 생성
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