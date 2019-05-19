#pragma once
#include "IWatercraft.h"
class CSpeedBoat :
	public IWatercraft
{
public:
	CSpeedBoat();
	virtual ~CSpeedBoat();

	virtual void Print() = 0;
	virtual void SteerLeft() = 0;
	virtual void SteerRight() = 0;
	virtual void MoveForward() = 0;
	virtual void MoveBackward() = 0;
	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
	virtual void MoveForward() = 0;
	virtual void MoveBackward() = 0;
	virtual void StopMoving() = 0;
};

