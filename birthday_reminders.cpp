#include <iostream>
#include <fstream>
#include <vector>

struct data {

	std::string name;
	int year;
	int month;
	int day;

};

void friends_birthdays_initialization(data& friends) {

	do {

		std::cout << "Enter a friend's name: ";
		std::cin >> friends.name;

		if (friends.name != "end") {	

			std::cout << "Enter the full date of birth, including the month and year, in the format year/month/day:\n";
			std::cin >> friends.year >> friends.month >> friends.day;	

			std::ofstream out_file("save.txt", std::ios::app);

			if (out_file.is_open()) {

				out_file << friends.name << " " << friends.year << " " << friends.month << " " << friends.day << std::endl;

				out_file.close();

			}
			else {

				std::cout << "WARNING!\n";
				std::cout << "ERROR!!!\n";
				std::cout << "File is not open\n";

			}
		}

	} while (friends.name != "end");
}

void load_friends_birthsday(data& friends, std::tm& today) {

	std::ifstream in_file("save.txt");

	if (in_file.is_open()) {

		
		while (!in_file.eof()) {

			friends.name = "";
			friends.month = 13;

			in_file >> friends.name >> friends.year >> friends.month >> friends.day;
			
			if (friends.month == today.tm_mon && friends.day == today.tm_mday) {

				std::cout << "Today is " << friends.name << "'s bithsday!!!";

			}



			if (friends.name == "") {

				break;

			}

			/*std::cout << friends.name<< ": " << friends.year << "/" << friends.month << "/" << friends.day << std::endl;*/

			
			
		}
		
		in_file.close();

	}
	else {

		std::cout << "WARNING!\n";
		std::cout << "ERROR!!!\n";
		std::cout << "File is not open\n";

	}
}

void experiment(std::tm& today){


	std::cout << today.tm_mon << " " << today.tm_mday << std::endl;
}


int main() {	
	
	data friends;	

	friends_birthdays_initialization(friends);
	
	std::time_t data = std::time(nullptr);
	std::tm today;
	localtime_s(&today, &data);
	today.tm_year = today.tm_year + 1900;
	++today.tm_mon;		
	
	load_friends_birthsday(friends, today);

	

	
}