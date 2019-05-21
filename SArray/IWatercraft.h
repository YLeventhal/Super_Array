#pragma once
#include "IEngineVehicle.h"

class IWatercraft : public IEngineVehicle
{
public:
	IWatercraft();
	virtual ~IWatercraft();

	
	virtual void StopMoving() = 0;
};

