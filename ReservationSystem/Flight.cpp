#include "pch.h"
#include "Flight.h"
#include <iostream>

using namespace std;

namespace AirlineSystem {

	Flight::Flight(int flightModelNumber, int NoOfSeats) : 
		mFlightModelNumber(flightModelNumber), mNoOfSeats(NoOfSeats)
	{ }

	/*Flight::Flight(int noOfSeats) : mNoOfSeats(noOfSeats)
	{}*/
	void Flight::setFlightModelNumber(int flightModelNumber) {
		mFlightModelNumber = flightModelNumber;
	}
	int Flight::getFlightModelNumber() const {
		return mFlightModelNumber;
	}

	void Flight::setNumberofSeats(int numberofSeats) {
		mNoOfSeats = numberofSeats;
	}
	int Flight::getNumberofSeats() const {
		return mNoOfSeats;
	}

	void Flight::displayFlights() const {
		cout << "Flight Number: " << getFlightModelNumber() << "has seats:" << getNumberofSeats() << endl;
	}
}