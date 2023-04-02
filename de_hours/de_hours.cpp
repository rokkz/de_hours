#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

int logging()
{
    using namespace std;
    cout << "Login: ";
    string userLogin;
    cin >> userLogin;
    cout << "Password: ";
    string userPassword;

    //HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    //DWORD mode = 0;
    //GetConsoleMode(hStdin, &mode);
    //SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
 
    char ch;
    while ((ch = _getch()) != 13) //enter type
    {
        userPassword += ch;
        std::cout << '*';
    }

    int result;
    if ((userLogin == "admin") && (userPassword == "dupa"))
    {
        result = 1;
        cout << endl << "Zalogowano poprawnie!" << endl;
        system("cls");
    }
    else
    {
        cout << endl << "Blad logowania! Niepoprawne dane" << endl;
        result = -1;
    }

    return result;
}

int userData()
{
    using namespace std;
    cout << "test" << endl;
    int testowy;
    cin >> testowy;
    return testowy;
}

int main()
{
    using namespace std;
    cout << "Hours manager" << endl;
    
    int loggingResult = 0;
    loggingResult = logging();
    
    if (loggingResult == -1)
    {
        cout << endl << "Czy chcesz zalogowac sie ponownie? [Y], [N]" << endl;
        int relogCh;
        relogCh = _getch();
        relogCh = toupper(relogCh);
        if (relogCh == 'Y')
        {
            system("cls");
            int loggingResult = logging();
        }
        else
        {
            return 0;
        }
    }

    int menuDecision = 0;
    while (menuDecision != 5)
    {
        cout << "Menu" << endl << "1. Dane uzytkownika\n2. Wprowadz godziny\n3. Zarzadzaj godzinami\n4. Historia\n5. Wyjscie" << endl;
        menuDecision = _getch();

        switch (menuDecision)
        {
        case '1':
            menuDecision = userData();
        default:
            system("cls");
            break;
        }
    }
    

    return 0;
}


