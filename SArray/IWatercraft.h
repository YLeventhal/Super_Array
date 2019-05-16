#pragma once
class IWatercraft : public IVehicle
{
public:
	IWatercraft();
	virtual ~IWatercraft();

	virtual void TurnOn() = 0;
	virtual void TurnOff() = 0;
	virtual void MoveForward() = 0;
	virtual void MoveBackward() = 0;
	virtual void StopMoving() = 0;
};

