#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

#include"Product1.cpp"

using namespace std;


class User
{
protected:
    string username;
    string password;
    string contact;
    string address;

public:


    void inputData()
    {
        cout << "Enter your name: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter Contact: ";
        cin >> contact;
        cout << "Enter Address: ";
        cin >> address;
    }
};

////////////////////////////////////////////////////////////////

class Buyer : public User
{

public:
    Buyer()
    {
        cout << "Buyer Registration" << endl;
        inputData();
    }
    void BuyerFileData()
    {
        ofstream buyerFile("buyers.txt", ios::app);
        if (buyerFile.is_open())
        {
            buyerFile << username << " " << password << " " << contact << " " << address << " " << endl;
            buyerFile.close();
            cout << "Registration successful!" << endl;
        }
    }

    bool login()
    {
        string username2, password2;
        cout << "Buyer Login" << endl;
        cout << "Enter username: ";
        cin >> username2;
        cout << "Enter password: ";
        cin >> password2;

        ifstream buyerFile("buyers.txt");
        if (buyerFile.is_open())
        {
            string line;
            while (getline(buyerFile, line))
            {
                istringstream iss(line);
                string storedName, storedPassword, storedContactDetails, storedAddress;
                if (iss >> storedName >> storedPassword  >> storedContactDetails >> storedAddress)
                {
                    if (storedName == username2 && storedPassword == password2)
                    {
                        cout << "Login successful! \nWelcome, " << storedName << "." << endl;
                        return true;
                    }
                }
            }
            cout << "Login failed! \nPlease try again." << endl;
            return false;
        }
        else
        {
            cout << "Error: Unable to open buyers file." << endl;
            return false; // Add this return statement for the case when the file cannot be opened
        }
    }

    bool logout()
    {
        string username1, password1;
        cout << "Seller Logout: " << endl;
        cout << "Enter username: ";
        cin >> username1;
        cout << "Enter password: ";
        cin >> password1;

        ifstream SellerFile("sellers.txt");
        if (SellerFile.is_open())
        {
            string line;
            while (getline(SellerFile, line))
            {
                istringstream iss(line);
                string storedName, storedPassword, storedContactDetails, storedAddress;
                if (iss >> storedName >> storedPassword  >> storedContactDetails >> storedAddress)
                {
                    if (storedName == username1 && storedPassword == password1)
                    {
                        cout << "\nLogged Out\nThank You For using our system! " << storedName << "." << endl;
                        return true;
                    }
                }
            }
            cout << "Logout failed! \nPlease try again." << endl;
            return false;
        }
        else
        {
            cout << "Error: Unable to open sellers file." << endl;
            return false; // Add this return statement for the case when the file cannot be opened
        }
    }

    friend class SellingBuyingSystem;


};


////////////////////////////////////////////////////////////////

class Seller : public User
{


public:
    Seller()
    {
        cout << "Seller Registration" << endl;
        inputData();
    }
    void SellerFileData()
    {
        ofstream SellerFile("sellers.txt", ios::app);
        if (SellerFile.is_open())
        {
            SellerFile << username << " " << password << " " << contact << " " << address << " " << endl;
            SellerFile.close();
            cout << "Registration successful!" << endl;
        }
    }

