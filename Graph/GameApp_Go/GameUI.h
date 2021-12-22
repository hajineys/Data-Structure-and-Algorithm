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

	// 그리기
	void DrawMyTurn();
};