#pragma once
#include <windows.h>
#include "GameDefine.h"

class GoBoard;
class Player;
class GDIEngine;
class GameUI;

/// <summary>
/// 게임 진행을 다룬다.
/// 바둑의 논리에는 개입하지 않는다.
/// </summary>
class GameManager
{
public:
	GameManager(GDIEngine* pEngine);
	~GameManager();

private:
	GDIEngine* m_pEngine;
	GoBoard* pGoBoard;
	Player* m_pPlayer;

	// UI
	GameUI* m_UI;

public:
	void DrawAll();

	void SetPlayersMousePos(int x, int y);
	void PickTileChangeStoneType();

	void CheckImDead(StoneType type);
	//void CheckMyArea(GoBoard* pGoBoard, StoneType Type);

public:
	// 교수님 바둑 참고 함수(비재귀 버전)
	//bool Check_DeadOrAlive(GoBoard* pGoBoard, int x, int y);
};