    bool login()
    {
        string username1, password1;
        cout << "Seller Login" << endl;
        cout << "Enter username: ";
        cin >> username1;
        cout << "Enter password: ";
        cin >> password1;

        ifstream SellerFile("sellers.txt");
        if (SellerFile.is_open())
        {
            string line;
            while (getline(SellerFile, line))
            {
                istringstream iss(line);
                string storedName, storedPassword, storedContactDetails, storedAddress;
                if (iss >> storedName >> storedPassword  >> storedContactDetails >> storedAddress)
                {
                    if (storedName == username1 && storedPassword == password1)
                    {
                        cout << "\nLogin successful! \nWelcome, " << storedName << "." << endl;
                        return true;
                    }
                }
            }
            cout << "Login failed! \nPlease try again." << endl;
            return false;
        }
        else
        {
            cout << "Error: Unable to open sellers file." << endl;
            return false; // Add this return statement for the case when the file cannot be opened
        }
    }
    bool logout()
    {
        string username1, password1;
        cout << "Seller Logout: " << endl;
        cout << "Enter username: ";
        cin >> username1;
        cout << "Enter password: ";
        cin >> password1;

        ifstream SellerFile("sellers.txt");
        if (SellerFile.is_open())
        {
            string line;
            while (getline(SellerFile, line))
            {
                istringstream iss(line);
                string storedName, storedPassword, storedContactDetails, storedAddress;
                if (iss >> storedName >> storedPassword  >> storedContactDetails >> storedAddress)
                {
                    if (storedName == username1 && storedPassword == password1)
                    {
                        cout << "\nLogged Out\nThank You For using our system! " << storedName << "." << endl;
                        return true;
                    }
                }
            }
            cout << "Logout failed! \nPlease try again." << endl;
            return false;
        }
        else
        {
            cout << "Error: Unable to open sellers file." << endl;
            return false; // Add this return statement for the case when the file cannot be opened
        }
    }

    friend class SellingBuyingSystem;

};

enum class RatingChoice
{
    Yes = 1,
    No
};

class Rating
{
public:
    virtual void Give_Rating()
    {

        RatingChoice choice;
        cout << "Do you want to give a rating?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int input;
        cin >> input;

        switch (input)
        {
        case static_cast<int>(RatingChoice::Yes):
            choice = RatingChoice::Yes;
            cout << "You chose Yes." << endl;

            int stars;
            cout << "Please Enter your opinion: \n1. *\n2. **\n3. ***\n4. ****\n5. *****"<<endl;
            cin >> stars;

            if (stars >= 1 && stars <= 5)
            {
                ofstream file("ratings.txt", ios::app);
                if (file.is_open())
                {
                    string rating(stars, '*');
                    file << rating << endl;
                    cout << "Rating saved successfully." << endl;
                    file.close();
                }
                else
                {
                    cout << "Error: Unable to open file." << endl;
                }
            }
            else
            {
                cout << "Invalid number of stars. Rating must be between 1 and 5." << endl;
            }

            cout<<"Thank You For Giving Rating for QuantumQart!!\n"<<endl;

            break;
        case static_cast<int>(RatingChoice::No):
            choice = RatingChoice::No;
            //cout << "You chose No." << endl;

            cout<<"Thank You!! "<<endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            // Handle invalid choice...
            break;
        }

    }

// Function to display ratings from the file
    virtual void Show_Rating()
    {
        ifstream file("ratings.txt");
        if (file.is_open())
        {
            string line;
            int count = 1;
            cout << "Ratings:" << endl;
            while (getline(file, line))
            {
                cout << count << ". " << line << endl;
                count++;
            }
            file.close();
        }
        else
        {
            cout << "No ratings available." << endl;
        }
    }

};


////////////////////////////////////////////////////////////////


class SellingBuyingSystem: public User, public Product
{
private:

    Product *product;
    Seller *seller;
    Buyer *buyer;

public:
    void showMenu()
    {


        cout << "\n=============================" << endl;
        cout << "|       Main Menu           |" << endl;
        cout << "=============================" << endl;
        cout << "| 1. Enter as a Viewer      |" << endl;
        cout << "| 2. Enter as a Buyer       |" << endl;
        cout << "| 3. Enter as a Seller      |" << endl;
        cout << "| 4. Exit Program           |" << endl;
        cout << "=============================" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
            displayWelcomeMessage();
            cout << "===========================Main Product List:==========================\n\n";
            ProductManager::viewProductsFromFile("products.txt");
            showMenu();
            break;
        case '2':
            BuyerLoginRegistration();
            break;
        case '3':
            SellerLoginRegistration();
            break;
        case '4': // Added case to exit the program
            cout << "Thank You for using our System!" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid choice!\nPlease try again." << endl;
            showMenu();
            break;
        }
    }

    ////////////////////////////////////

    void BuyerLoginRegistration()
    {
        cout << "=========================" << endl;
        cout << "|         Buyer         |" << endl;
        cout << "=========================" << endl;
        cout << "| 1. Buyer Registration |" << endl;
        cout << "| 2. Buyer Login        |" << endl;
        cout << "| 3. Buyer Logout       |" << endl;
        cout << "| 4. Return to main menu|" << endl;
        cout << "=========================" << endl;
        cout << "\nEnter your choice: ";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
            BuyerRegistration();
            BuyerLoginRegistration();
            break;
        case '2':
            BuyerLogin();
            BuyerLoginRegistration();
            break;
        case '3':
            BuyerLogout();
            break;
        case '4':
            showMenu();
            break;
        default:
            cout << "Invalid choice." << endl
                 << "Please try again." << endl;
            BuyerLoginRegistration();
            break;
        }
    }

    void BuyerAfterLoginRegistration()
    {
        cout << "=================================" << endl;
        cout << "|      Buyer Menu               |" << endl;
        cout << "=================================" << endl;
        cout << "| 1. View main product List     |" << endl;
        cout << "| 2. View Selected Product List |" << endl;
        cout << "| 3. Select Product             |" << endl;
        cout << "| 4. Give Ratings               |" << endl;
        cout << "| 5. Show Ratings               |" << endl;
        cout << "| 6. Return to Main Menu        |" << endl;
        cout << "=================================" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            cout << "Main Product List:\n";
            ProductManager::viewProductsFromFile("products.txt");
            BuyerAfterLoginRegistration();

        }
        break;
        case '2':
        {
            cout << "Selected Product List:\n";
            ProductManager::viewProductsFromSelectedFile("SelectedProducts.txt");
            BuyerAfterLoginRegistration();

        }
        break;
        case '3':
        {
            Product newProduct;
            ProductManager productManager;
            string username,productId, contact;
            cout << "Enter Product ID: ";
            cin >> newProduct.serialNumber;
            cin.ignore();
            cout << "Enter Product Type: ";
            getline(cin, newProduct.type);
            cout << "Enter Product Name: ";
            getline(cin, newProduct.name);
            cout << "Enter Product Price: ";
            cin >> newProduct.price;
            cout << "Enter Contact Number: ";
            cin >> newProduct.buyerContact;
            cout<<"Do you want to confirm Order?"<<endl;
            cout<<"1. Yes\n2. No"<<endl;
            int ch;
            cin>>ch;
            if(ch==1)
            {
                cout<<"Enter Product ID: " <<endl;
                cin>>productId;
                cout<<"Enter username: "<<endl;
                cin>>username;
                cout<<"Enter Contact to reach you: "<<endl;
                cin>>contact;

                //productManager.serialNumber = getNextSerialNumber();
                productManager.confirmOrder(productId, username, contact);
                ProductManager::addProductToSelectedFile(newProduct);
                ProductManager::removeProductBySerialNumber("products.txt", newProduct.serialNumber);
            }
            else
            {
                BuyerAfterLoginRegistration();
            }

            break;


        }

        case '4':
        {
            Rating r;
            r.Give_Rating();
            break;
        }

        case '5':
        {
            Rating r;
            r.Show_Rating();
            break;
        }

        case '6':
        {
            showMenu();
            break;
        }

        default:
        {
            cout << "Invalid choice!" << endl
                 << "Try again." << endl;

            break;
        }

        }
    }

    void BuyerRegistration()
    {
        buyer = new Buyer;
        buyer->BuyerFileData();
        BuyerAfterLoginRegistration();
    }

    void BuyerLogin()
    {
        if (buyer->login())
        {
            BuyerAfterLoginRegistration();
        }
    }
    void BuyerLogout()
    {
        if (buyer->logout())
        {
            //BuyerAfterLoginRegistration();
            exit(0);
        }
        else
        {
            cout<<"Something Went Wrong"<<endl;
        }
    }


    ////////////////////////////////////////////////////////////////
    void SellerLoginRegistration()
    {
        cout << "============================" << endl;
        cout << "|         Seller           |" << endl;
        cout << "============================" << endl;
        cout << "| 1. Seller Registration   |" << endl;

        cout << "| 2. Seller Login          |" << endl;
        cout << "| 3. Seller Logout         |" <<endl;
        cout << "| 4. Return to main menu   |" << endl;
        cout << "============================" << endl;
        cout << "\nEnter your choice: ";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
            SellerRegistration();
            SellerLoginRegistration();
            break;

        case '2':
            SellerLogin();
            SellerLoginRegistration();
            break;
        case '3':
            SellerLogout();
            break;

        case '4':
            //SellerLoginRegistration();
            showMenu();
            break;

        default:
            cout << "Invalid choice!" << endl
                 << "Please try again." << endl;
            break;

        }
    }

    void SellerAfterLoginRegistration()
    {
        cout << "=================================" << endl;
        cout << "|          Seller Menu          |" << endl;
        cout << "=================================" << endl;
        cout << "| 1. View main product List     |" << endl;
        cout << "| 2. Add New Product to the List|" << endl;
        cout << "| 3. View selected product List |" << endl;
        cout << "| 4. Give Ratings               |" << endl;
        cout << "| 5. Show Ratings               |" << endl;
        cout << "| 6. View Orders                |" << endl;
        cout << "| 7. Return to main menu        |" << endl;
        cout << "=================================" << endl;
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            cout << "Main Product List:\n";
            ProductManager::viewProductsFromFile("products.txt");
            SellerAfterLoginRegistration();
            break;
        }
        case '2':
        {

            Product newProduct;
            newProduct.serialNumber = getNextSerialNumber();
            cout << "Enter Product Type: ";
            cin.ignore();
            getline(cin, newProduct.type);
            cout << "Enter Product Name: ";
            getline(cin, newProduct.name);
            cout << "Enter Product Price: ";
            cin >> newProduct.price;
//            cout<<"Enter Product Condition :"<<endl;
//            cin>>newProduct.NewOld;
            ProductManager::addProductToFile(newProduct);
            SellerAfterLoginRegistration();
            break;
        }
        case '3':
        {
            cout << "Selected Product List:\n";
            ProductManager::viewProductsFromSelectedFile("SelectedProducts.txt");
            SellerAfterLoginRegistration();
            break;
        }
        case '4':
        {
            Rating r;
            r.Give_Rating();
            break;
        }
        case '5':
        {
            Rating r;
            r.Show_Rating();
            break;
        }
        case '6':
        {
            ProductManager msg;
            msg.viewMessages();
            break;
        }
        case '7':
        {
            showMenu();
            break;
        }
        default:
        {
            cout << "Invalid choice!" << endl
                 << "Try again." << endl;
            SellerAfterLoginRegistration();
            break;
        }
        }
    }

    void SellerRegistration()
    {
        seller = new Seller;
        seller->SellerFileData();
        SellerAfterLoginRegistration();
    }

    void SellerLogin()
    {
        if (seller->login())
        {
            SellerAfterLoginRegistration();
        }
    }
    void SellerLogout()
    {
        if (seller->logout())
        {
            //BuyerAfterLoginRegistration();
            exit(0);
        }
        else
        {
            cout<<"Something Went Wrong"<<endl;
        }
    }




    void displayWelcomeMessage()
    {

        cout << "*                             Welcome to QuantumQart                         *" << endl;
        cout << "******************************************************************************" << endl;
        cout << "* Dear Viewer, Welcome to QuantumQart!! We are Very Much Happy to see you in *" << endl;
        cout << "* our platform! Our basic field of services is about selling  and buying. If *"<< endl;
        cout << "* you are a student of Jahangirnagar University, then you are at the right   *" << endl;
        cout << "* place. If not, then no problem, the system can be useful for you also! You *" << endl;
        cout << "* can sell your products, daily accessories which are of no use now and also *" << endl;
        cout << "* you can Buy your desired product here. Have a Good Day!!                   *" << endl;
        cout << "******************************************************************************"<< endl;
    }



};



int main()
{
    cout << "===============================================" << endl;
    cout << "|           Welcome to QuantumQart            |" << endl;
    cout << "|A new Dimension of Selling and Buying System!|" << endl;
    cout << "===============================================" << endl;

    SellingBuyingSystem SellBuySystem;
    SellBuySystem.showMenu();
    return 0;
}



