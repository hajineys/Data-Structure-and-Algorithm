#pragma once
#include <windows.h>
#include "GameDefine.h"
#include "Board.h"
#include "GameUI.h"

class Player
{
public:
	Player();
	~Player();

public:
	POINT CurrMousePos;

	StoneType MyTurnStoneType;

public:
	void InitMyTrunStoneType();
};