#pragma once
#include "IVehicle.h"
class IEngineVehicle :
	public IVehicle
{
public:
	IEngineVehicle();
	virtual ~IEngineVehicle();

	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
};
