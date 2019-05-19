#pragma once

class IVehicle
{
public:
	IVehicle() {};
	virtual ~IVehicle() {};

	virtual void Print() = 0;
	virtual void SteerLeft() = 0;
	virtual void SteerRight() = 0;
	virtual void MoveForward() = 0;
	virtual void MoveBackward() = 0;
};

