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
void validator(std::string &password);
void addCredential(Credential info[], int &userCount);
void viewCredential(Credential info[], int &userCount);
void deteleCredential(struct Credential (&info)[]);
void passwordStrength(struct Credential (&info)[]);
int main()
{

    std::string vaultPassword;
    Credential credential[maxCredentials];
    int usercount = 0;
    system("cls");
    validator(vaultPassword);
    int menuOption, flowOption;
    std::cout << "Hello, Welcome To Boitumelo's Password Vault.\nYou are given the opportunity to save your credentials and have them for future usage\nPress Enter To Proceed...\n";

    std::cin.get();

    do
    {
        system("cls");

        std::cout << "Welcome to Your Vault\n";

        std::cout << "Options\n";
        std::cout << "1. Add New Credential\n2. View All Saved Credentials\n3. Delete A Credential\n4. Check Password Strength\n5. Exit\nOption:";

        std::cin >> menuOption;
        switch (menuOption)
        {
        case 1:
            addCredential(credential, usercount);
            break;
        case 2:
            viewCredential(credential, usercount);
            break;
        case 3:
            deteleCredential(credential);
            break;
        case 4:
            passwordStrength(credential);
            break;
        case 5:
            system("cls");
            std::cout << "Thank You For Visisting.\nExiting Vault\n";
            return 0;
            break;

        default:
            system("cls");
            std::cout << "Invalid Input\n1. Restart Vault\n2. Exit Vault\n";
            std::cout << "Option:";
            std::cin >> flowOption;
            if (flowOption == 1)
            {
                system("cls");
                std::cout << "Restarting Vault...\n";
                std::cout << "Press Enter To Continue...";
                std::cin.ignore(); // Clear the newline character left in the input buffer
                std::cin.get();    // Wait for user to press Enter

                return main();
                break;
            }
            else if (flowOption == 2)
            {
                system("cls");
                std::cout << "Thank You For Visisting.\nExiting Vault...\n";
                return 0;
                break;
            }

            else
            {
                system("cls");
                std::cout << "Invalid Input\n";
                break;
            }
        }
    } while (menuOption < 5 && menuOption > 0);

    return 0;
}
void validator(std::string &password)
{

    while (true)
    {

        std::cout << "Enter Your Vault Password:";
        std::getline(std::cin, password);
        if (password.length() > 7)
        {
            password[0] = toupper(password[0]);
            break;
        }
        else
        {
            system("cls");
            std::cout << "Password Must Have More Than 7 Characters\n";
            validator(password);
            break;
        }
    }
}

void addCredential(Credential info[], int &userCount)
{
    if (userCount >= maxCredentials)
    {
        std::cout << "Vault is full, cannot add more credentials.\n";
        return;
    }
    else
    {
        system("cls");
        std::cout << "Adding Credential\n";
        std::cout << "You can add up to " << maxCredentials << " credentials.\n";
        std::cout << "Current number of credentials: " << userCount << "\n";
        std::cout << "Press Enter to continue...\n";
        std::cin.get(); // Wait for user to press Enter
        system("cls");
        std::cin.ignore();
        std::cout << std::setw(20) << "Adding Credential\n";
        std::cout << "Enter Website:";
        getline(std::cin, info[userCount].website);
        std::cout << std::endl;
        std::cout << "Enter Username:";
        getline(std::cin, info[userCount].username);
        std::cout << std::endl;
        std::cout << "Enter Password:";
        getline(std::cin, info[userCount].password);
        std::cout << std::endl;
        userCount++;

        std::cout << "Credential Added Successfully!\n";
        std::cout << "Press Enter To Continue...";
        std::cin.get(); // Wait for user to press Enter
    }
}
void viewCredential(Credential info[], int &userCount)
{
    system("cls");
    if (userCount == 0)
    {
        std::cout << "Vault Is Empty Bro";
        return;
    }

    else
    {
        std::cout << "Saved Credentials";
        for (auto i = 0; i < userCount; i++)
        {
            std::cout << "Credential " << (i + 1) << ":\nWebsite: " << info[i].website << "\nUsername: " << info[i].username << "\nPassword: " << info[i].password;
            std::cout << std::endl;
        }
    }
}
void deteleCredential(struct Credential (&info)[])
{
    system("cls");
    std::cout << "Deleting Credential";
}
void passwordStrength(struct Credential (&info)[])
{
    system("cls");
    std::cout << "Checking Password Strength";
}