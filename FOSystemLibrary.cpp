#include<iostream>
#include<windows.h>
#include<conio.h>
#include<algorithm>
#include<string>
#include"FOSFeatures.h"
using namespace std;
using namespace features;

int main()
{
     // . . . . . Loading Feature . . . . . 
    LoadingScreen();
    MenuInfo menu; //Intialize Structure
    bool validChoice= false; //Initializer to check whether the choices are 1 or 2
    
    // . . . . . Home Page /  Startup . . . . .
    do{
        system("cls");
            HomePage(); //Display FOS cover
            cout<<"\n\n\t\t\t\t\t\t\t     "; system("pause"); //Click to Proceed

        // . . . . . Customer's Information Page . . . . .
        system("cls");
            OrderPage(); //Displays Order Method Options
            cin>>menu.OrderMethod; //Enter Order Method
        cin.ignore(); //ignore a specific number of characters before reading further input

        if(menu.OrderMethod == 1)  // . . . PickUp Order Method . . .  
        {
            system("cls"); 
                PickUpPage(menu); //Return Customer's Information
            validChoice=true;
        }
        else if(menu.OrderMethod == 2) // . . . Via Courier Order Method . . .  
        {
            system("cls");
                CourierPage(menu); //Return Customer's Information
            validChoice=true;
        }
        else
        {
                DefaultOrderMethod(); //Warning Statement for Invalid Order Methods
            cin.get(); system("cls"); //to capture a single character input from the user; to clear screen
        }
    }while(!validChoice);

    system("cls");

    // . . . . . LOVE, REGINA MAIN MENU . . . . . 

    //Initialization 
    OrderSystem ordering; //Initialize Sturcture
    ordering.NumOfOrders = 0; // Initialize number of order to 0
    bool RenewCart = false; //Initialize bool to check whether the user wants to renew the cart

    do{
    ordering.NumOfOrders = 0; //Reset the orders
    ordering.FoodTotal = 0; //Reset the Total price per food
    ordering.TotalOrder = 0; //Reset the Total price 
    LoadingMenu(); //Load to Menu
    MainMenu(); //List of Love, Regina's Main Menu

        for (int i = 0; i < MAX_ORDERS;) //loop until the order reach the max which is 5
        {
            // Enter Order Code
            cout << "\n\t\t\t\t\t\t\t [" << i+1 << "]" << " Enter Order : ";
            cin >> menu.Order;

                if (!isValidOrderCode(menu.Order)) //Check wheter the entered code by the user is valid A-F a-f
                {
                    InValidOrderCode(); //Display Invalid Statement
                }
                else
                {
                    // Enter Order Quantity
                    cout << "\t\t\t\t\t\t\t Enter Quantity : ";
                    cin >> menu.OrderQuantity;

                    ordering.MaxOrders[ordering.NumOfOrders] = menu; // Storing of information to the array
                    ordering.NumOfOrders++;
                    i++; // Increase the order counter

                        if (i == MAX_ORDERS) //Check wheher the user reach the maximum number of orders
                        {
                            MaxOrdersReach(); // Display Warning statement
                            break; // Exit the loop if the maximum number of orders is reached
                        }
                }

            // Check whether the user wants to add another order
            cout << "\n\t\t\t\t\t\t\t Do you want to add another order? (Y/N) : ";
            cin >> ordering.AddOrder;

                if (ordering.AddOrder != 'Y' && ordering.AddOrder != 'y') //if the user does not select Y or y the system will proceed to the next part
                {
                    break; // Exit the loop if the user doesn't want to add another order
                }
        }

        system("cls");

        OrderBreakdownPage(); // Display order breakdwon page

        for (int i=0; i<ordering.NumOfOrders; i++) //Loop the switch until all orders are accessed
        {
            const MenuInfo& menu = ordering.MaxOrders[i]; 
            //Access a constant reference to an element of the `MaxOrders` array within the `ordering` object.
            //access the element efficiently without making a copy and ensures that the referenced object cannot be modified unintentionally.

            switch (menu.Order) 
            {
                case 'A':
                case 'a':
                    {
                        cout<<"\n\t\t\t\t            Chocolate Crinkles(20 pcs)\t\t\t\tx"<<menu.OrderQuantity;
                            ordering.FoodTotal = menu.OrderQuantity * 100; 
                        cout<<"\tP "<<ordering.FoodTotal<<endl;
                    break; 
                    }
                case 'B':
                case 'b':
                    {
                        cout<<"\t\t\t\t            Mini Chocolate Ganache\t\t\t\tx"<<menu.OrderQuantity;
                            ordering.FoodTotal = menu.OrderQuantity * 60; 
                        cout<<"\tP "<< ordering.FoodTotal<<endl; 
                    break;
                    }           
                case 'C':
                case 'c':
                    {
                    cout<<"\t\t\t\t            Moist Chocolate Ganache\t\t\t\tx"<<menu.OrderQuantity;
                            ordering.FoodTotal = menu.OrderQuantity * 400; 
                        cout<<"\tP "<< ordering.FoodTotal<<endl; 
                    break;
                    }
                case 'D':
                case 'd':
                    {
                        cout<<"\t\t\t\t            1 Dozen Minimalist Chocolate Cupcakes\t\tx"<<menu.OrderQuantity;
                            ordering.FoodTotal = menu.OrderQuantity * 400; 
                        cout<<"\tP "<< ordering.FoodTotal<<endl; 
                    break;
                    }
                case 'E':
                case 'e':
                    {
                        cout<<"\t\t\t\t            Minimalist Moist Chocolate Cake\t\t\tx"<<menu.OrderQuantity;
                            ordering.FoodTotal = menu.OrderQuantity * 800; 
                        cout<<"\tP "<< ordering.FoodTotal<<endl;  
                    break;
                    }
                case 'F':
                case 'f':
                    {
                        cout<<"\t\t\t\t            Minimalist Moist Chocolate Money Cake\t\tx"<<menu.OrderQuantity;
                            ordering.FoodTotal = menu.OrderQuantity * 1000; 
                        cout<<"\tP "<< ordering.FoodTotal<<endl;  
                    break;
                    }
                default:
                        cout <<"\t\t\t\t           Invalid order code. Please try again.\n";
                        getch(); system("cls"); i--;
                    break;                                
            }
            ordering.TotalOrder += ordering.FoodTotal; //compute the total price of each order and add as a whole to get the total price
        }

        //Display total order
        cout<<"\n\n\n\t\t\t\t\t    TOTAL PRICE" << "\t\t\t\t\t\t\tP " << ordering.TotalOrder; 
        cout<<"\n\t\t\t\t           =====================================================================\n";

        //Option to Renew the cart, This will erase the existing orders
        cout << "\n\t\t\t\t\t\t\t Do you want to renew the cart? (Y/N) : ";
        cin >> ordering.RenewOrder;

        RenewCart = (ordering.RenewOrder == 'Y' || ordering.RenewOrder == 'y'); //Check wheter the user wants renew the cart

        if(!RenewCart)
        {
            cin.ignore();
            cout << "\n\t\t\t\t\t\t\t Date of Delivery or Claiming (MM/DD/YYYY) : "; //Enter Date of Delivery or Claiming
            getline(cin, menu.Date);
        }

        system("cls");

    }while(RenewCart); //loop this block of code until the user does not want to renew its cart

    LoadingReceipt(); // Display Loading Animation

    system("cls");

    // . . . . . RECEIPT GENERATION . . . . .

    ReceiptHeader(); //Display Receipt Header
            //Display Information
            cout<<"\n\t\t\t\t            NAME : " << menu.Name;
            cout<<"\n\t\t\t\t            ADDRESS : " << menu.Address;
            cout<<"\n\t\t\t\t            CONTACT NUMBER : " << menu.PhoneNumber;
            cout<<"\n\t\t\t\t            DATE OF DELIVERY/CLAIMING : " << menu.Date << endl;
    ReceiptBody(); //Display the Body of Receipt 

    ordering.TotalOrder = 0; //Reset the Total price 

    for (int i=0; i<ordering.NumOfOrders; i++) //Loop the switch until all orders are accessed
    {
        const MenuInfo& menu = ordering.MaxOrders[i]; 
        //Access a constant reference to an element of the `MaxOrders` array within the `ordering` object.
        //access the element efficiently without making a copy and ensures that the referenced object cannot be modified unintentionally.

        switch (menu.Order) 
        {
            case 'A':
            case 'a':
                {
                    cout<<"\n\t\t\t\t            Chocolate Crinkles (20 pcs)\t\t\t\tx"<<menu.OrderQuantity;
                        ordering.FoodTotal = menu.OrderQuantity * 100; 
                    cout<<"\tP "<<ordering.FoodTotal<<endl;
                break; 
                }
            case 'B':
            case 'b':
                {
                    cout<<"\t\t\t\t            Mini Chocolate Ganache\t\t\t\tx"<<menu.OrderQuantity;
                        ordering.FoodTotal = menu.OrderQuantity * 60; 
                    cout<<"\tP "<< ordering.FoodTotal<<endl; 
                break;
                }           
            case 'C':
            case 'c':
                {
                cout<<"\t\t\t\t            Moist Chocolate Ganache\t\t\t\tx"<<menu.OrderQuantity;
                        ordering.FoodTotal = menu.OrderQuantity * 400; 
                    cout<<"\tP "<< ordering.FoodTotal<<endl; 
                break;
                }
            case 'D':
            case 'd':
                {
                    cout<<"\t\t\t\t            1 Dozen Minimalist Chocolate Cupcakes\t\tx"<<menu.OrderQuantity;
                        ordering.FoodTotal = menu.OrderQuantity * 400; 
                    cout<<"\tP "<< ordering.FoodTotal<<endl; 
                break;
                }
            case 'E':
            case 'e':
                {
                    cout<<"\t\t\t\t            Minimalist Moist Chocolate Cake\t\t\tx"<<menu.OrderQuantity;
                        ordering.FoodTotal = menu.OrderQuantity * 800; 
                    cout<<"\tP "<< ordering.FoodTotal<<endl;  
                break;
                }
            case 'F':
            case 'f':
                {
                    cout<<"\t\t\t\t            Minimalist Moist Chocolate Money Cake\t\tx"<<menu.OrderQuantity;
                        ordering.FoodTotal = menu.OrderQuantity * 1000; 
                    cout<<"\tP "<< ordering.FoodTotal<<endl;  
                break;
                }
            default:
                    cout <<"\t\t\t\t           Invalid order code. Please try again.\n";
                    getch(); system("cls"); i--;
                break;                                
        }
        ordering.TotalOrder += ordering.FoodTotal; //compute the total price of each order and add as a whole to get the total price
    }

    cout<<"\n\n\n\t\t\t\t           =====================================================================\n";

        if(menu.OrderMethod == 1) //If user, choose pick-up method
        {
            cout<<"\n\t\t\t\t            DELIVERY METHOD					  TOTAL PRICE";
            cout<<"\n\t\t\t\t            Pick-Up("<<menu.PickUpLocation<<")\t\t\t\t\t  " << ordering.TotalOrder << "\n";
        }
        else if(menu.OrderMethod == 2) //If user, choose via-courier method
        {
            cout<<"\n\t\t\t\t            DELIVERY METHOD					  TOTAL PRICE";
            cout<<"\n\t\t\t\t            Via Courier"<<"\t\t\t\t\t\t   " << ordering.TotalOrder << "\n";
        }

        ReceiptFooter(); //Display Receipt Footer

        //Restart the Program 
        cout<<"\n\t\t\t\t\t\t\t\t "; system("pause");
        system("cls");
        main(); //Return to Main

    getche();
    return 0;
}