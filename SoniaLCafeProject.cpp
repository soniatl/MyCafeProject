//
//  main.cpp
//  MyFirstproject
//
//  Created by Sonia Lopchan on 9/19/24.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void displayMenu();
void adminManageInventory();

    //Menu Price & Inventory / global variables and arrays
    string coffeeItems[5] = {" Americano", " Cappucino", " Double Expresso", " Expresso", " Mocha"};
    double coffeePrices[5] = {3.0, 4.0, 3.50, 3.0, 5.0};
    int coffeeInventory[5] = {20, 20, 10, 20, 10};

    string teaItems[5] = {" Black Tea", " Ginger Tea", " Honey Lemon Tea", " Masala Tea",  " Matcha Green Tea"};
    double teaPrices[5] = {3.50, 4.50, 4.50, 5.0, 5.0};
    int teaInventory[5] = {10, 20, 20, 10, 10};

    string beverageItems[5] = {" Ginger Ale", " Iced Coffee", " Iced Tea", " Lemon Soda", " Pepsi Cola"};
    double beveragePrices[5] = {5.0, 3.50, 3.50, 3.0, 2.50};
    int beverageInventory[5] = {5, 10, 5, 10, 10};

    string pastryItems[5] = {" Almond Croissant", " Brownies", " Cinnamon Rolls", " Doughnut", " Muffin"};
    double pastryPrices[5] = {3.50, 4.50, 4.50, 5.0, 5.0};
    int pastryInventory[5] = {10, 10, 5, 20, 10};

//Function to display the menu / set rows and columns to make it readable output
void displayMenu()
{
    cout << setw(50) << left << "Welcome to Nia's Cafe!" << setw(50) << right << "Open Everyday: 7am to 5pm" << endl;
    cout << setw(50) << left << "---------------------" << setw(50) << right << "-------------------------" << endl;
    cout << endl;
    cout << "* ORDER MENU * " << "(Subject to 15% tax) " << endl;
    cout << endl;
    
    //Display coffee menu
    cout << "   COFFEE" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i <5; i++) { // create a loop to print coffee items along with price
        cout << i+1 << "." << setw(20) << left << coffeeItems[i] << setw(20) << right << "  - $" << coffeePrices[i] << endl;
    }
    cout << endl;
    
    //Display tea menu
    cout << "   TEA" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i <5; i++) {
        cout << i+1 << "." << setw(20) << left << teaItems[i] << setw(20) << right << "  - $" << teaPrices[i] << endl;
    }
    cout << endl;
    
    //Display cold beverage menu
    cout << "   COLD BEVERAGES" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i <5; i++) {
        cout << i+1 << "." << setw(20) << left << beverageItems[i] << setw(20) << right << "  - $" << beveragePrices[i] << endl;
    }
    cout << endl;
    
    //Display pastry menu
    cout << "   PASTRY" << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i <5; i++) {
        cout << i+1 << "." << setw(20) << left << pastryItems[i] << setw(20) << right << "  - $" << pastryPrices[i] << endl;
    }
    cout << endl;
}

// Function to allow the admin to manage inventory
void adminManageInventory() {
    char category;
    int itemIndex, newInventory;
    
    // Loop for multiple inventory updates
    do {
        cout << "Enter the category to update inventory (C for Coffee, T for Tea, B for Beverages, P for Pastry, E to Exit): ";
        cin >> category;

        // Process inventory updates based on category
        if (category == 'C') {
            cout << "Enter the coffee item number (1-5) to update: ";
            cin >> itemIndex;
            cout << "Enter the new inventory count for " << coffeeItems[itemIndex - 1] << ": ";
            cin >> newInventory;
            coffeeInventory[itemIndex - 1] = newInventory;
            cout << "Updated inventory for " << coffeeItems[itemIndex - 1] << ": " << coffeeInventory[itemIndex - 1] << " items." << endl;
        } else if (category == 'T') {
            cout << "Enter the tea item number (1-5) to update: ";
            cin >> itemIndex;
            cout << "Enter the new inventory count for " << teaItems[itemIndex - 1] << ": ";
            cin >> newInventory;
            teaInventory[itemIndex - 1] = newInventory;
            cout << "Updated inventory for " << teaItems[itemIndex - 1] << ": " << teaInventory[itemIndex - 1] << " items." << endl;
        } else if (category == 'B') {
            cout << "Enter the beverage item number (1-5) to update: ";
            cin >> itemIndex;
            cout << "Enter the new inventory count for " << beverageItems[itemIndex - 1] << ": ";
            cin >> newInventory;
            beverageInventory[itemIndex - 1] = newInventory;
            cout << "Updated inventory for " << beverageItems[itemIndex - 1] << ": " << beverageInventory[itemIndex - 1] << " items." << endl;
        } else if (category == 'P') {
            cout << "Enter the pastry item number (1-5) to update: ";
            cin >> itemIndex;
            cout << "Enter the new inventory count for " << pastryItems[itemIndex - 1] << ": ";
            cin >> newInventory;
            pastryInventory[itemIndex - 1] = newInventory;
            cout << "Updated inventory for " << pastryItems[itemIndex - 1] << ": " << pastryInventory[itemIndex - 1] << " items." << endl;
        } else if (category == 'E') {
            cout << "Exiting inventory management." << endl;
        } else {
            cout << "Invalid category!" << endl;
        }
    } while (category != 'E'); // Loop until user chooses to exit
}

