#pragma once
#include "GameDefine.h"

/// <summary>
/// �� ���� Ÿ��. ��ǻ� ���� ������ �����Ѵ�.
/// ��ġ�� �Ǿ��°�? ���� �⺻���� �Ǵܵ� �Ѵ�.
/// 
/// 2020.12.18 HakGeom
/// </summary>
class Tile
{
public:
	Tile();
	Tile(StoneType _StoneType, int x, int y);
	~Tile();

private:
	// �⺻ ����
	int PosX;
	int PosY;

	StoneType m_StoneType;
	bool Passed;

	// ���
	Tile* up;
	Tile* right;
	Tile* down;
	Tile* left;

public:
	// �� ��ġ�� Ÿ�� ���� ����
	int GetPosX() const { return PosX; }
	int GetPosY() const { return PosY; }
	void SetPosX(int val) { PosX = val; }
	void SetPosY(int val) { PosY = val; }

	StoneType GetStoneType() const { return m_StoneType; }
	void SetStoneType(StoneType val) { m_StoneType = val; }
	bool IsStoneType(StoneType type) { return (m_StoneType == type); }

	void SetPassed();
	bool IsPassed();
	bool IsExistaWay();
	bool IsMatch(StoneType type);
	bool MatchType_NotPassed(Tile* stone, StoneType type);
	//BOOL ResetAllPassed(GoBoard* pGoBoard);
};