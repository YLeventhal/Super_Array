#pragma once
#include "IAircraft.h"
class CHotAirBalloon :
	public IAircraft
{
private:
	std::string m_sShape;
	std::string m_sColour;
	bool m_bOn = false;
	bool m_bMooving = false;

public:
	CHotAirBalloon(std::string shape, std::string colour);
	~CHotAirBalloon();

	virtual void Print();
	virtual void TurnOn();
	virtual void TurnOff();
	virtual void TakeOff();
	virtual void Land();
	virtual void MoveForward();
	virtual void MoveBackward();
	virtual void SteerLeft();
	virtual void SteerRight();
};

