#pragma once

#include "IVehicle.h"

class IAircraft : public IVehicle
{
public:
	IAircraft();
	virtual ~IAircraft();

	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
	virtual void TakeOff() = 0;
	virtual void Land() = 0;
};

