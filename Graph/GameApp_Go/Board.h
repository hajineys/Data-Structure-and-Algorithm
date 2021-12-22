#pragma once
#include "GDIEngine.h"
#include "GameDefine.h"
#include "Player.h"
#include "GameUI.h"
#include "Tile.h"

class Player;

/// <summary>
/// ������. �ٵ��� ������ �κ��� ����Ѵ�.
/// ���� ������ ���� �ʴ´�.
/// </summary>
class GoBoard
{
public:
	GoBoard();
	~GoBoard();

private:
	GDIEngine* m_GDIEngine;
	Player* m_Player;

	// ������ �迭�� �ٵ��� ������ŭ ��´�
	Tile* m_GoBoard[BOARD_Y][BOARD_X];

public:
	bool m_IsAlive;

	// ��ġ�κ��� �ѹ��� ���� ������ �˾ƿ´�.
	StoneType GetStoneType(int x, int y) const;

	void Initialize(GDIEngine* pGDIEngine);

	// ���� �� �ʱ�ȭ
	void InitBoard();

	void DrawBoard();
	void DrawBoardStoneType();
	
	// �÷��̾ Ŭ���� Ÿ�� ����Ÿ�� �� ����
	void PickTileChangeStoneType(Player* pPlayer);

public:
	/// �ֺ� Ÿ���� �����ϴ� �Լ��� ���� �ְ� �Ǵ� ���
	void CheckDeadStones(StoneType type);

private:
	// �� ���� Ÿ���� �ݴ븦 �����´�. (��->�� / ��->��)
	StoneType GetOpponent(StoneType myType);
};