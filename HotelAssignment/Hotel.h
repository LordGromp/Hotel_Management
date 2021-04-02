#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

class Hotel
{
protected:
	std::vector<std::tuple<int, char ,std::string, int>> m_hotel_rooms; // Room Number, is occupied, Name of main customer, Number of people staying in room 
	std::regex m_search_customer;
	std::string m_name_of_occupant = "Empty";
	int m_number_of_customers = 0;
	int m_room_number = 0;
	char m_is_occupied = 'N';

private:
#pragma region String Comparison
	static bool comparison_of_strings(const std::tuple<int, char, std::string, int>& a, //Compare funtion for [order_rooms_by_name] function.
									  const std::tuple<int, char, std::string, int>& b)
	{
		return (std::get<2>(a) > std::get<2>(b));
	}
#pragma endregion
public :
#pragma region Create Rooms
	void create_rooms()
	{
		for (int i = 1; i < 11; i++)
		{
			m_room_number = i;
			m_hotel_rooms.push_back(std::make_tuple(m_room_number, m_is_occupied, m_name_of_occupant, m_number_of_customers));
		}
	}
#pragma endregion
	
#pragma region Display Rooms
	void display_rooms()
	{
for (const auto& i : m_hotel_rooms)
{
	std::cout << "Room " << std::get<0>(i) << "| Room occupied: " << std::get<1>(i) << "| Name: " << std::get<2>(i) << "| Number of occupants: " << std::get<3>(i) << std::endl;
}
std::cout << "\n";
	}
#pragma endregion

#pragma region Display Empty Rooms
	void display_empty_rooms()
	{
		for (const auto& i : m_hotel_rooms)
		{
			if (std::get<1>(i) == 'N')
			{
				std::cout << "Room " << std::get<0>(i) << " is empty.\n";
			}
		}
		std::cout << std::endl;
	}
#pragma endregion

#pragma region Find Room by Name
	void find_room_by_name()
	{
		std::string user_input;
		unsigned customer_found = 0;

		std::cout << "Please enter the name of the customer you are looking for: ";
		std::cin >> user_input;

		std::cout << std::endl;
		for (const auto& i : m_hotel_rooms)
		{
			m_search_customer = std::regex(std::get<2>(i), std::regex_constants::ECMAScript | std::regex_constants::icase);

			if (std::regex_search(user_input, m_search_customer))
			{
				std::cout << "Customer found in room " << std::get<0>(i) << std::endl;
				customer_found = customer_found + 1;
			}

		}
		if (customer_found == 0)
		{
			std::cout << "Customer NOT found." << std::endl;
		}
		std::cout << std::endl;
	}
#pragma endregion

#pragma region Add Customer to Room
	void add_customer_to_room()
	{
		std::tuple<int, char, std::string, int> temp_room;
		int temp_room_number;
		char temp_is_occupied;
		std::string temp_customer_name;
		int temp_number_of_customers;


		std::cout << "Enter the room number you wish to add the customer to: ";
		std::cin >> temp_room_number;

		for (const auto& i : m_hotel_rooms)
		{
			if ((std::get<0>(i) == temp_room_number) && (std::get<1>(i) == 'N'))
			{
				std::cout << "Room is available." << std::endl;

				temp_is_occupied = 'Y';

				std::cout << "Please enter the name of the main customer: " << std::endl;
				std::cin >> temp_customer_name;

				std::cout << "Please enter then number of customers that will be staying in the room: " << std::endl;
				std::cin >> temp_number_of_customers;

				auto insert_it = m_hotel_rooms.begin() + (temp_room_number);

				temp_room = std::make_tuple(std::get<0>(i), temp_is_occupied, temp_customer_name, temp_number_of_customers);

				m_hotel_rooms.insert(insert_it, temp_room);
				m_hotel_rooms.erase((m_hotel_rooms.begin() + (temp_room_number - 1)));
				break;
			}
			else if ((std::get<0>(i) == temp_room_number) && (std::get<1>(i) == 'Y'))
			{
				std::cout << "Room is unavailable." << std::endl;
			}
		}
		std::cout << std::endl;
	}
#pragma endregion

#pragma region Delete Customer from Room
	void delete_customer_from_room()
	{
		std::tuple<int, char, std::string, int> temp_room;
		int temp_room_number;
		char temp_is_occupied;
		std::string temp_customer_name = "Empty";
		int temp_number_of_customers = 0;

		std::cout << "Enter the room number you wish to remove the customer from: ";
		std::cin >> temp_room_number;

		for (const auto& i : m_hotel_rooms)
		{
			if ((std::get<0>(i) == temp_room_number) && (std::get<1>(i) == 'Y'))
			{
				std::cout << "Room is has been cleared" << std::endl;

				temp_is_occupied = 'N';

				auto insert_it = m_hotel_rooms.begin() + (temp_room_number);

				temp_room = std::make_tuple(std::get<0>(i), temp_is_occupied, temp_customer_name, temp_number_of_customers);

				m_hotel_rooms.insert(insert_it, temp_room);
				m_hotel_rooms.erase((m_hotel_rooms.begin() + (temp_room_number - 1)));
				break;
			}
			else if ((std::get<0>(i) == temp_room_number) && (std::get<1>(i) == 'N'))
			{
				std::cout << "Room is already empty." << std::endl;
			}
		}
		std::cout << std::endl;
	}
#pragma endregion

#pragma region Order Rooms by Customers Name
	void order_rooms_by_name()
	{
		std::sort(m_hotel_rooms.begin(), m_hotel_rooms.end(), comparison_of_strings);
		
		display_rooms();
	}
#pragma endregion
};