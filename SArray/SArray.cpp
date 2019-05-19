
#include "pch.h"
#include <iostream>
#include "IVehicle.h"
#include "IWatercraft.h"
#include "IAircraft.h"
#include "CAirplane.h"
#include "CHotAirBalloon.h"

int main()
{

	CHotAirBalloon hab1("car", "red");
	hab1.Print();

	CAirplane ap1("boeing", "747");

	ap1.Print();




}

