#include "pch.h"
#include "FlightPath.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace AirlineSystem {
	FlightPath::FlightPath(const string& destination, const string& origin, Flight& flight, double startTime, double reachedTime)
	{
		mDestination = destination;
		mOrigin = origin;
		mFlight = flight;
		mStartTime = startTime;
		mReachedTime = reachedTime;
	}

	
	void  FlightPath::setDestination(const string& destination) {
		 mDestination = destination;
	}
	const std::string& FlightPath::getDestination() const {
		return mDestination;
	}

	void  FlightPath::setOrigin(const string& origin) {
		mOrigin = origin;
	}
	const std::string& FlightPath::getOrigin() const {
		return mOrigin;
	}

	void FlightPath::setStartTime(double startTime) {
		mStartTime = startTime;
	}
	const double FlightPath::getStartTime() const {
				
		return mStartTime;
	}

	void FlightPath::setReachedTime(double reachedTime) {
		mReachedTime = reachedTime;
	}
	const double FlightPath::getReachedTime() const {
		return mReachedTime;
	}
	
	void FlightPath::getDuration()
	{
		mDuration = mStartTime-mReachedTime;
	}
	//const std::time_t FlightPath::setDuration() const {
	//	return mDuration;
	//}

	bool FlightPath::isNonStop() const{
		return mIsNonStop;
	}

	bool FlightPath::isSeatAvailable() const {
		return mIsSeatAvailable;
	}

	void FlightPath::nonStop() {
		mIsNonStop = true;
	}
	void FlightPath::hasStops() {
		mIsNonStop = false;
	}

	int FlightPath::bookSeat()
	{
		int seatNumber;
		for (int i = 0; i < 150; i++)
		{
			if (mAvailableSeats[i] == 0)
			{
				mAvailableSeats[i] = 1;
				seatNumber = i;
			}
		}

		return seatNumber;
	}

	void FlightPath::disaplayFlightSchedule() const {
		cout << "From: " << getOrigin() << "  To: " << getDestination() << endl;
		cout << (isNonStop() ? "Non Stop Flight" : "Has stops in between") << endl;
		cout << "Start time: " << getStartTime() << " Reached time: " << getReachedTime() <<  endl;
		mFlight.displayFlights();
		//this->displayFlightInfo();
		
		cout << endl;
	}


}