int main(){
    
    // Define constants/strings for username login and passwords
    const string adminLogin = "NiaCafe";
    const string adminPassword = "Nia_Cafe123@";
    
    const string userLogin = "User1";
    const string userPassword = "User_Niacafe";
    
    string login, password;
    double totalPrice = 0;
    char choice;
    int itemIndex, quantity;
    
    while (true) {
        cout << "Enter your login: ";
        cin >> login;
        
        cout << "Enter your password: ";
        cin >> password;
        
        // Check if username is correct
        if (login == adminLogin && password == adminPassword) {
            cout << "You logged in as Admin" << endl;
            cout << endl;
            adminManageInventory();
            break;
        } else if (login == userLogin && password == userPassword) {
            cout << "You logged in as User" << endl;
            cout << endl;
            displayMenu();
            do {
                cout << "Hi, what would you like to order today? (B for Beverage, C for Coffee, T for Tea, P for Pastry): ";
                cin >> choice;
                
                if (choice == 'B') {
                    cout << "Enter the beverage item number (1-5): ";
                    cin >> itemIndex;
                    cout << "How many" << beverageItems[itemIndex-1] << " would you like? ";
                    cin >> quantity;
                    totalPrice += beveragePrices[itemIndex-1] * quantity;
                } else if (choice == 'C') {
                    cout << "Enter the coffee item number (1-5): ";
                    cin >> itemIndex;
                    cout << "How many" << coffeeItems[itemIndex-1] << " would you like? ";
                    cin >> quantity;
                    totalPrice += coffeePrices[itemIndex-1] * quantity;
                } else if (choice == 'T') {
                    cout << "Enter the tea item number (1-5): ";
                    cin >> itemIndex;
                    cout << "How many" << teaItems[itemIndex-1] << " would you like? ";
                    cin >> quantity;
                    totalPrice += teaPrices[itemIndex-1] * quantity;
                } else if (choice == 'P') {
                    cout << "Enter the pastry item number (1-5): ";
                    cin >> itemIndex;
                    cout << "How many" << pastryItems[itemIndex-1] << " would you like? ";
                    cin >> quantity;
                    totalPrice += pastryPrices[itemIndex-1] * quantity;
                }
                
                cout << "Do you want to order anything else? (Y/N): ";
                cin >> choice;
            } while (choice == 'Y');
            
            // Initialize variables and calculation
            const double taxRate = 0.15;
            double taxAmount = totalPrice * taxRate;
            double finalTotal = totalPrice + taxAmount;
            
            // Display total after tax
            cout << endl;
            cout << "Your Receipt" << endl;
            cout << "------------" << endl;
            cout << setw(15) << left << "Total Price: " << setw(15) << right << "$"<< totalPrice << endl;
            cout << setw(15) << left << "Tax (15%): " << setw(15) << right << "$"<< taxAmount << endl;
            cout << setw(15) << left << "Final Total: " << setw(15) << right << "$"<< finalTotal << endl;
            cout << "Thank you for your order! See you again!" << endl;
            
            return 0; // End the program after user order
            
        } else {
            cout << "Invalid login credentials!" << endl;
        }
    }
}
