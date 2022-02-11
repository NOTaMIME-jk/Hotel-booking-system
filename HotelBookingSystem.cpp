
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <array>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
void display();
void display_e();
void empty();
void book_guest();
void search();
void import();
void save();
void order();


//at first each room is going to be initialised to empty as the hotel has no guests.
string names[10] = { "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty", "empty" };

int x, s, i;

int main()
{
	while (s != 6) {
		char q;
		cout << "MENU\n";
		cout << "What would you like to do?\n Press:\n";
		cout << "A - To add a customer to a room\n";
		cout << "V - To view all rooms\n";
		cout << "E - To display all empty rooms\n";
		cout << "D - To delete a customer from a room\n";
		cout << "F - To find room from customer name\n";
		cout << "S - To strore program data to a text file (paracites.txt)\n";
		cout << "L - To load program data (pre-existing guest list) from a file\n";
		cout << "O - To view the customer's names ordered alphabetically \n";
		cout << "Otherwise to exit press '6'.\n";
		cin >> q;
		if (q == 'A' || q == 'a') { book_guest(); }
		else if (q == 'V' || q == 'v') { display(); }
		else if (q == 'E' || q == 'e') { display_e(); }
		else if (q == 'D' || q == 'd') { empty(); }
		else if (q == 'F' || q == 'f') { search(); }
		else if (q == 's' || q == 'S') { save(); }
		else if (q == 'L' || q == 'l') { import(); }
		else if (q == 'O' || q == 'o') { order(); }
		else if (q == '6' || q == '6') { s = 6; }
		else system("pause");
	}
return 0;
}

void book_guest() {
	cout << endl;
	cout << " Insert the room number\n";
	cin >> x;
	cout << endl;
	cout<< "Now instert the first name of the customer.\n";
	cout << "If you want to type in a guest's ";
	cout << "first and last name, please\n";
	cout<< "seperate them with a '_' symbol, or similar.\n"; 
	//indexes in C++ start at 0, hotel numberss start from one we have to confert somwere to avoid confusion.
	cin >> names[x - 1];
	cout << endl;
}

void display() {
	cout << endl;
	cout<< "These are all the guests reistered to the hotel at the moment:\n";
	for (int x = 0; x < 10; x++) {
		cout << x + 1 << ". " << names[x] << endl;
	}
	cout << endl;
}

void empty() {
	cout << endl;
	cout << "Which room would you like to edit?" << endl;
	cin >> x;
	cout << endl;
	//the index represents the room number minus 1 hence the converson.
	names[x - 1] = "empty";
	cout << "OK room " << x << " is now " << names[x - 1] << endl;
	cout << endl;
}

void display_e() {
	cout << endl;
	cout << "These rooms are empty: " << endl;
	for (int x = 0; x < 10; x++) {
		//If one of the strings in the array matches the keyword empty, this will return as true.
		if (names[x] == "empty")
			cout << x + 1 << ". " << names[x] << endl;
	}
	cout << endl;
}

void search() {
	cout << endl;
	string customer_name;
	cout << "Please type the name of the customer you're looking for\n";
	cin >> customer_name;
	for (int x = 0; x < 10; x++){
		//if the string of the array is the same as the current customer name the code will return as true.
		if (names[x] == customer_name){
			cout << names[x] << " is in room " << x + 1 << endl;
		}
		else {
			cout << "Not in this room...\n";
		}
	}
	cout << endl;
}

void save() {
	cout << endl;
	// a new file is created to store the guest list on
	ofstream theFile("paracites.txt");
	for (int x = 0; x <= 10; x++)
		theFile << names[x] << endl;
	cout << "Your guest list has been saved on to the text file 'paracites.txt'." << endl;
	cout << endl;
}

void import() {
	cout << endl;
	//the file must already exist for the if stream to be able to open it.
	ifstream theFile("paracites.txt");
	int x = 0;
	//while there are still things in 'theFile' to be thaken the while loop ill take.
	while (theFile >> names[x]) {
		//x+1 adds each guest to the next available room.
		cout <<x+1<<". "<< names[x] << endl;
		x++;
	}
	cout << endl;
	cout << "The names saved in the file 'paracites.txt' are now registered to the hotel.\n";
}

void order() {
	cout << endl;
	cout << "The names of the guests in alphabetical order are: \n";
	//The pre existing array initialises the vector necesary for the alphabetisation.
	vector <string> names(names, names + sizeof(names) / sizeof(names[0]));

	//Function 'sort' is working overtime here.
	sort(names.begin(), names.end(), [&](const string& left, const string& right) {
		size_t l_Iter = 0, r_Iter = 0; //create iterators to serve as limits (left/right).
		size_t l_Size = left.size(), r_Size = right.size(); 
		//get the ASCII code numerical representation 
		while (l_Iter != l_Size && r_Iter != r_Size) {
			//Check if the left letter doesn't equal the right letter. 
			if (left[l_Iter] != right[r_Iter]) {
				//return if the current letter has a lower numerical representation than the one to its right.
				return left[l_Iter] < right[r_Iter];
			}
			//adding one to each counter
			++l_Iter;
			++r_Iter;
		}
		//swap if the new iteration is larger than the old one.
		return l_Size < r_Size;
	});
	for (const auto& name : names) {
		cout << name << '\n';
	}
	cout << endl;
	cin.get();
	}


// References:
// JAMSA's C/C++/C# Programer's Bible, Second edition, by Kris Jamesa (PhD, MBA)
// Problem Solving with C++, Pearson International Sixth Edition, by Walter Savitch
// Yacoby on StackOverflow.com
