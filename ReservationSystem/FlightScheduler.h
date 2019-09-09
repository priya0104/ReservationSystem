#pragma once
#include <string>
#include "FlightPath.h"
#include "TicketInfo.h"

using namespace std;

namespace AirlineSystem {
	class FlightScheduler {
	public:
		//void checkFlightSchedules(const std::string& destination, const std::string& origin);
		//Flight& addFlight(int flightModelNumber, int NoOfSeats);
		FlightPath& addFlightPaths(const std::string& destination, const std::string& origin,
			Flight& flight, double startTime, double reachedTime);
		FlightPath& getFlightPathDetails(const std::string& destination, const std::string& origin);

		//get Flight by its number and also between cities
		
		FlightPath& getFlightDetails(const std::string& destination, const std::string& origin);
		void ReserveSeat();
		//void displayFlightInfo() const;
		void disaplayFlightPaths() const;
		void disaplayFlights() const;
		TicketInfo getUserTicket(string& firstname, string& lastname);

	private:
		std::vector<FlightPath> mflightPaths;
		std::vector<TicketInfo> mTickets;
		std::vector<Flight> mflights;
		int mNextFlightNumber = kFlightNumberToStartWith;
	};
}