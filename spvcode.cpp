#include <iostream>
#include <cctype>
#include <iomanip>

struct Credential
{
    std::string website;
    std::string username;
    std::string password;
};

const int maxCredentials = 100;
void userAuthentication(std::string &password);
void addCredential(Credential info[], int &userCount);
void viewCredential(Credential info[], int userCount);
void deleteCredential(Credential info[], int &userCount);
void passwordStrength(Credential info[], int userCount);
void displayMenu(int &option, Credential info[], int userCount);

int main()
{
    std::string vaultPassword;
    Credential credential[maxCredentials];
    int usercount = 0, menuOption;

    system("cls");
    userAuthentication(vaultPassword);
    displayMenu(menuOption, credential, usercount);
    return 0;
}
void userAuthentication(std::string &password)
{
    while (true)
    {
        bool allDigit = true;
        bool allequal = false;
        std::cout << "Enter Your 4-digit Vault Access Code:";
        getline(std::cin, password);
        std::cout << "Press Enter To Confirm...";
        std::cin.get();
        system("cls");
        for (char c : password)
        {
            if (!isdigit(c))
            {
                allDigit = false;
                break;
            }
            if (c == c)
            {
                allequal = true;
                break;
            }
        }
        if (allDigit == false)
        {
            std::cout << "Invalid Input.\nThe Access Code You've Entered Contains Letters AND That Isn't Allowed.\nPress Enter To Restart Vault...";
            std::cin.get();
            system("cls");
        }
        else if (password.size() != 4)
        {
            std::cout << "Invalid Input.\nThe Access Code You've Entered Must Be 4-DIGITS.\nPress Enter To Restart Vault...";
            std::cin.get();
            system("cls");
        }
        /* else if (allequal == true)
        {
            std::cout << "Security Error!!.\nThe Access Code You've Entered Must Not Contain The Same Digits.\nPress Enter To Restart Vault...";
            std::cin.get();
            system("cls");
        } */

        else
        {
            std::cout << "Access Granted\nPress Enter To Continue...";
            std::cin.get();
            system("cls");
            break;
        }
    }
}
void addCredential(Credential info[], int &userCount)
{
    if (userCount > maxCredentials)
    {
        std::cout << "The Vault Is Full\nPress Enter To Continue...";
        std::cin.get();
    }
    else
    {
        std::cin.ignore();
        std::cout << "|     Adding Credentials     |\n\n";
        std::cout << "Website Name :";
        getline(std::cin, info[userCount].website);
        std::cout << std::endl;
        std::cout << "Username     : ";
        getline(std::cin, info[userCount].username);
        std::cout << std::endl;
        std::cout << "Password     : ";
        getline(std::cin, info[userCount].password);
        std::cout << std::endl;
        std::cout << "\nPress Enter To Save Credentials...";
        std::cin.get();
        system("cls");
        std::cout << "Credentials Have Been Successfully Added\nPress Enter To Return To Menu...";
        userCount++;
        std::cin.get();
        system("cls");
    }
};
void displayMenu(int &option, Credential info[], int userCount)
{
    std::cout << "Welcome To The Vault\nPress Enter To View Options...";
    std::cin.get();
    system("cls");
    do
    {

        std::cout << "1. Add Credential\n2. View Saved Credentials\n3. Delete Credential\n4. Check Password Strength\n5. Exit\n  Option:";
        std::cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            addCredential(info, userCount);
            break;
        case 2:
            system("cls");
            viewCredential(info, userCount);
            break;
        case 3:
            system("cls");
            deleteCredential(info, userCount);
            break;
        case 4:
            system("cls");
            passwordStrength(info, userCount);
            break;
        case 5:
            system("cls");
            std::cout << "Exiting Vault...";
            return;
            break;
        default:
        {
            system("cls");
            std::cout << "Invalid Input\n   Options\n1. Restart Vault\n2.Exit Vault\n Option:";
            std::cin >> option;
            switch (option)
            {
            case 1:
            {
                system("cls");
                std::cout << "Restarting Vault...\nPress Enter To Continue.";
                std::cin.get();
                displayMenu(option, info, userCount);
                break;
            }

            case 2:
            {
                system("cls");
                std::cout << "Exiting Vault...";
                return;
                break;
            }

            default:
            {

                system("cls");
                std::cout << "User INPUT ERROR\nRestarting Vault...\nPress Enter To Continue.";
                std::cin.get();
                displayMenu(option, info, userCount);
                break;
            }
            }
            break;
        }
        }

    } while (option > 0 && option < 6);
};
void viewCredential(Credential info[], int userCount)
{

    if (userCount == 0)
    {
        std::cin.ignore();
        std::cout << "The Vault Is Empty\nPress Enter To Return To Menu...";
        std::cin.get();
        system("cls");
    }
    else
    {
        std::cin.ignore();
        std::cout << "Saved Credentials\n";
        for (int i = 0; i < userCount; i++)
        {
            std::cout << (i + 1) << ".   |  " << info[i].website << "   |  " << info[i].username << "   |  " << info[i].password << std::endl;
        }
        std::cout << "\nPress Enter To Return To Menu...";
        std::cin.get();
        system("cls");
    }
}
void deleteCredential(Credential info[], int &userCount)
{
    int deleteEntry;
    if (userCount == 0)
    {
        std::cin.ignore();
        std::cout << "The Vault Is Empty\nPress Enter To Return To Menu...";
        std::cin.get();
        system("cls");
    }
    else
    {
        std::cin.ignore();
        std::cout << "Saved Credentials\n";
        for (int i = 0; i < userCount; i++)
        {
            std::cout << (i + 1) << ".   |  " << info[i].website << "   |  " << info[i].username << "   |  " << info[i].password << std::endl;
        }
        std::cout << "\nEnter The Number Of The Credentials You Want To Delete:";
        std::cin >> deleteEntry;
        deleteEntry--;

        if (deleteEntry < 0 || deleteEntry > maxCredentials)
        {
            std::cin.ignore();
            std::cout << "The Entry Entered Is Invalid\nPress Enter To Return To Menu...";
            std::cin.get();
            system("cls");
        }
        else
        {
            for (int i = deleteEntry; i < userCount; i++)
            {
                info[i] = info[i + 1];
            }

            std::cout << "Entry Has Been Successfully Deleted\nPress Enter To Return To Menu...";
            std::cin.get();
            system("cls");
            userCount--;
        }
    }
}
void passwordStrength(Credential info[], int userCount)
{
    std::cout << "strength";
};