#pragma once
#include <string>


namespace AirlineSystem {

	const int kDefaultNumberOfSeats = 150;

	class Flight {
	public:
		Flight() = default;
		Flight(int flightModelNumber,int noOfSeats);
		//Flight(int noOfSeats);

		//bool checkSeatsAvail(int seatnumber);
		void displayFlights() const;

		
		void setFlightModelNumber(int flightModelNumber);
		int getFlightModelNumber() const;
		void setNumberofSeats(int numberofSeats);
		int getNumberofSeats() const;
		//bool checkStatus() const;

	private:
		int mFlightModelNumber = -1;
		int mNoOfSeats = kDefaultNumberOfSeats;
		//bool mAvailableSeats[150] = { false };
	};
}