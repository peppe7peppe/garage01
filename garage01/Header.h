#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<array>

using namespace std;



class Vehicle {
protected:
	std::string vehicleType, vehicleModel, vehicleRegNr, vehicleManufacturer, vehicleColour;
	int vehicleSeats;
public:
	Vehicle(std::string t, std::string m, std::string r, std::string c, std::string manu, int s) :
		vehicleType(t), vehicleModel(m), vehicleRegNr(r), vehicleColour(c), vehicleManufacturer(manu), vehicleSeats(s) {}
	virtual ~Vehicle() {};

	std::string get_vehicleType() { return vehicleType; }
	std::string get_vehicleRegNr() { return vehicleRegNr; }
	virtual void output() = 0;
};


class Bicycle : public Vehicle {
protected:
	std::string frame;
	int wheels;
public:
	Bicycle(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, std::string in_bikeFrame, int in_bikeWheels) : Vehicle(t, m, r, c, manu, s)
	{
		vehicleType = "Bicycle"; frame = in_bikeFrame; wheels = in_bikeWheels;
	}
	~Bicycle() {};

	void output() {
		std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
			<< "\n Manufacturer: \t" << vehicleManufacturer << "\n Seats:  \t" << vehicleSeats << "\n Frame:  \t" << frame << "\n Wheels: \t" << wheels << std::endl;
	}
};
class MotorCycle : public Vehicle {
protected:
	int gears;
	int lightHeavy;
public:
	//    MotorCycle(){} // default constructor
	MotorCycle(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, int in_gears, int in_motorClass) : Vehicle(t, m, r, c, manu, s)
	{
		vehicleType = "Motorcycle"; gears = in_gears; lightHeavy = in_motorClass;
	}
	~MotorCycle() {}

	void output() {
		std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
			<< "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Weght class: \t" << lightHeavy << "\n Gears: \t" << gears << std::endl;
	}
};

class Car : public Vehicle {
protected:
	int doors;
	std::string electric;
public:
	//    Car(){}
	Car(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, int in_carDoors, std::string in_electric) : Vehicle(t, m, r, c, manu, s)
	{
		vehicleType = "Car"; doors = in_carDoors; electric = in_electric;
	}
	~Car() {}

	void output() {
		std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
			<< "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Nr of doors: \t" << doors
			<< "\n Fuel: \t " << electric << std::endl;
	}
};
class Bus : public Vehicle {
protected:
	float hight;
	float length;
public:
	//    Bus(){}
	Bus(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, float in_height, float in_length) : Vehicle(t, m, r, c, manu, s)
	{
		vehicleType = "Bus"; length = in_length; hight = in_height;
	}
	~Bus() {}

	void output() {
		std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
			<< "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Hight: \t" << hight << " meters" << "\n length: \t" << length << endl;
	}
};
class Truck : public Vehicle {
protected:
	int truckbed;
	float weight;
public:
	//    Truck(){}
	Truck(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, int in_truckBed, float in_weight) : Vehicle(t, m, r, c, manu, s)
	{
		vehicleType = "Truck"; truckbed = in_truckBed; weight = in_weight;
	}
	~Truck() {}

	void output() {
		std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
			<< "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Number of truckbeds: \t" << truckbed << " meters" << "\n Weight: \t" << weight << endl;
	}
};




class Garage {
protected:
	std::vector<Vehicle*>garage;
public:
	std::string findType;
	int parkingLot;
	Vehicle* foundVehicle;
	int garageSize, newGarage, bicycle, motorcycle, car, bus, truck, vehicleCount;

	//    Garage(){}
	~Garage() {};

	int get_parkingLot() { return parkingLot; }

	int get_garageSize() {
		for (int i = 0; i != garage.size(); i++) {
			garageSize = i + 1;
		}
		return garageSize;
	}
	void addVehicle(Vehicle* v) { garage.push_back(v); }





	void check_out(string str)
	{
		int x = -1;
		x = searchRegNr(str);
		if (x != -1)
		{
			delete garage[x];
			garage.erase(remove(garage.begin(), garage.end(), garage[x]), garage.end());

			vehicleCount--;
			cout << "\n\t\t\t\t\t You're checked out successfully! \n";

		}

	}






	void listVehicles(int choice) {
		//        bicycle = 0; motorcycle = 0; car = 0; bus = 0; truck = 0;

		if (choice == 1)
			findType = "Bicycle";
		if (choice == 2)
			findType = "Motorcycle";
		if (choice == 3)
			findType = "Car";
		if (choice == 4)
			findType = "Bus";
		if (choice == 5)
			findType = "Truck";

		if (choice != 6) {
			for (int i = 0; i < garage.size(); i++) {
				if (garage[i]->get_vehicleType() == findType) {
					garage[i]->output();
					parkingLot = i + 1;
				}
				{
					if (findType == "Bicycle")
						bicycle++;
					if (findType == "Motorcycle")
						car++;
					if (findType == "Car")
						motorcycle++;
					if (findType == "Bus")
						bus++;
					if (findType == "Truck")
						truck++;
				}
			}
			vehicleCount = set_Counter(findType);
			std::cout
				<< "\n--------------------------------"
				<< "\nYour Vehicle Is Parked At\n Parkinglot Number: ";
			std::cout << parkingLot
				<< "\n--------------------------------"
				<< endl;
		}
		else {
			for (int i = 0; i < garage.size(); i++) {
				garage[i]->output();
				parkingLot = i + 1;
			}
		}
	}

	int set_Counter(std::string input) {
		int count = 0;
		if (input == "Bicycle")
			count = bicycle;
		if (input == "Motorcycle")
			count = car;
		if (input == "Car")
			count = motorcycle;
		if (input == "Bus")
			count = bus;
		if (input == "Truck")
			count = truck;

		return count;
	}

	void display_Counter() {
		std::cout << "\nNumber of " << findType << " Is Currently: " << vehicleCount << endl;
	}

	int searchRegNr(std::string search) {
		findType = search;
		for (int i = 0; i < garage.size(); i++) {
			if (garage[i]->get_vehicleRegNr() == findType) {
				garage[i]->output();
				return i;
			}
		}
		return 0;
	}

	int get_Vacancy() { return newGarage - get_garageSize(); }

	int createGarage(int nLots) {
		garage.reserve(nLots);
		return nLots;
	}

	void display_CurrentData() {
		std::cout << "\nMaximun Capacity: " << newGarage << "\t Current Number of Vehicles: " << get_garageSize();
	}

	void demoVehicles() {

		createGarage(5);

		Vehicle* bicycle = new Bicycle("Bicycle", "Cresent", "Mountain bike", "ABC123", "Male", 1, "Red", 2);
		addVehicle(bicycle);

		Vehicle* motorcycle = new MotorCycle("Motorbike", "Kawasaki", "Crouser", "ABC234", "Black", 1, 6, 1);
		addVehicle(motorcycle);

		Vehicle* car = new Car("Car", "Volvo", "V70", "ABC345", "Blue", 5, 4, "Electric Powered");
		addVehicle(car);

		Vehicle* bus = new Bus("", "Scania", "x90", "ABC456", "Metallic Grey", 3, 23.5, 3.4);
		addVehicle(bus);

		Vehicle* truck = new Truck("", "Ford", "X", "ABC567", "White", 3, 2, 10);
		addVehicle(truck);
	}
};