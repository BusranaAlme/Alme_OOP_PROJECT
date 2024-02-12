#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

//#include"product.cpp"

using namespace std;
class Product
{
public:
    int serialNumber;
    string type;
    string name;
    double price;
    int buyerContact;
    //Condition NewOld;

    Product(int serialNumber, const string& type, const string& name, double price, int buyerContact) :
        serialNumber(serialNumber), type(type), name(name), price(price), buyerContact(buyerContact) {}

    Product() : serialNumber(0), price(0), buyerContact(0) {}
};

class ProductManager: public Product
{
public:
    // Function to add a product record to the file
    static void addProductToFile(const Product& product)
    {
        ofstream outFile("products.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << product.serialNumber << ',' << product.type << ',' << product.name << ',' << product.price << '\n';
            cout << "Product added successfully! Product ID : " << product.serialNumber << '\n';
            outFile.close();
        }
        else
        {
            cout << "Error opening the file for writing.\n";
        }
    }

    // Function to add a product to the selected product list file
    static void addProductToSelectedFile(const Product& product)
    {
        ofstream outFile("SelectedProducts.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << product.serialNumber << ',' << product.type << ',' << product.name << ',' << product.price << ',' << product.buyerContact <<'\n';
            cout << "Thank You For Ordering ! " << '\n';
            outFile.close();
        }
        else
        {
            cout << "Error opening the file for writing.\n";
        }
    }

    // Function to display all product records from the file as a table
    static void viewProductsFromFile(const string& fileName)
    {
        ifstream inFile(fileName);
        if (inFile.is_open())
        {
            string line;
            cout << setw(15) << "Product ID" << setw(15) << "Type" << setw(20) << "Name" << setw(10) << "Price" << '\n';
            cout << string(60, '-') << '\n';
            while (getline(inFile, line))
            {
                istringstream iss(line);
                string token;
                int colCount = 0;
                while (getline(iss, token, ','))
                {
                    switch (colCount)
                    {
                    case 0:
                        cout << setw(15) << token;
                        break;
                    case 1:
                        cout << setw(15) << token;
                        break;
                    case 2:
                        cout << setw(20) << token;
                        break;
                    case 3:
                        cout << setw(10) << token;
                        break;
                    default:
                        break;
                    }
                    colCount++;
                }
                cout << '\n';
            }
            inFile.close();
        }
        else
        {
            cout << "Error opening the file for reading.\n";
        }
    }

    // Function to display all selected product records from the file as a table
    static void viewProductsFromSelectedFile(const string& fileName)
    {
        ifstream inFile(fileName);
        if (inFile.is_open())
        {
            string line;
            cout << setw(15) << "Product ID" << setw(15) << "Type" << setw(20) << "Name" << setw(15) << "Price" << setw(20) << "Contact" << '\n';
            cout << string(85, '-') << '\n';
            while (getline(inFile, line))
            {
                istringstream iss(line);
                string token;
                int colCount = 0;
                while (getline(iss, token, ','))
                {
                    switch (colCount)
                    {
                    case 0:
                        cout << setw(15) << token;
                        break;
                    case 1:
                        cout << setw(15) << token;
                        break;
                    case 2:
                        cout << setw(20) << token;
                        break;
                    case 3:
                        cout << setw(15) << token;
                        break;
                    case 4:
                        cout << setw(20) << token;  // Display the Seller's contact in a separate column
                        break;
                    default:
                        break;
                    }
                    colCount++;
                }
                cout << '\n';
            }
            inFile.close();
        }
        else
        {
            cout << "Error opening the file for reading.\n";
        }
    }

    // Function to remove a product record from the file based on serial number
    static void removeProductBySerialNumber(const string& fileName, int serialNumber)
    {
        ifstream inFile(fileName);
        if (inFile.is_open())
        {
            vector<string> lines;
            string line;
            while (getline(inFile, line))
            {
                size_t commaPos = line.find(',');
                int currentSerialNumber = stoi(line.substr(0, commaPos));
                if (currentSerialNumber != serialNumber)
                {
                    lines.push_back(line);
                }
            }
            inFile.close();

            ofstream outFile(fileName);
            if (outFile.is_open())
            {
                for (const auto& l : lines)
                {
                    outFile << l << '\n';
                }
                cout << "The seller will contact you very soon!\n";
                outFile.close();
            }
            else
            {
                cout << "Error opening the file for writing.\n";
            }
        }
        else
        {
            cout << "Error opening the file for reading.\n";
        }
    }

    int getNext()
{
    ifstream inFile("textMessages.txt");
    int next = 1; // Default starting serial number

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            istringstream iss(line);
            string token;
            getline(iss, token, ',');
            int currentSerialNumber = stoi(token);
            if (currentSerialNumber >= next)
            {
                next = currentSerialNumber + 1;
            }
        }
        inFile.close();
    }
    else
    {
        cout << "Error opening the file for reading.\n";
        return -1;
    }

    return next;
}
void confirmOrder(const string& productId, const string& username, const string& contact) {
    // Display confirmation message in the console
    string cnt=contact;
    cout << "Your Order has been Confirmed!" << endl;

    // Get today's date
    time_t now = time(0);
    tm* localTime = localtime(&now);
    string todaysDate = to_string(localTime->tm_year + 1900) + "-" +
                        to_string(localTime->tm_mon + 1) + "-" +
                        to_string(localTime->tm_mday);

    // Display and save order details
    cout << "Order Confirmed by the " << username << " With product ID: " << productId
         << " has been placed on " << todaysDate << endl;

    // Save order details to the "Messages" file
    ofstream messagesFile("Messages.txt", ios::app);
    if (messagesFile.is_open()) {
        // Save the order details with a serial number
        //static int serialNumber = 1;
        //messagesFile << "Serial No: " << serialNumber++ << "\n";
        messagesFile << "Order Confirmed by the " << username << " With product ID: " << productId
                     << " has been placed on " << todaysDate << "Buyer contact: "<<cnt <<"\n\n";

        // Close the file
        messagesFile.close();
    } else {
        cerr << "Error: Unable to open Messages.txt for writing." << endl;
    }
}




void viewMessages() {
    ifstream messagesFile("MessagesText.txt");
    if (messagesFile.is_open()) {
        string line;
        int cnt = 1;
            cout << "Orders:" << endl;
            while (getline(messagesFile, line))
            {
                cout << cnt << ". " << line << endl;
                cnt++;

            }
    }
    else
    {
        cerr << "Error: Unable to open MessagesText.txt for reading." << endl;
    }
}

};


// Function to get the next available serial number
int getNextSerialNumber()
{
    ifstream inFile("products.txt");
    int nextSerialNumber = 1; // Default starting serial number

    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            istringstream iss(line);
            string token;
            getline(iss, token, ',');
            int currentSerialNumber = stoi(token);
            if (currentSerialNumber >= nextSerialNumber)
            {
                nextSerialNumber = currentSerialNumber + 1;
            }
        }
        inFile.close();
    }
    else
    {
        cout << "Error opening the file for reading.\n";
        return -1;
    }

    return nextSerialNumber;
}

