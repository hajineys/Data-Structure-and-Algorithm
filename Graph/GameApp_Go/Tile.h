#pragma once
#include "GameDefine.h"

/// <summary>
/// 한 개의 타일. 사실상 돌의 정보를 포함한다.
/// 매치가 되었는가? 등의 기본적인 판단도 한다.
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
	// 기본 정보
	int PosX;
	int PosY;

	StoneType m_StoneType;
	bool Passed;

	// 노드
	Tile* up;
	Tile* right;
	Tile* down;
	Tile* left;

public:
	// 돌 위치와 타입 셋팅 관련
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