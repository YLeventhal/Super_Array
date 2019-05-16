#pragma once
#include "IAircraft.h"
class CAirplane :
	public IAircraft
{
private:
	std::string m_sBrand;
	std::string m_sModel;
	bool m_bOn = false;
	bool m_bMooving = false;
public:
	CAirplane(std::string brand, std::string model);
	~CAirplane();

	virtual void Print();
	virtual void TurnOn();
	virtual void TurnOff();
	virtual void Land();
	virtual void TakeOff();
	virtual void MoveForward();
	virtual void MoveBackward();
	virtual void StopMoving();
	virtual void SteerLeft();
	virtual void SteerRight();
};

