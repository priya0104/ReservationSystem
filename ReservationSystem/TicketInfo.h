#pragma once
#include <string>
#include "FlightPath.h"
using namespace std;

namespace AirlineSystem {
	class TicketInfo {
	public:
		TicketInfo() = default;
		TicketInfo(string& firstName,string& lastName, FlightPath& path);
		string& getTicketHolderName();

		void displayTicketInfo();

	private:
		int mTicketNumber;
		FlightPath mFlight;
		std::string mFirstName;
		std::string mLastName;
		int mSeatNumber;
		std::string mCheckinGate;
		//std::string mFlightPathInfo[];


	};
}