#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <string.h>
#include <windows.h>
using namespace std;
void speak(string temp)
{
    string phrase = temp;
    string command = "espeak \"" + phrase + "\"";
    const char *call = command.c_str();
    system(call);
}
void date_time()
{
    time_t now = time(NULL); // return time in seconds
    char *dt = ctime(&now);
    cout << "\t Current Time and Date " << endl
         << endl;
    string temp = "Current Time and Date ";
    speak(temp);
    Sleep(500);
    cout << ":-"
         << "  " << dt << endl;
    cout << "<|-----------------------------------------------------------|>" << endl;
}
void wishme()
{
    time_t now = time(0);
    tm *time = localtime(&now);
    if (time->tm_hour < 12)
    {
        string temp = "Good Morning Sir ";
        cout << temp << endl
             << endl;
        speak(temp);
    }
    else if (time->tm_hour > 12 && time->tm_hour < 16)
    {
        string temp = "Good Afternoon Sir ";
        cout << temp << endl
             << endl;
        speak(temp);
    }
    else if (time->tm_hour >= 16 && time->tm_hour < 24)
    {
        string temp = "Good Evening Sir ";
        cout << temp << endl
             << endl;
        speak(temp);
    }
}
void change_pass();
void addPassword()
{
    // check if password is already added
    fstream io;
    io.open("password.txt", ios::in);
    string temp;
    getline(io, temp);
    io.close();
    if (!temp.empty())
    {
        cout << "\t You already have password , press enter to change  " << endl;
        speak("you already have password pree enter to change ");
        if (cin.get() == '\n')
        {
            return change_pass();
        }
    }
    string pass1;
    string pass2;
    cout << "\t || Enter the password ||" << endl;
    cout << "<|------------------------------------------------------------|>" << endl;
    Sleep(500);
    speak("Enter the password");
    cout << "-> ";
    getline(cin, pass1);
    cout << "\t || Enter the password again ||" << endl;
    cout << "<|------------------------------------------------------------|>" << endl;
    speak("Enter the password again");
    cout << "-> ";
    getline(cin, pass2);
    Sleep(300);
    if (pass1.compare(pass2) != 0)
    {
        cout << "\t || Please enter password same both time and try again ||" << endl;
        cout << "<|------------------------------------------------------------|>" << endl;
        speak("Please enter password same both time and try again");
        addPassword();
    }
    else
    {
        io.open("password.txt", ios::in | ios::out | ios::trunc);
        io << pass1;
        io.close();
        cout << "\t Adding password please wait..... " << endl;
        speak("Adding password please wait");
        Sleep(700);
        cout << "\t Password added successfully!" << endl;
        speak("password added successfully ");
    }
}
void change_pass()
{
    fstream io;
    io.open("password.txt");
    string temp, pass;
    getline(io, temp);
    io.close();
    cout << "\t || Enter the current password || " << endl;
    cout << "<|------------------------------------------------------------|>" << endl;
    speak("Enter the current password");
    cout << "-> ";
    getline(cin, pass);
    if (pass.compare(temp) == 0)
    {
        io.open("password.txt", ios::out | ios::trunc); // clear password
        io.close();
        addPassword();
    }
    else
    {
        cout << "\t Incorrect password " << endl;
        change_pass();
    }
}
bool checkpass()
{
    string pass;
    cout << endl
         << "<|------------------------------------------------------------|>" << endl;
    cout << "\t || Please enter the password to active me ||" << endl;
    speak("Please enter the password to active me");
    cout << "<|------------------------------------------------------------|>" << endl;
    cout << "-> ";
    getline(cin, pass);
    fstream io;
    io.open("password.txt", ios::in | ios::out);
    string temp;
    getline(io, temp);
    if (pass.compare(temp) != 0)
    {
        cout << "\t Incorrect password" << endl;
        speak("Incorrect password");
        cout << "<|------------------------------------------------------------|>" << endl;
        return false;
    }
    else
    {
        cout << "\t Activated Successfully!" << endl;
        speak("activated successfully");
        cout << "<|------------------------------------------------------------|>" << endl;
        return true;
    }
}
int main()
{
    wishme();
    Sleep(500);
    cout << "|=====================================================================================|" << endl;
    cout << "\t<--------------------------- WELCOME ------------------------------------->" << endl;
    speak("welcome");
    cout << "\t<------------------ I AM HOMELANDER: THE ASSISTANT ----------------------->" << endl;
    Sleep(300);
    speak("I AM HOMELANDER: THE ASSISTANT");
    cout << "\t<------------------------Created by VOUGHT-------------------------------->" << endl;
    speak("Created by VOUGHT");
    cout << "|=====================================================================================|" << endl;
    int command;
    // command for create process
    STARTUPINFO si = {0};
    PROCESS_INFORMATION pi = {0};

    do
    {
        bool flag = checkpass();
        if (flag)
        {
            do
            {
                cout << "\t How can i help you Boss" << endl;
                speak("How can i help you boss ");
                cout << "<|------------------------------------------------------------|>" << endl;
                cout << " 1. add new password" << endl;
                cout << " 2. change password" << endl;
                cout << " 3. check time and date" << endl;
                cout << " 4. open youtube " << endl;
                cout << " 5. open browser" << endl;
                cout << " 6. open notepad" << endl;
                cout << " 7. play song" << endl;
                cout << " 8. exit" << endl;
                cout << "Your Query ==>";
                cin >> command;
                cout << endl;
                cout << "<|------------------------------------------------------------|>" << endl;
                // commands
                if (command == 8)
                {
                    cout << "\t Good bye Boss , have a nice day" << endl
                         << endl;
                    speak("good bye boss have a nice day");
                    cout << "<|------------------------------------------------------------|>" << endl;
                    exit(0);
                }
                else if (command == 3)
                {
                    date_time();
                }
                else if (command == 2)
                {
                    change_pass();
                }
                else if (command == 1)
                {
                    addPassword();
                }
                else if (command == 6)
                {
                    cout << "opening notepad..." << endl;
                    speak("opening notepad");
                    cout << "<|------------------------------------------------------------|>" << endl;
                    CreateProcess(TEXT("C:\\Windows\\notepad.exe"), NULL, NULL, NULL, false, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
                    Sleep(1000);
                }
                else if (command == 4)
                {
                    system("start https://www.youtube.com/");
                    cout << "Youtube opened enjoy Boss" << endl;
                    speak("youtube opened enjoy Boss");
                    cout << "<|------------------------------------------------------------|>" << endl;
                }
                else if (command == 5)
                {
                    if (system("start https://www.google.com/"))
                    {
                        cout << "browser  opened enjoy Boss" << endl;
                        speak("browser opened enjoy Boss");
                    }
                    cout << "<|------------------------------------------------------------|>" << endl;
                }
                else if (command == 7)
                {

                    system("explorer "); // put path of song
                    cout << "Song played successfully" << endl;
                    speak("song played successfully");
                }
            } while (1);
        }
        else if (!flag)
        {
            cout << "\t try again..." << endl;
            speak("try again");
            cout << "Press 'A' to add new password Or Press 'C' to try again " << endl;
            speak("Press 'A' to add new password Or Press 'C' to try again ");
            string com;
            getline(cin, com);
            if (com == "A" || com == "a")
            {
                addPassword();
            }
            else if (com == "c" || com == "C")
            {
                checkpass();
            }
            cout << "<|------------------------------------------------------------|>" << endl;
        }
    } while (1);

    return 0;
}
