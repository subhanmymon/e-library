//############# c++ code for library Management Statement#############


#include <iostream>
#include <string>
using namespace std;

// maximum book will be added and issue.
const int MAX_BOOKS = 100;
const int MAX_ISSUE_RECORDS = 100;

// using array to added book capacities
string bookNames[MAX_BOOKS];
string bookSubjects[MAX_BOOKS];
int bookQuantities[MAX_BOOKS];
//string bookCategories[MAX_BOOKS];

// using array to store the issue books
string studentNames[MAX_ISSUE_RECORDS];
string issueDates[MAX_ISSUE_RECORDS];
string returnDates[MAX_ISSUE_RECORDS];
int returnTimePeriods[MAX_ISSUE_RECORDS];

// counter the detail of issue book and current book
int bookCount = 0;
int issueRecordCount = 0;

// function using to choice the users.
int getUserChoice() {
    int choice;
    cout << "Enter your choice: " <<endl;
    cin >> choice;
    
    return choice;
}

// using function to added new books
void addBook() {
    // condition checking
    if (bookCount >= MAX_BOOKS) {
        cout << "Maximum book limit reached!"<<endl;
        
    }
cout<<endl;
    // the detail of the users to get and store in a array.
    cout << "Enter Book Name: "<<endl;
    cin >> bookNames[bookCount];
    cout << "Enter Subject: "<<endl;
    cin >> bookSubjects[bookCount];
    cout << "Enter Quantity: "<<endl;
    cin >> bookQuantities[bookCount];


    // using incriments to store data
    bookCount++;
    cout << "Book added successfully!"<<endl;
    cout<<endl;
}

// using function to display the books available.
inline void displayBooks() {
    cout << "Available Books:"<<endl;
    cout<<endl;
    cout << "Subject  Name  Quantity"<<endl;

    // using loop to display the books
    for (int i = 0; i < bookCount; ++i) {
    cout << bookSubjects[i] << "    " << bookNames[i] << "    " << bookQuantities[i] <<endl;
    cout<<endl;
    }
}

// using a function to issue the book for students'

void issueBook() {
    // using condition to check there is no book.
    if (bookCount == 0) {
        cout << "No books available for issuance."<<endl;
       
    }

    // check the condition if the maxium book reached limit.
    if (issueRecordCount >= MAX_ISSUE_RECORDS) {
        cout << "Maximum issue record limit reached!"<<endl;
      
    }

    // call the function to display all aviable book for user.
    displayBooks();

    // taking the detail of issue the books from users.
    cout << "Enter Student Name: "<<endl;
    cin >> studentNames[issueRecordCount];
    cout << "Enter Issue Date (DD-MM-YYYY): "<<endl;
    cin >> issueDates[issueRecordCount];
    cout << "Enter Book Name: "<<endl;
    cin >> returnDates[issueRecordCount];
    cout << "Enter Return Time Period (in months): "<<endl;
    cin >> returnTimePeriods[issueRecordCount];

    // using increments for issue book and display the message for user.
    issueRecordCount++;
    cout << "Book issued successfully!"<<endl;
    cout<<endl;
}

// using a function to return the books
void returnBook() {
    // using condition to check at
    if (issueRecordCount == 0) {
        cout << "No books issued to return."<<endl;
        return;
    }

    string studentName;
	string bookName;
    cout << "Enter Student Name: "<<endl;
    cin >> studentName;
    cout << "Enter Book Name: "<<endl;
    cin >> bookName;

    // using loop to searching the issue books.
    for (int i = 0; i < issueRecordCount; ++i) {
        if (studentNames[i] == studentName && returnDates[i] == bookName) {
            // Shift the subsequent records to cover the returned book and decrement issue record count
            for (int j = i; j < issueRecordCount - 1; ++j) {
                studentNames[j] = studentNames[j + 1];
                issueDates[j] = issueDates[j + 1];
                returnDates[j] = returnDates[j + 1];
                returnTimePeriods[j] = returnTimePeriods[j + 1];
            }
            issueRecordCount--;
            cout << "Book returned successfully!"<<endl;
            return;
        }
    }
    // display the message if the book no found.
    cout << "No record found for the provided details." <<endl;
}

// using function to display the issue books.
void displayIssueRecords() {
    cout << "Issue Records:\n";
    cout << "Student Name ,Issue Date,Book Name ,Return Time Period"<<endl;

    // using loops to disply the issue record of each book
    for (int i = 0; i < issueRecordCount; ++i) {
        cout << studentNames[i] << "  " << issueDates[i] << "   " << returnDates[i] << "  " << returnTimePeriods[i] <<endl;
    }
}

// using function for login process
bool login() {
    string username = "cs101@giki.edu.pk";
    string password = "cs101";
    string enteredUsername, enteredPassword;

    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    return (enteredUsername == username && enteredPassword == password);
}

void developer(){

        cout << "\t\t\t\t\t\t\t\t ====================================="<< endl;
        cout << " \t\t\t\t\t\t\t\t ===        ABOUT DEVELOPER       ===" << endl;
        cout << "\t\t\t\t\t\t\t\t|=====================================" << endl;
        cout << "\t\t\t\t\t\t\t\t|    DEVELOPER: Jamshed Afridi         |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                Khan Muhammad         |" << endl;
        cout << "\t\t\t\t\t\t\t\t|                Abdul Subhan          |" << endl;
        cout << "\t\t\t\t\t\t\t\t|               Hammad Abid            |" << endl;
        cout << "\t\t\t\t\t\t\t\t|   SEMESTER:  FIRST                   |" <<endl;
        cout << "\t\t\t\t\t\t\t\t|   ROLL NO:   269,028.277,314         |" <<endl;
        cout << "\t\t\t\t\t\t\t\t|   SUBMIT TO: cs101                   |" <<endl;
        cout << "\t\t\t\t\t\t\t\t|===================================== |" << endl;

	return;
}

// main function where program executions start and call the every function to display all data.

int main() {
	
	    cout << " login Process starting  ....... !"<<endl;
	    cout <<endl;

    bool loggedIn = false;
    int attempts = 3;

    do {
        loggedIn = login();
        if (!loggedIn) {
            attempts--;
            if (attempts > 0) {
                cout << "Invalid username or password. " << attempts << " attempts remaining."<<endl;
            } else {
                cout << "Exceeded maximum login attempts. Exiting..."<<endl;
                return 1;
            }
        }
    } while (!loggedIn);
	
    int choice;
        cout<<endl;
        cout<<endl;
      
        cout << "\t\t\t\t\t\t   Welcome To Library Management System " <<endl;
        cout << endl;

    do {
        cout << "1. Add Book " << endl;
        cout << "2. Display Available Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Display Issue Records" << endl;
        cout << "6. About Developer " <<endl;
        cout << "0. Exit" << endl;
        cout << endl;

        // using switch statement to perform a function.
        
        choice = getUserChoice();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                displayIssueRecords();
                break;
            case 6:
            	developer();
            	break;
            case 0:
                cout << "Exiting..."<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again."<<endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

// the end of C++ code===========
