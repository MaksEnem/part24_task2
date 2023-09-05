#include <iostream>
#include <vector>

void friends_birthdays_initialization(std::string& name_friend, std::vector <std::string>& name, std::vector <int>& day, std::vector <int>& month, std::vector <int>& year) {

	int day_Bith;
	int month_Bith;
	int year_Bith;

	do {

		std::cout << "Enter a friend's name: ";
		std::cin >> name_friend;

		if (name_friend != "end") {

			std::cout << "Enter the full date of birth, including the month and year, in the format year/month/day:\n";
			std::cin >> year_Bith >> month_Bith >> day_Bith;

			name.push_back(name_friend);
			day.push_back(day_Bith);
			month.push_back(month_Bith);
			year.push_back(year_Bith);
		}

	} while (name_friend != "end");
}

int main() {

	std::string name_friend;
	
	std::vector <std::string> name(0);
	std::vector <int> day(0); 
	std::vector <int> month(0);
	std::vector <int> year(0);

	friends_birthdays_initialization(name_friend, name, day, month, year);
	
	for (int i = 0; i < day.size(); ++i) {

		std::cout << name[i] << " " << year[i] << "/" << month[i] << "/" << day[i] << std::endl;

	}

}