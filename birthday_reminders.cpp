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

		std::vector <std::string> vec_name(0);
		std::vector <int> vec_day(0);
		std::vector <int> vec_month(0);

		int day_min = 32;
		int month_min = 13;
		bool is_birthsday = true;
		bool is_examination = true;
		while (!in_file.eof()) {

			friends.name = "";
			friends.month = 13;

			in_file >> friends.name >> friends.year >> friends.month >> friends.day;
			
			if (friends.month == today.tm_mon && friends.day == today.tm_mday) {

				std::cout << "Today is " << friends.name << "'s bithsday!!!";
				is_birthsday = false;
			}
			else if (is_birthsday == true && friends.month == today.tm_mon && friends.day > today.tm_mday) {				

				if (friends.day < day_min) {					

					vec_name.push_back(friends.name);
					vec_day.push_back(friends.day);
					vec_month.push_back(friends.month);

				}
				else if (friends.day == day_min) {

					vec_name.push_back(friends.name);
					vec_day.push_back(friends.day);
					vec_month.push_back(friends.month);

				}

				bool is_examination = false;
				
			}
			else if (is_birthsday == true && is_examination == true && friends.month > today.tm_mon) {

				if (friends.month < month_min) {

					vec_name.push_back(friends.name);
					vec_day.push_back(friends.day);
					vec_month.push_back(friends.month);

				}
				else if (friends.month == month_min) {

					if (friends.day < vec_day[0]) {

						vec_name.push_back(friends.name);
						vec_day.push_back(friends.day);
						vec_month.push_back(friends.month);

					}
				}				
			}

			month_min = friends.month;
			day_min = friends.day;

			if (friends.name == "") {

				break;

			}
		}
		
		if (vec_name.size() > 0) {

			for (int i = 0; i < vec_name.size(); ++i) {

				std::cout << "The next birthday is a " << vec_name[i] << " month: " << vec_month[i] << " ,day: " << vec_day[i] << std::endl;

			}
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