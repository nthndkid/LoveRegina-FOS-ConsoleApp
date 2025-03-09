#ifndef FOS_FEATURES_H
#define FOS_FEATURES_H
using namespace std;
namespace features
{
    const int MAX_ORDERS = 5; // Maximum number of orders

    struct MenuInfo //Structure for Customer's Information
    {
        int OrderMethod, OrderQuantity;
        string PhoneNumber, Name, Address, PickUpLocation, Date;
        char Order;
    }menu;

    struct OrderSystem // Structure to Function the System
    {
        MenuInfo MaxOrders[MAX_ORDERS];
        int NumOfOrders, TotalOrder=0, FoodTotal=0;
        char AddOrder, RenewOrder;
    }ordering;

    void LoadingScreen()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h
        
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t Loading ";

        for(int i = 0; i < 5; i++) // Loop to display a loading animation
        {
            cout << " . ";
            Sleep(200); // Pause the execution for 200 milliseconds
        }

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); //Set the Text color to Green
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t THANK YOU FOR WAITING!"; 
        Sleep(300); system("cls"); // Pause the execution for 300 milliseconds and then clear the screen
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }

    void HomePage()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout << "\n\n\t\t\t\t\t\t   ===============================================";
        cout << "\n\t\t\t\t\t\t      LOVE,   REGINA   FOOD   ORDERING  SYSTEM ";
        cout << "\n\t\t\t\t\t\t   ===============================================\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE); //Set the Text color to Blue
        cout << "\n\t\t\t\t\t\t       ===========    =========      ==========  ";
        cout << "\n\t\t\t\t\t\t       ===========   ===========   ===========   ";
        cout << "\n\t\t\t\t\t\t       ===           ===     ===   ====          ";
        cout << "\n\t\t\t\t\t\t       ========      ===     ===   =======       ";
        cout << "\n\t\t\t\t\t\t       =======       ===     ===     ========    ";
        cout << "\n\t\t\t\t\t\t       ===           ===     ===        ======   ";
        cout << "\n\t\t\t\t\t\t       ===           ===     ===          ====   ";
        cout << "\n\t\t\t\t\t\t       ===           ===========   ===========   ";
        cout << "\n\t\t\t\t\t\t       ===            =========   ==========    \n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout << "\n\t\t\t\t\t\t   ===============================================";
        cout << "\n\t\t\t\t\t\t              Created  by  J.U.L.I.E.T";
        cout << "\n\t\t\t\t\t\t   ===============================================\n\n";
        cout << "\n\t\t\t\t\t\t\t======================================\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE); // Set the text to blue
        cout << "\t\t\t\t\t\t\t    ALL PRODUCTS ARE MADE TO ORDER! ";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout << "\n\t\t\t\t\t\t\t======================================\n";
    }

    void OrderPage()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout << "\n\n\n\t\t\t\t\t\t\t    ===================================";
        cout << "\n\t\t\t\t\t\t\t      CHOOSE   AN   ORDER   METHOD :";
        cout << "\n\t\t\t\t\t\t\t    ===================================";
        cout << "\n\n\t\t\t\t\t\t\t        [1]    -     ";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE + FOREGROUND_RED); // Set the text to violet
        cout << "PICK UP";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout << "\n\n\t\t\t\t\t\t\t        [2]    -     ";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN + FOREGROUND_RED); // Set the text to light yellow
        cout <<  "VIA COURIER";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout << "\n\n\t\t\t\t\t\t\t    ===================================";
        cout << "\n\n\t\t\t\t\t\t\t          ENTER  YOUR  CHOICE : ";
    }

    void PickUpPage(MenuInfo& menu)
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h
        bool ContactIsValid = false; //Intialize bool to check wheter the contact numbers are valid
        bool LocIsValid = false; //Initialize bool to check wheter the location is valid

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE + FOREGROUND_RED); // Set the text to Red
        cout << "\n\n\n\t\t\t\t\t\t     FILL UP INFORMATION FOR  PICK UP";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default

        cout << "\n\t\t\t\t\t\t ========================================\n";
        cout << "\n\t\t\t\t\t\t\t NAME : "; 
        getline(cin, menu.Name); 

        cout << "\n\t\t\t\t\t\t    ===================================\n\n";
        cout << "\t\t\t\t\t\t        CHOOSE A PICK-UP LOCATION : \n\n";
        cout << "\t\t\t\t\t\t                  DOST \n";  
        cout << "\t\t\t\t\t\t               SM BICUTAN \n";  
        cout << "\t\t\t\t\t\t            WALTERMART BICUTAN \n";

            while(!LocIsValid) 
            {
                cout << "\n\t\t\t\t\t\t        ENTER LOCATION : "; 
                getline(cin, menu.PickUpLocation);

                transform(menu.PickUpLocation.begin(), menu.PickUpLocation.end(), menu.PickUpLocation.begin(), ::tolower); // Convert the characters in to lowercase

                    if(menu.PickUpLocation == "dost" || menu.PickUpLocation == "sm bicutan" || menu.PickUpLocation == "waltermart bicutan") //check whether the characters are same while in lowercase
                    {
                        LocIsValid = true;
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to Red
                        cout << "\n\t\t\t\t\t\t\t Invalid Location."; 
                        cout << "\n\t\t\t\t\t\t Please choose the specific location above.";
                        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
                    }
            }

        cout << "\n\t\t\t\t\t\t    ===================================";
            while (!ContactIsValid)
            {
                cout << "\n\n\t\t\t\t\t\t\tCONTACT NUMBER : ";
                getline(cin, menu.PhoneNumber);

                    if (menu.PhoneNumber.size() == 11 && menu.PhoneNumber.find_first_not_of("0123456789") == string::npos) //find_first_not_of() function is used to check if the phone number contains only digits.
                    {                                                                                                          //It returns string::npos if any character other than a digit is found.
                        ContactIsValid = true;
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to Red
                        cout << "\n\t\t\t\t\t\t\t Invalid phone number."; 
                        cout << "\n\t\t\t\t\t\t Please make sure it has exactly 11 digits.";
                        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
                    }
            }
        
        cout << "\n\t\t\t\t\t\t ========================================\n";
        cout << "\n\t\t\t\t\t\t     "  << system("pause");
    }

    void CourierPage(MenuInfo& menu) 
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h
        bool ContactIsValid = false;

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN + FOREGROUND_RED); // Set the text to Red
        cout << "\n\n\n\t\t\t\t\t\t          FILL UP INFORMATION FOR COURIER\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout << "\t\t\t\t\t\t ==================================================\n";
        cout << "\n\t\t\t\t\t\t  NAME : "; 
        getline(cin, menu.Name);
        cout << "\n\t\t\t\t\t\t ==================================================\n";
        cout << "\n\t\t\t\t\t\t  ADDRESS : "; 
        getline(cin, menu.Address);
        cout << "\n\t\t\t\t\t\t ==================================================\n";
        while (!ContactIsValid)
            {
                cout << "\n\t\t\t\t\t\t  CONTACT NUMBER : ";
                getline(cin, menu.PhoneNumber);

                    if (menu.PhoneNumber.size() == 11 && menu.PhoneNumber.find_first_not_of("0123456789") == string::npos) //find_first_not_of() function is used to check if the phone number contains only digits.
                    {                                                                                                      //It returns string::npos if any character other than a digit is found.
                        ContactIsValid = true;
                    }
                    else
                    {
                        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to red
                        cout << "\n\t\t\t\t\t\t\t     Invalid phone number."; 
                        cout << "\n\t\t\t\t\t\t     Please make sure it has exactly 11 digits.\n";
                        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
                    }
            }
        cout << "\n\t\t\t\t\t\t ==================================================\n";
        cout << "\n\t\t\t\t\t\t           "; system("pause"); 
    }

    void DefaultOrderMethod() 
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t WARNING! "<<endl;
        cout<<"\t\t\t\t\t\t\t    =================================== "<<endl;
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to Red
        cout<<"\t\t\t\t\t\t\t      PLEASE CHOOSE BETWEEN 1 AND 2!"<<endl;
        cout<<"\t\t\t\t\t\t\t        PRESS ANY KEY TO RESTART() "<<endl;
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }

    void LoadingMenu()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout << "\n\n\n\n\n\t\t\t\t\t\t\t Preparing Menu";

            for(int i = 0; i < 5; i++) // Loop to display a loading animation
            {
                cout << " . ";
                Sleep(200); // Pause the execution for 200 milliseconds
            }

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Set the text to green
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t THANK YOU FOR WAITING!"; 
        Sleep(300); system("cls"); // Pause the execution for 300 milliseconds and then clear the screen
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }

    void MainMenu()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout<<"\n\n\t\t\t\t\t=============================";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE); // Set the text to blue
        cout<<"LOVE, REGINA  MENU";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout<<"=============================\n\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE + FOREGROUND_RED); // Set the text to Violet
        cout<<"\t\t\t\t\t\t\t    +++++   CAKES & PASTRIES   +++++\n\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to red
        cout<<"\t\t\t\t\t    CODE";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE + FOREGROUND_GREEN);	// Set the text to Cyan		
        cout<<"                       MENU				    ";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Set the text to green
        cout<<"PRICE\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default

        cout<<"\t\t\t\t\t============================================================================\n\n";
        cout<<"\t\t\t\t\t    [A]	    =       Chocolate Crinkles (20 pcs)	                    P 100       \n";
        cout<<"\t\t\t\t\t____________________________________________________________________________\n\n";
        cout<<"\t\t\t\t\t    [B]	    =	    Mini Chocolate Ganache 			    P 60		\n";
        cout<<"\t\t\t\t\t____________________________________________________________________________\n\n";
        cout<<"\t\t\t\t\t    [C]	    =	    Moist Chocolate Ganache			    P 400       \n";
        cout<<"\t\t\t\t\t____________________________________________________________________________\n\n";
        cout<<"\t\t\t\t\t    [D]	    =	    1 Dozen Minimalist Chocolate Cupcakes           P 400       \n";
        cout<<"\t\t\t\t\t____________________________________________________________________________\n\n";
        cout<<"\t\t\t\t\t    [E]	    =	    Minimalist Moist Chocolate Cake	            P 800       \n";
        cout<<"\t\t\t\t\t____________________________________________________________________________\n\n";
        cout<<"\t\t\t\t\t    [F]	    =	    Minimalist Moist Chocolate Money Cake	    P 1000      \n";
        cout<<"\n\t\t\t\t\t============================================================================\n";
    }

    bool isValidOrderCode(char code)
    {
        return (code >= 'a' && code <= 'f') || (code >= 'A' && code <= 'F'); 
        //Returns'true' if the 'code' is a valid order code, 'false' otherwise.
        //Check if the given 'code' is a valid order code
    }

    void InValidOrderCode()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h
        
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to Red
        cout << "\t\t\t\t\t\t\t Invalid order code. Please try again.\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }

    void MaxOrdersReach()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h
        
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Set the text to Green
        cout << "\n\t\t\t\t\t\t\t Maximum number of orders reached.\n";
        cout << "\t\t\t\t\t\t\t "; system("pause");
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }

    void OrderBreakdownPage()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout<<"\n\n\n\t\t\t\t           =========================";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Set the text to green
        cout<<" ORDER'S BREAKDOWN ";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout<<"=========================\n";
    }

    void LoadingReceipt()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        cout << "\n\n\n\n\n\t\t\t\t\t\t\t Preparing Receipt";

            for(int i = 0; i < 5; i++) // Loop to display a loading animation
            {
                cout << " . ";
                Sleep(200); // Pause the execution for 200 milliseconds
            }

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Set the text to green
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t THANK YOU FOR WAITING!"; 
        Sleep(300); system("cls"); // Pause the execution for 300 milliseconds and then clear the screen
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }

    void ReceiptHeader()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE); // Set the text to blue
        cout<<"\n\n\t\t\t\t\t\t             LOVE, REGINA  -  HOME BAKERY";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout<<"\n\t\t\t\t\t      070 Sitio De Asis, Brgy. San Martin De Porres, Paranaque City";
        cout<<"\n\t\t\t\t\t\t               Contact us at 09434977327\n\n";
        cout<<"\t\t\t\t           ========================= CUSTOMER'S INFO ==========================\n";
    }

    void ReceiptBody()
    {
        cout<<"\n\t\t\t\t           ========================= ORDER'S RECEIPT ==========================\n";
        cout<<"\n\t\t\t\t            ORDER/s					       QTY.	PRICE\n";
    }

    void ReceiptFooter()
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE); //Pre-defined function from Windows.h

        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_GREEN); // Set the text to green
        cout<<"\n\n\n\t\t\t\t\t\t\t         THANK YOU FOR YOUR ORDER!\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
        cout<<"\n\t\t\t\t\t\t\t                   NOTE:";
        cout<<"\n\t\t\t\t\t\t\t       All products are made to order.";
        cout<<"\n\t\t\t\t\t\t\t    Please leave a message on our FB Page";
        cout<<"\n\t\t\t\t\t\t\t       OPENS: 10:00AM - 8:00PM (DAILY)";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_RED); // Set the text to red
        cout<<"\n\n\n\n\t\t\t\t\t\t  ++++++++++++++++++ TAKE A SCREENSHOT! ++++++++++++++++++\n\n";
        SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED); // Set the text to default
    }
}
#endif