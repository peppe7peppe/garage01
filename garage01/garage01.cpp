#include"Header.h"


int main(int argc, const char* argv[]) {
	// Global variables
	std::string in_vehicleType, in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour;
	int in_vehicleSeats, choice; int sizeOfGarage = 0;
	Garage g;

	// Demo vehiclea
	g.demoVehicles();


	bool b;
	bool c;

	do {
		b = true;
		c = true;
		g.display_CurrentData();
		//    do{
		std::cout << "\n \t \t<< Welcome >>"
			<< "\n \tLet's Get Started!"
			<< "\n--------------------------"
			<< "\n \tOptions"
			<< "\n--------------------------"
			<< "\nPlease Enter Your Choice\n"
			<< "\n1. Create Garage"
			<< "\n2. Remove Garage"
			<< "\n3. Skip To Main Menu"
			<< "\n4. Exit"
			<< std::endl;

		std::cin >> choice;

		switch (choice) {
		case 1: {
			std::cout
				<< "\nTo Create A New Garage, Please Enter Number of Parkinglots To Create. "
				<< std::endl;
			std::cin >> sizeOfGarage;

			g.newGarage = g.createGarage(sizeOfGarage);
			std::cout << "A Garage With The Capacity of " << g.newGarage << " Vehicles Created." << endl;
			break;
		}
		case 2: {
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			c = false;
			break;
		}
		default: {
			std::cout << "\nInvalid input! \n  " << endl;
			break;
		}
		}
		if (choice != 4) {
			do {
				g.display_CurrentData();
				std::cout
					<< "\n \tMAIN MENU"
					<< "\n--------------------------"
					<< "\n \tOptions"
					<< "\n--------------------------"
					<< "\nPlease enter your choice\n"
					<< "\n1. Park Vehicle"
					<< "\n2. Remove Vehicle"
					<< "\n3. Search Vehicle"
					<< "\n4. Retrieve Vehicle Registration"
					<< "\n5. Garage Data"
					<< "\n6. Back To Start"
					<< "\n7. Exit"
					<< std::endl;

				std::cin >> choice;

				switch (choice) {
				case 1: {
					do {
						g.display_CurrentData();


						std::cout
							<< "\n \t \tPARK VEHICLE MENU"
							<< "\n--------------------------"
							<< "\n \tOptions"
							<< "\n--------------------------"
							<< "\nPlease enter your choice\n"
							<< "\n1. Park Bicycle"
							<< "\n2. Park Motorcycle"
							<< "\n3. Park Car"
							<< "\n4. Park Bus"
							<< "\n5. Park Truck"
							<< "\n6. Back To Main Menu"
							<< "\n7. Exit"
							<< std::endl;

						std::cin >> choice;

						if (g.get_garageSize() == g.newGarage) {
							std::cout
								<< "\n \t \t \t << GARAGE IS FULL >>"
								<< "\n \t Go To >> Create Garage << To Resize Garage"
								<< "\n \t \t Returning To Start Menu"
								<< endl;
							choice = 6;
							b = false;
						}
						switch (choice) {
						case 1: {
							int in_bikeWheels;
							std::string in_bikeFrame;

							std::cout << "\tPlease enter brand >> \t";
							std::cin >> in_vehicleManufacturer;
							std::cout << "\tPlease enter model >> \t";
							std::cin >> in_vehicleModel;
							std::cout << "\tPlease enter registration/license number >> \t";
							std::cin >> in_vehicleRegNr;
							std::cout << "\tPlease enter colour >> \t";
							std::cin >> in_vehicleColour;
							std::cout << "\tPlease enter number of seats >> \t";
							std::cin >> in_vehicleSeats;
							std::cout << "\tFrame? (female/male)  >> \t";
							std::cin >> in_bikeFrame;
							std::cout << "\tPlease enter number of wheels >> \t";
							std::cin >> in_bikeWheels;

							Vehicle* bike = new Bicycle("", in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour, in_vehicleSeats, in_bikeFrame, in_bikeWheels);
							g.addVehicle(bike);
							break;
						}
						case 2: {
							int in_motorClass;
							int in_gears;

							std::cout << "\tPlease enter brand >> \t";
							std::cin >> in_vehicleManufacturer;
							std::cout << "\tPlease enter model >> \t";
							std::cin >> in_vehicleModel;
							std::cout << "\tPlease enter registration/license number >> \t";
							std::cin >> in_vehicleRegNr;
							std::cout << "\tPlease enter colour >> \t";
							std::cin >> in_vehicleColour;
							std::cout << "\tPlease enter number of seats >> \t";
							std::cin >> in_vehicleSeats;
							std::cout << "\tPlease enter class (light/heavy) >> /t";
							std::cin >> in_motorClass;
							std::cout << "\tPlease enter nr of gears >> \t";
							std::cin >> in_gears;

							Vehicle* motorcycle = new MotorCycle("", in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour, in_vehicleSeats, in_gears, in_motorClass);
							g.addVehicle(motorcycle);
							break;
						}
						case 3: {
							int in_carDoors;
							std::string in_electric;

							std::cout << "\tPlease enter brand >> \t";
							std::cin >> in_vehicleManufacturer;
							std::cout << "\tPlease enter model >> \t";
							std::cin >> in_vehicleModel;
							std::cout << "\tPlease enter registration/license number >> \t";
							std::cin >> in_vehicleRegNr;
							std::cout << "\tPlease enter colour >> \t";
							std::cin >> in_vehicleColour;
							std::cout << "\tPlease enter number of seats >> \t";
							std::cin >> in_vehicleSeats;
							std::cout << "\tPlease enter number of doors >> \t";
							std::cin >> in_carDoors;
							std::cout << "\tPlease enter type of engine >> \t";
							std::cin >> in_electric;

							Vehicle* car = new Car("", in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour, in_vehicleSeats, in_carDoors, in_electric);
							g.addVehicle(car);
							break;
						}
						case 4: {
							float in_length;
							float in_height;

							std::cout << "\tPlease enter brand >> \t";
							std::cin >> in_vehicleManufacturer;
							std::cout << "\tPlease enter model >> \t";
							std::cin >> in_vehicleModel;
							std::cout << "\tPlease enter registration/license number >> \t";
							std::cin >> in_vehicleRegNr;
							std::cout << "\tPlease enter colour >> \t";
							std::cin >> in_vehicleColour;
							std::cout << "\tPlease enter number of seats >> \t";
							std::cin >> in_vehicleSeats;
							std::cout << "\tPlease enter length in meters accordingly '\"'X.X'\"' >> \t";
							std::cin >> in_length;
							std::cout << "\tPlease enter height in meters accordingly '\"'Y.Y'\"' >> \t";
							std::cin >> in_height;

							Vehicle* bus = new Bus("", in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour, in_vehicleSeats, in_length, in_height);
							g.addVehicle(bus);
							break;
						}
						case 5: {
							int in_truckBed;
							float in_weight;

							std::cout << "\tPlease enter brand >> \t";
							std::cin >> in_vehicleManufacturer;
							std::cout << "\tPlease enter model >> \t";
							std::cin >> in_vehicleModel;
							std::cout << "\tPlease enter registration/license number >> \t";
							std::cin >> in_vehicleRegNr;
							std::cout << "\tPlease enter colour >> \t";
							std::cin >> in_vehicleColour;
							std::cout << "\tPlease enter number of seats >> \t";
							std::cin >> in_vehicleSeats;
							std::cout << "\tPlease enter number of truck beds >> \t";
							std::cin >> in_truckBed;
							std::cout << "\tPlease enter weight >> \t";
							std::cin >> in_weight;
							Vehicle* truck = new Truck("", in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour, in_vehicleSeats, in_truckBed, in_weight);
							g.addVehicle(truck);
							break;
						}
						case 6: {
							choice = 0;
							break;
						}
						case 7: {
							choice = 0;
							b = false;
							c = false;
							break;
						}
						default: {
							std::cout << "\nInvalid input! \n" << endl;
							if (choice == 0)
								choice++;
							break;
						}
						}
					} while (choice != 0);
				case 2: {
				
					cout << "\n\t\t   Enter yours vehicle registration number:  "; cin >> in_vehicleRegNr;
					g.check_out(in_vehicleRegNr);
			

					// remove_Vehicle();
					break;
				}
				case 3: {
					// Error message if no vehicle are retrieved
					std::string searchInput;

					std::cout
						<< "\n--------------------------"
						<< "\n \tSEARCH VEHICLE"
						<< "\n--------------------------"
						<< "\nPlease Enter Your Vehicles Registration Plate Number Accordingly  > abc123 < "
						<< endl;

					std::cin >> searchInput;

					if (g.garageSize != 0) {
						std::cout
							<< "--------------------------------------"
							<< "\nVehicle Found: ";
						g.searchRegNr(searchInput);
						std::cout
							<< "\n--------------------------------------"
							<< "\nYour Vehicle Is Parked At\n Parkinglot Number: "
							<< g.get_parkingLot();
						std::cout
							<< "\n--------------------------------------"
							<< endl;
					}
					break;
				}
				case 4: {
					do {
						//   b = true;
						g.display_CurrentData();
						std::cout
							<< "\n \t LIST VEHICLES MENU"
							<< "\n--------------------------"
							<< "\n \tOptions"
							<< "\n--------------------------"
							<< "\nPlease Enter Your Choice\n"
							<< "\n1. List Bicycles"
							<< "\n2. List Motorcycles"
							<< "\n3. List Cars"
							<< "\n4. List Buses"
							<< "\n5. List Trucks"
							<< "\n6. List All Vehicles"
							<< "\n7. Back To Main Menu"
							<< "\n8. Exit"
							<< endl;

						std::cin >> choice;

						if (choice < 1 || choice > 8) {
							std::cout << "\nInvalid input! \n" << endl;
							break;
						}
						if (choice != 7) {
							g.listVehicles(choice);
							//                        g.display_Counter();
						}
						if (choice == 8) {
							b = false;
							c = false;
						}
						else {
							b = false;
						}
					} while (b);
					b = true;
					break;
				}
				case 5: {
					b = true;

					do {
						std::cout
							<< "\n\t GARAGE DATA MENU"
							<< "\n--------------------------"
							<< "\n \tOptions"
							<< "\n--------------------------"
							<< "\nPlease Enter Your Choice\n"
							<< "\n1. Retrieve Garage Size"
							<< "\n2. Retrieve Number of Vacant parking lots"
							<< "\n3. Retrieve Number of Occupied parking lots"
							<< "\n4. Back To Main Menu"
							<< "\n5. Exit"
							<< endl;

						std::cin >> choice;

						switch (choice) {
						case 1: {
							std::cout
								<< "\nThis Garage Has a Capacity of: "
								<< g.newGarage << " vehicles" << endl;
							break;
						}
						case 2: {
							int vacancy = g.get_Vacancy();
							std::cout
								<< "\nNumber of Vacant Parkinglots: "
								<< vacancy << endl;
							vacancy = 0;
							break;
						}
						case 3: {
							std::cout << "Vacant lots: " << g.get_Vacancy() << endl;
							break;
						}
						case 4: {
							break;
						}
						case 5: {
							b = false;
							c = false;
							break;
						}
						default: {
							std::cout << "\nInvalid input! \n" << endl;
							b = true;
							break;
						}
						}
					} while (b && choice != 4);
					break;
				}
				case 6: {
					b = false;
					break;
				}
				case 7: {
					b = false;
					c = false;
					break;
				}
				default: {
					std::cout << "\nInvalid input! \n" << endl;
					b = true;
					break;
				}
				}
				}
			} while (b);
		}
	} while (c);

	std::cout << "\nExiting..." << std::endl;
	return 0;
}
