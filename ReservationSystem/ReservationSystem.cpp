// ReservationSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "FlightScheduler.h"

using namespace AirlineSystem;
using namespace std;

int displayMenu();
void displayFlights(FlightScheduler& fs);
void displayUserInfo(FlightScheduler& fs);

int main()
{
	FlightScheduler flightManager;

	Flight flight1(1001, 155);
	Flight flight2(1002, 170);
	Flight flight3(1003, 190);
	Flight flight4(1004, 250);

	FlightPath& path1 = flightManager.addFlightPaths("Seattle", "Denver", flight1, 12.45, 15.50);
	FlightPath& path2 = flightManager.addFlightPaths("Seattle", "NewYork", flight2, 17.00, 22.59);
	FlightPath& path3 = flightManager.addFlightPaths("NewYork", "Los Vegas", flight3, 11.00, 13.40);
	FlightPath& path4 = flightManager.addFlightPaths("Boston", "Seattle", flight4, 5.50, 10.00);

	while (true) {
		int selection = displayMenu();

		switch (selection) {
		case 0:
			return 0;
		case 1:
			flightManager.ReserveSeat();
			break;
		case 2:
			flightManager.disaplayFlightPaths();
			break;
		case 3:
			displayUserInfo(flightManager);
			break;
		case 4:
			displayFlights(flightManager);
			break;
		case 5:
			return 0;		
		default:
			cerr << "Unknown Command! Please Try Again" << endl;
			break;
		}
	}
}

void displayFlights(FlightScheduler& fs) {
	string destination;
	string origin;
	cout << "Destination ? " << endl;
	cin >> destination;
	cout << "Origin ? " << endl;
	cin >> origin;

	FlightPath path = fs.getFlightDetails(destination,origin);
	path.disaplayFlightSchedule();
}

void displayUserInfo(FlightScheduler& fs)
{
	string firstName;
	string lastName;
	cout << "First Name ? " << endl;
	cin >> firstName;
	cout << "Last Name ? " << endl;
	cin >> lastName;

	TicketInfo ticket = fs.getUserTicket(firstName,lastName);
	ticket.displayTicketInfo();
}

int displayMenu() {
	int selection;

	cout << endl;
	cout << "Welcome to Airline Reservation System. Please select an option from Menu:" << endl;
	cout << "1.Reserve a Seat and User ticket info" << endl;
	cout << "2.Flight Schedule" << endl;
	cout << "3.Display Passenger Information" << endl;
	cout << "4.Flight Details" << endl;
	//cout << "5.User ticket Information" << endl;
	cout << "5.Exit the program" << endl;

	cin >> selection;

	return selection;
}
