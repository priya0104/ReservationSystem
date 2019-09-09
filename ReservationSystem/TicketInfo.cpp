#include "pch.h"
#include "TicketInfo.h"
#include <iostream>
using namespace std;

AirlineSystem::TicketInfo::TicketInfo(string& firstName, string& lastName, FlightPath & path)
{
	mFirstName = firstName;
	mLastName = lastName;
	mFlight = path;
	mSeatNumber = path.bookSeat();
}

string & AirlineSystem::TicketInfo::getTicketHolderName()
{
	string name = mFirstName + "," + mLastName;
	return name;
}

void AirlineSystem::TicketInfo::displayTicketInfo()
{
	cout << "First Name: " << mFirstName << " Last Name: " << mLastName << endl;
	cout << "Destination: "<< mFlight.getDestination() << endl;
	cout << "Origin: " << mFlight.getOrigin() << endl;
	//cout << "Duration: " << mFlight.getDuration() << endl;
	cout << "Seat Number: " << mFlight.bookSeat() << endl;
}
