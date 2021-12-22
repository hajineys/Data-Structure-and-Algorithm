#include "Tile.h"

Tile::Tile()
	:PosX(), PosY(),
	m_StoneType(),
	Passed(false),
	up(),
	right(),
	down(),
	left()
{

}

Tile::Tile(StoneType _StoneType, int x, int y)
{
	SetStoneType(_StoneType);
}

Tile::~Tile()
{

}

void Tile::SetPassed()
{
	Passed = true;
}

bool Tile::IsPassed()
{
	return Passed;
}

bool Tile::IsExistaWay()
{
	return (left == nullptr) || (right == nullptr) || (up == nullptr) || (down == nullptr);
}

bool Tile::IsMatch(StoneType type)
{
	return (m_StoneType == type);
}

bool Tile::MatchType_NotPassed(Tile* stone, StoneType type)
{
	return (stone->IsPassed() == false) && stone->IsMatch(type);
}