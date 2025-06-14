#include <iostream>
#include <cctype>

struct Credential
{
    std::string website;
    std::string username;
    std::string password;
};
void validator(std::string &password);
void addCredential(struct Credential (&info)[]);
void viewCredential(struct Credential (&info)[]);
void deteleCredential(struct Credential (&info)[]);
void passwordStrength(struct Credential (&info)[]);
int main()
{
    std::string vaultPassword;
    Credential credential[100];
    system("cls");
    validator(vaultPassword);
    std::cout << "Hello, Welcome To Boitumelo's Password Vault.\nYou are given the opportunity to save your   credentials and have them for future usage\nPress Enter To Proceed.\n";
    std::cin.get();
    system("cls");
    std::cout << "Options\n";
    std::cout << "1. Add New Credential\n2. View All Saved Credentials\n3. Delete A Credential\n4. Check Password Strength\n5. Exit\nOption:";
    int menuOption;
    std::cin >> menuOption;
    switch (menuOption)
    {
    case 1:
        addCredential(credential);
        break;
    case 2:
        viewCredential(credential);
        break;
    case 3:
        deteleCredential(credential);
        break;
    case 4:
        passwordStrength(credential);
        break;
    case 5:
        std::cout << "Thank You For Visisting.\nExiting Vault\n";
        return 0;
        break;

    default:
        break;
    }
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

void addCredential(struct Credential (&info)[])
{
    system("cls");
    std::cout << "Adding Credential";
};
void viewCredential(struct Credential (&info)[])
{
    system("cls");
    std::cout << "Viewing Credential";
};
void deteleCredential(struct Credential (&info)[])
{
    system("cls");
    std::cout << "Deleting Credential";
};
void passwordStrength(struct Credential (&info)[])
{
    system("cls");
    std::cout << "Checking Password Strength";
};