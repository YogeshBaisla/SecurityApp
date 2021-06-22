// Security System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	int choice = 0;
	std::cout << "**********Securit System Program********\n";
	while (choice != 3) {
		std::cout << "****************************************\n";
		std::cout << "* 1->    Change the Password           *\n";
		std::cout << "* 2->    Go to login panel to see data *\n";
		std::cout << "* 3->    Quit Program                  *\n";
		std::cout << "****************************************\n";
		std::cout << "Enter your choice :- ";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			std::fstream password;
			password.open("password.txt", ios::in);
			if (!password) {
				cout << "Some Error\n";
			}
			else {
				string current_password;
				string new_password;
				string confirm_password;
				string real_password;
				cout << "Enter your current password :- ";
				cin >> current_password;
				password >> real_password;
				password.close();
				if (real_password == current_password) {
					cout << "Enter the new password :- ";
					cin >> new_password;
					cout << "Confirm your password :- ";
					cin >> confirm_password;
					if (new_password == confirm_password)
					{
						password.open("password.txt", ios::trunc);
						password.close();
						password.open("password.txt", ios::out);
						password << new_password;
						password.close();
						password.open("password.txt", ios::in);
						password >> real_password;
						if (new_password == real_password)
						{
							cout << "Password changed succefully\n";
						}
						else {
							cout << "Error occured\n";
						}
					}
					else
					{
						cout << "Please enter same password in new and confirm box\n";
					}
				}
				else
				{
					cout << "Wrong Password\n";
				}
				password.close();
			}
			break; }
		case 2:
		{std::fstream password;
		password.open("password.txt", ios::in);
		if (!password) {
			cout << "Some Error\n";
		}
		else {
			string current_password;
			string real_password;
			cout << "Enter your  password :- ";
			cin >> current_password;
			password >> real_password;
			password.close();
			if (real_password == current_password) {
				cout << "Successfull\n";
			}
			else {
				cout << "Wrong Password\n";
			}

		}
		break;
		}
		default: {
			cout << "Please Enter Valid choice\n";
				break;
		}
		
		
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
