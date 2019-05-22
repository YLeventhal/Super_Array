#pragma once

#include "IEngineVehicle.h"

class IAircraft : public IEngineVehicle
{
public:
	virtual ~IAircraft() {};

	
	virtual void TakeOff() = 0;
	virtual void Land() = 0;
};

