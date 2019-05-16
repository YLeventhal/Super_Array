#include "pch.h"
#include <iostream>
#include <string>
#include "CHotAirBalloon.h"


CHotAirBalloon::CHotAirBalloon(std::string shape, std::string colour):
m_sShape(shape),
m_sColour(colour)
{}


CHotAirBalloon::~CHotAirBalloon()
{
}


void CHotAirBalloon::Print()
{
	std::cout << "Class: CHotAirBalloon\n Shape: " << m_sShape << "\n" << "Name: " << m_sColour << std::endl;
}

void  CHotAirBalloon::TurnOn()
{
	if (m_bOn)
	{
		std::cout << "Already giving propane!\n";
	}
	else
	{
		std::cout << "Propane on!\n";
		m_bOn = true;
	}
}

void  CHotAirBalloon::TurnOff()
{
	if (m_bOn)
	{
		std::cout << "Propane off!\n";
		m_bOn = false;
	}
	else
	{
		std::cout << "Already off!\n";
	}
}


void CHotAirBalloon::TakeOff()
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

void CHotAirBalloon::Land()
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

void CHotAirBalloon::MoveForward()
{
	if (m_bMooving)
	{
		std::cout << "Lowering our altiitude!\n";
	}
	else
	{
		std::cout << "not in flight!\n";
	}
}
void CHotAirBalloon::MoveBackward()
{
	if (m_bMooving)
	{
	std::cout << "Lowering our altiitude!\n";
	}
	else
	{
		std::cout << "not in flight!\n";
	}
 }
 
 void CHotAirBalloon::SteerLeft()
 {
	 if (m_bMooving)
	 {
	 std::cout << "Lowering our altiitude!\n";
	 }
	 else
	 {
		 std::cout << "not in flight!\n";
	 }
 }
void CHotAirBalloon::SteerRight()
 {
	if (m_bMooving)
	{
		std::cout << "Lowering our altiitude!\n";
	}
	else
	{
		std::cout << "not in flight!\n";
	}
 }