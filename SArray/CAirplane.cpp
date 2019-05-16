#include "pch.h"
#include <string>
#include <iostream>
#include "CAirplane.h"


CAirplane::CAirplane(std::string brand, std::string model) :
	m_sBrand(brand),
	m_sModel(model)
{}


CAirplane::~CAirplane()
{
}


void CAirplane::Print()
{
	std::cout << "Class: CAirplane\n Brand: " << m_sBrand << "\n" << "Model: " << m_sModel << std::endl;
}

void  CAirplane::TurnOn()
{
	if (m_bOn)
	{
		std::cout << "Already on!\n";
	}
	else
	{
		std::cout << "Engines on!\n";
		m_bOn = true;
	}
}

void  CAirplane::TurnOff()
{
	if (m_bOn)
	{
		std::cout << "Engines off!\n";
		m_bOn = false;
	}
	else
	{
		std::cout << "Already off!\n";
	}
}


void CAirplane::MoveForward()
{
	if (m_bMooving)
	{
		std::cout << "Already moving!\n";
	}
	else
	{
		std::cout << "Rolling!\n";
		m_bMooving = true;
	}

}
void CAirplane::MoveBackward()
{
	if (m_bMooving)
	{
		std::cout << "Already moving!\n";
	}
	else
	{
		std::cout << "Reversing!\n";
		m_bMooving = true;
	}

}

void CAirplane::Land()
{
	if (m_bMooving)
	{
		std::cout << "Landing!\n";
		m_bMooving = false;
	}
	else
	{
		std::cout << "On the ground already!\n";
	}

}

void CAirplane::TakeOff()
{
	if (m_bMooving)
	{
		std::cout << "Already flying!\n";
	}
	else
	{
		std::cout << "Lifting off!\n";
		m_bMooving = true;
	}

}
void CAirplane::StopMoving()
{
	if (m_bMooving)
	{
		std::cout << "stopping!\n";
	}
	else
	{
		std::cout << "Already stopped!\n";
		m_bMooving = false;
	}

}
void CAirplane::SteerLeft()
{
	if (m_bMooving)
	{
		std::cout << "Going Left!\n";
	}
	else
	{
		std::cout << "not moving!\n";
	}
}
void CAirplane::SteerRight()
{
	if (m_bMooving)
	{
		std::cout << "Going Right!\n";
	}
	else
	{
		std::cout << "not moving!\n";
	}
}