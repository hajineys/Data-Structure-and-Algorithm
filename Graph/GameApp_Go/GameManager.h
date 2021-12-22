#pragma once
#include <windows.h>
#include "GameDefine.h"

class GoBoard;
class Player;
class GDIEngine;
class GameUI;

/// <summary>
/// ���� ������ �ٷ��.
/// �ٵ��� ������ �������� �ʴ´�.
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
	// ������ �ٵ� ���� �Լ�(����� ����)
	//bool Check_DeadOrAlive(GoBoard* pGoBoard, int x, int y);
};