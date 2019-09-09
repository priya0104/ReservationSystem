#pragma once
#include <string>
#include <ctime>
#include <vector>	

#include "Flight.h"


namespace AirlineSystem {

	const int kFlightNumberToStartWith = 1000;

	class FlightPath {
	public:
		FlightPath() = default;
		FlightPath(const std::string& destination, const std::string& origin,Flight& flight, 
			double startTime, double reachedTime);

		void setDestination(const std::string& destination);
		const std::string& getDestination() const;
		
		void setOrigin(const std::string& origin);
		const std::string& getOrigin() const;
		
		void setStartTime(double startTime);
		const double getStartTime() const;

		void setReachedTime(double reachedTime);
		const double getReachedTime() const;

		void getDuration();
		//const std::time_t setDuration() const;

		
		//add Flights for given 2 cities
		Flight& addFlight( int flightModelNumber,int noOfSeats);
		Flight& getFlightDetails(int flightModelNumber);
		void getAllFlights() const;
		//void reserveASeat();
		void nonStop();
		void hasStops();
		int bookSeat();
		bool isNonStop() const;
		bool isSeatAvailable() const;
		//int availableFlights();
		void displayFlightInfo() const;
		void disaplayFlightSchedule() const;

	private:
		std::string mDestination;
		std::string mOrigin;
		double mStartTime;
		double mReachedTime;
		double mDuration;
		bool mIsNonStop = false;
		bool mIsSeatAvailable = false;
		bool mAvailableSeats[150] = { false };
		Flight mFlight;
		//std::vector<Flight> mflights;
		int mNextFlightNumber = kFlightNumberToStartWith;
		//array to get the flights
		

		
	};
}