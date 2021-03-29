#pragma once
#include<iostream>
#include "Hotel.h"

int main(int argc, char **argv)
{
	char menu_selection;
	char user_choice;
	
	Hotel hotel;
	
	hotel.create_rooms();

	#pragma region Menu Selection
	while (true)
	{
		std::cout << "What would you like to do?\n"
			"V : View all rooms\n"
			"E : Display the empty rooms\n"
			"A : Add a customer to a room\n"
			"D : Delete a customer from a room\n"
			"F : Find a room by customer name\n"
			"O : Order rooms alphabetically by the main customer's name\n"
			"S : Save data to file\n"
			"L : Load data from file\n";

		std::cin >> user_choice;

		menu_selection = toupper(user_choice);

		switch (menu_selection)
		{
		case 'V':
			std::system("CLS");
			hotel.display_rooms();
			break;
		case 'A':
			std::system("CLS");
			hotel.add_customer_to_room();
			break;
		case 'E':
			std::system("CLS");
			hotel.display_empty_rooms();
			break;	  
		case 'D':	  
			std::system("CLS");
			hotel.delete_customer_from_room();
			break;	  
		case 'F':	  
			std::system("CLS");
			hotel.find_room_by_name();
			break;	  
		case 'S':	  
			std::cout << "S\n";
			break;	  
		case 'L':	  
			std::cout << "L\n";
			break;	  
		case 'O':	  
			std::system("CLS");
			hotel.order_rooms_by_name();
			break;
		default:
			std::cout << "Error : Unknown Command\n";
			break;
		}
	}
	#pragma endregion

    int a; std::cin >> a; // Debug Freeze
    return EXIT_SUCCESS;
}

