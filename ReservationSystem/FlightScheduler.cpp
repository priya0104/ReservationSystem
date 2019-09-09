#include "pch.h"
#include "FlightScheduler.h"
#include <iostream>

namespace AirlineSystem {
	FlightPath& FlightScheduler::addFlightPaths(const std::string& destination, const std::string& origin,
		Flight& flight, double startTime,double reachedTime) {
			FlightPath theFlightPath(destination,origin,flight,startTime,reachedTime);		
			theFlightPath.nonStop();
			theFlightPath.getDuration();
			mflightPaths.push_back(theFlightPath);

			return mflightPaths[mflightPaths.size() - 1];
	}

	FlightPath& FlightScheduler::getFlightPathDetails(const std::string& destination, const std::string& origin){
		for (auto& flightpath : mflightPaths) {
			if (flightpath.getDestination() == destination &&
				flightpath.getOrigin() == origin) {
				return flightpath;
			}
		}

		throw logic_error("No Employees found");
	}

	void FlightScheduler::disaplayFlightPaths() const {
		cout << "Flight Schedule details: " << endl;
		cout << "-------------------------" << endl;
		for (const auto& flightpath : mflightPaths)
		{
			flightpath.disaplayFlightSchedule();
		}
	}

	FlightPath & FlightScheduler::getFlightDetails(const std::string & destination, const std::string & origin)
	{
		for (auto& flightPath : mflightPaths)
		{
			if (flightPath.getDestination() == destination &&
				flightPath.getOrigin() == origin)
			{
				return flightPath;
			}
		}	
	}


	void FlightScheduler::ReserveSeat()
	{
		string firstName("");
		string lastName("");
		string destination, origin;
		cout << "Please provide details" << endl;
		cout << "First Name: ";
		cin >> firstName;
		cout << "Last Name: ";
		cin >> lastName;
		cout << "Destination: ";
		cin >> destination;
		cout << "Origin: ";
		cin >> origin;
		//
		
		FlightPath path = this->getFlightPathDetails(destination, origin);
		
		//Ticket object created Store first & last names and also flightpath object
		TicketInfo ticket(firstName, lastName, path);

		//Add it to the collection.
		mTickets.push_back(ticket);
		cout << "Thanks for booking with us, here is your ticketinfo" << endl;
		cout << "------------------------------------------------------" << endl;
		ticket.displayTicketInfo();
	}


	TicketInfo FlightScheduler::getUserTicket(string& firstname, string& lastname)
	{
		string name = firstname + "," + lastname;

		for (auto& ticket : mTickets)
		{
			if (ticket.getTicketHolderName() == name)
			{
				return ticket;
			}
		}
	}
	
	
}