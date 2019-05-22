#pragma once

#include "IEngineVehicle.h"

class IWatercraft : public IEngineVehicle
{
public:
	virtual ~IWatercraft() {};

	
	virtual void StopMoving() = 0;
};

