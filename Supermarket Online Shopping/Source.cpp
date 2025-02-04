#include <iostream>
#include <fstream>
using namespace std;

// stucture customer is made to hold customer's id, name, phone number and location
struct Customer {
    string id;
    string name;
    string phoneNo; // customer phone number
    string location;
};

// stucture Product is made to hold Product information
struct Product {
    string code;
    string name;
    string category;
    string P_date; // Production Date variable declaration
    string E_date; // Expired Date variable declaration
    double price; // Price for one piece
};

// stucture order is made to hold ordered Product
struct List {
    Product ordered; // delectation of a new variable of type Product
    int quantity; // quantity of each product ordered
};

// stucture order is made to hold order information
struct Order {
    string C_id; // Customer ID
    List selected_goods[15]; // list of Products ordered
    double t_price; // total price of the order
};

// structure about the extra information of items 
struct Information
{
    string name;
    string ingredients;
    string specifications;
};

// List of Product categories: snacks, drinks, Vegetables & fruit, Meat, and Fish
// Number of categories = 5
const int CATEGORY_lIST_SIZE = 5; // number of category Products
string pList[CATEGORY_lIST_SIZE] = { "snacks","drinks","vegetables and fruit",
"meat","fish" };

// fish Category Products
const int FISH_CATEGORY_lIST = 2;
const Product fish[FISH_CATEGORY_lIST] = { {"fi01","salmon","fish","02/12/2023","12/12/2023",230},
{"fi02","tuna","fish","02/12/2023","20/12/2023",150} };

// snacks Category Products
const int SNACKS_CATEGORY_lIST = 2;
const Product snacks[SNACKS_CATEGORY_lIST] = { {"sn01","chips","snacks","02/12/2023","30/12/2023",10},
{"sn02","chocolate ","snacks","02/12/2023","30/01/2024",30} };

// drinks Category Products
const int DRINKS_CATEGORY_lIST = 2;
const Product drinks[DRINKS_CATEGORY_lIST] = { {"dr01","water","drinks","02/12/2023","20/6/2024",20},
{"dr02","apple juice","drinks","02/12/2023","30/3/2024",30} };

// meat Category poducts
const int MEAT_CATEGORY_lIST = 2;
const Product meat[MEAT_CATEGORY_lIST] = { {"mt01","turkey","meat","02/12/2023","30/12/2023",200},
{"mt02","beef","meat","02/12/2023","30/1/2024",300} };

// Vegetables & fruit Category Products
const int VEGETABLES_FRUITS_CATEGORY_lIST = 2;
const Product veg_fruit[VEGETABLES_FRUITS_CATEGORY_lIST] = { {"vf01","mushrooms","vegetables and fruit","02/12/2023","22/12/2023",40},
{"vf02","tomatoes","vegetables and fruit","02/12/2023","30/12/2023",35} };
int c = 0;

void login(Customer*, Order);
void Registration();
void Show_menu_of_options(Customer, Order);
void viewproductmenu(Customer, Order);
void viewproductmenu_1();
void edit_information(Customer*, Order);
void select(Customer, Order);
void select_1(Order* o, int i);
void review_the_order(Customer customer, Order* order, int count);
void viewTotalPrice(Customer customer, Order* order);
void Logout();

int main()
{
    cout << "\t\t\t\t\tWelcome to our Online Supermarket Shopping Experience" << endl;
    char choice_1;
    char choice_2;
    int i = 0, l = 0;
    Customer customer_1;
    Customer* ptr;
    Order order_1;
    order_1.C_id = customer_1.id;
    ptr = &customer_1;
    cout << "Do you want to log in ? (Y/N)" << endl;
    cin >> choice_1;
    while (i == 0)
    {
        if (choice_1 == 'Y')
        {
            login(ptr, order_1);
            Show_menu_of_options(customer_1, order_1);
            i++;
        }
        else if (choice_1 == 'N')
        {
            i++;
            cout << "Do you want to register ? (Y/N)" << endl;
            cin >> choice_2;
            while (l == 0)
            {
                if (choice_2 == 'Y')
                {
                    Registration();
                    l++;
                }
                else if (choice_2 == 'N')
                {
                    l++;
                    return 0;
                }
                else
                {
                    cout << "Invalid input,you should enter Y for yes and N for no." << endl;
                    cout << "Do you want to register ? (Y/N)" << endl;
                    cin >> choice_2;
                }
            }
            return 0;
        }
        else
        {
            cout << "Invalid input,you should enter Y for yes and N for no." << endl;
            cout << "Do you want to log in ? (Y/N)" << endl;
            cin >> choice_1;
        }
    }
}

void login(Customer* customer_address, Order order)
{
    int count = 0;
    string username, password, name, pass;
    cout << "Please Enter your username and Password : " << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    ifstream input("records.txt");
    while (input >> name >> pass)
    {
        if (name == username && pass == password)
        {
            count = 1;
        }
    }
    input.close();
    if (count == 1)
    {
        cout << username << "\nSuccesfully loged in \nThanks for logging in ! \n";
        (*customer_address).name = username;
        (*customer_address).id = "1";
    }
    else
    {
        cout << username << "\nFailed to logged in  \nPleses check your username and password ! \n";
        main();
    }
}
void Registration()
{
    string username, password, name, pass;
    system("cls");
    cout << "Please Enter your username and Password : " << endl;
    cout << "Username : ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    ofstream f1("records.txt", ios::app);
    f1 << username << ' ' << password << endl;
    cout << "Registration is successfull \n";
    main();
}

void Show_menu_of_options(Customer customer, Order order)
{
    int user_selection = 0;
    cout << "Please enter 1,if you want to edit your information." << endl;
    cout << "Please enter 2,if you want to view the product menu." << endl;
    cout << "Please enter 3,if you want to view more information about an item." << endl;
    cout << "Please enter 4,if you want to select the goods." << endl;
    cout << "Please enter 5,if you want to review your order." << endl;
    cout << "Please enter 6,if you want to modify your order." << endl;
    cout << "Please enter 7,if you want to view the total price of your order." << endl;
    cout << "Please enter 8,if you want to log out." << endl;
    cout << "What do you want to do?" << endl;
    cin >> user_selection;
    while (user_selection != 0)
    {
        switch (user_selection)
        {
        case 1:
            edit_information(&customer, order);
            user_selection = 0;
            break;
        case 2:
            viewproductmenu(customer, order);
            user_selection = 0;
            break;
        case 4:
            select(customer, order);
            user_selection = 0;
            break;
        case 5:
            review_the_order(customer, &order, c);
            user_selection = 0;
            break;
        case 7:
            viewTotalPrice(customer, &order);
            user_selection = 0;
            break;
        case 8:
            Logout();
            user_selection = 0;
            break;
        }
    }
    cout << endl;
}
void edit_information(Customer* customer_address, Order order)
{
    cout << "Your name is " << (*customer_address).name << endl;
    cout << "Your id is " << (*customer_address).id << endl;
    cout << "Your location is " << (*customer_address).location << endl;
    cout << "Your phone number is " << (*customer_address).phoneNo << endl;
    int user_selection_2;
    cout << "Please enter 1,if you want to edit your name." << endl;
    cout << "Please enter 2,if you want to edit location." << endl;
    cout << "Please enter 3,if you want to edit your phone number." << endl;
    cout << "What do you want to edit ?";
    cin >> user_selection_2;
    while (user_selection_2 != 0)
    {
        switch (user_selection_2)
        {
        case 1:
            cout << "Please enter the new name :" << endl;
            cin >> (*customer_address).name;
            user_selection_2 = 0;
            break;
        case 2:
            cout << "Please enter the new location :" << endl;
            cin >> (*customer_address).location;
            user_selection_2 = 0;
            break;
        case 3:
            cout << "Please enter the new phone number :" << endl;
            cin >> (*customer_address).phoneNo;
            user_selection_2 = 0;
            break;
        default:
            cout << "Invalid input" << endl;
            cout << "Please enter 1,if you want to edit your name." << endl;
            cout << "Please enter 2,if you want to edit location." << endl;
            cout << "Please enter 3,if you want to edit your phone number." << endl;
            cout << "What do you want to edit ?";
            cin >> user_selection_2;
            break;
        }
    }
    cout << endl;
    Show_menu_of_options((*customer_address), order);

}
void viewproductmenu(Customer customer, Order order)//to show the costumer the supermarket products
{
    int n = 0;
    cout << " Our first category is Snacks " << endl;
    cout << "there are " << SNACKS_CATEGORY_lIST << " kinds";
    for (n = 0; n < SNACKS_CATEGORY_lIST; n++)//to show kinds of snacks category
    {
        cout << endl;
        cout << "Code :" << snacks[n].code << endl << "Name :" << snacks[n].name << endl << "Category :" <<
            snacks[n].category << endl << "Production date :" << snacks[n].P_date << endl << "Expiration date :" <<
            snacks[n].E_date << endl << "Price :" << snacks[n].price << endl;

    }
    cout << endl;
    cout << " 0ur seconed category is Drinks " << endl;
    cout << "there are " << DRINKS_CATEGORY_lIST << " kinds";
    for (n = 0; n < DRINKS_CATEGORY_lIST; n++)//to show kinds of driks category
    {
        cout << endl;
        cout << "Code :" << drinks[n].code << endl << "Name :" << drinks[n].name << endl << "Category :" <<
            drinks[n].category << endl << "Production date :" << drinks[n].P_date << endl << "Expiration date :" <<
            drinks[n].E_date << endl << "Price :" << drinks[n].price << endl;

    }
    cout << endl;

    cout << " Our third category is Vegetables and Fruit " << endl;
    cout << "there are " << VEGETABLES_FRUITS_CATEGORY_lIST << " kinds";
    for (n = 0; n < VEGETABLES_FRUITS_CATEGORY_lIST; n++)//to show kinds of Vegetables and Fruit category
    {
        cout << endl;
        cout << "Code :" << veg_fruit[n].code << endl << "Name :" << veg_fruit[n].name << endl << "Category :" <<
            veg_fruit[n].category << endl << "Production date :" << veg_fruit[n].P_date << endl << "Expiration date :" <<
            veg_fruit[n].E_date << endl << "Price :" << veg_fruit[n].price << endl;

    }
    cout << endl;

    cout << " Our fourth category is Meat " << endl;
    cout << "there are " << MEAT_CATEGORY_lIST << " kinds";
    for (n = 0; n < MEAT_CATEGORY_lIST; n++)//to show kinds of meat category
    {
        cout << endl;
        cout << "Code :" << meat[n].code << endl << "Name :" << meat[n].name << endl << "Category :" <<
            meat[n].category << endl << "Production date :" << meat[n].P_date << endl << "Expiration date :" <<
            meat[n].E_date << endl << "Price :" << meat[n].price << endl;

    }

    cout << endl;
    cout << " Our fifth category is Fish " << endl;
    cout << "there are " << FISH_CATEGORY_lIST << " kinds";
    for (n = 0; n < FISH_CATEGORY_lIST; n++)//to show kinds of fish category
    {
        cout << endl;
        cout << "Code :" << fish[n].code << endl << "Name :" << fish[n].name << endl << "Category :" <<
            fish[n].category << endl << "Production date :" << fish[n].P_date << endl << "Expiration date :" <<
            fish[n].E_date << endl << "Price :" << fish[n].price << endl;

    }
    cout << endl;
    Show_menu_of_options(customer, order);
}
void viewproductmenu_1()
{
    int n = 0;
    cout << " Our first category is Snacks " << endl;
    cout << "there are " << SNACKS_CATEGORY_lIST << " kinds";
    for (n = 0; n < SNACKS_CATEGORY_lIST; n++)//to show kinds of snacks category
    {
        cout << endl;
        cout << "Code :" << snacks[n].code << endl << "Name :" << snacks[n].name << endl << "Category :" <<
            snacks[n].category << endl << "Production date :" << snacks[n].P_date << endl << "Expiration date :" <<
            snacks[n].E_date << endl << "Price :" << snacks[n].price << endl;

    }
    cout << endl;
    cout << " 0ur seconed category is Drinks " << endl;
    cout << "there are " << DRINKS_CATEGORY_lIST << " kinds";
    for (n = 0; n < DRINKS_CATEGORY_lIST; n++)//to show kinds of driks category
    {
        cout << endl;
        cout << "Code :" << drinks[n].code << endl << "Name :" << drinks[n].name << endl << "Category :" <<
            drinks[n].category << endl << "Production date :" << drinks[n].P_date << endl << "Expiration date :" <<
            drinks[n].E_date << endl << "Price :" << drinks[n].price << endl;

    }
    cout << endl;

    cout << " Our third category is Vegetables and Fruit " << endl;
    cout << "there are " << VEGETABLES_FRUITS_CATEGORY_lIST << " kinds";
    for (n = 0; n < VEGETABLES_FRUITS_CATEGORY_lIST; n++)//to show kinds of Vegetables and Fruit category
    {
        cout << endl;
        cout << "Code :" << veg_fruit[n].code << endl << "Name :" << veg_fruit[n].name << endl << "Category :" <<
            veg_fruit[n].category << endl << "Production date :" << veg_fruit[n].P_date << endl << "Expiration date :" <<
            veg_fruit[n].E_date << endl << "Price :" << veg_fruit[n].price << endl;

    }
    cout << endl;

    cout << " Our fourth category is Meat " << endl;
    cout << "there are " << MEAT_CATEGORY_lIST << " kinds";
    for (n = 0; n < MEAT_CATEGORY_lIST; n++)//to show kinds of meat category
    {
        cout << endl;
        cout << "Code :" << meat[n].code << endl << "Name :" << meat[n].name << endl << "Category :" <<
            meat[n].category << endl << "Production date :" << meat[n].P_date << endl << "Expiration date :" <<
            meat[n].E_date << endl << "Price :" << meat[n].price << endl;

    }

    cout << endl;
    cout << " Our fifth category is Fish " << endl;
    cout << "there are " << FISH_CATEGORY_lIST << " kinds";
    for (n = 0; n < FISH_CATEGORY_lIST; n++)//to show kinds of fish category
    {
        cout << endl;
        cout << "Code :" << fish[n].code << endl << "Name :" << fish[n].name << endl << "Category :" <<
            fish[n].category << endl << "Production date :" << fish[n].P_date << endl << "Expiration date :" <<
            fish[n].E_date << endl << "Price :" << fish[n].price << endl;

    }
    cout << endl;
}
void select(Customer customer, Order order)
{
    bool x = 1;
    viewproductmenu_1();
    for (int i = 0; i < 15; i++)
    {
        select_1(&order, i);
        cout << "PRESS 1 TO CONTINUE : ";
        cin >> x;
        c = i;
        if (x != 1)
        {
            break;
        }
    }
    cout << endl;
    Show_menu_of_options(customer, order);
}
void select_1(Order* o, int i)
{
    cout << endl;
    cout << "Please enter your order : ";
    cin >> (*o).selected_goods[i].ordered.name;
    cout << "How much do you want ? ";
    cin >> (*o).selected_goods[i].quantity;
    cout << endl;
}
void review_the_order(Customer customer, Order* order, int count)
{

    for (int i = 0; i <= count; i++)
    {
        cout << " Order Detalis:\n";
        cout << "name of the product: " << (*order).selected_goods[i].ordered.name << endl;
        cout << "quantity: " << (*order).selected_goods[i].quantity << endl;
        for (int j = 0; j < FISH_CATEGORY_lIST; j++)
        {
            if ((*order).selected_goods[i].ordered.name == fish[j].name)
            {
                (*order).selected_goods[i].ordered.price = fish[j].price;
                cout << "price: " << (*order).selected_goods[i].ordered.price << endl;
            }
        }

        for (int j = 0; j < SNACKS_CATEGORY_lIST; j++)
        {

            if ((*order).selected_goods[i].ordered.name == snacks[j].name)
            {
                (*order).selected_goods[i].ordered.price = snacks[j].price;
                cout << "price: " << (*order).selected_goods[i].ordered.price << endl;
            }
        }
        for (int j = 0; j < DRINKS_CATEGORY_lIST; j++)
        {

            if ((*order).selected_goods[i].ordered.name == drinks[j].name)
            {
                (*order).selected_goods[i].ordered.price = drinks[j].price;
                cout << "price: " << (*order).selected_goods[i].ordered.price << endl;
            }
        }
        for (int j = 0; j < MEAT_CATEGORY_lIST; j++)
        {


            if ((*order).selected_goods[i].ordered.name == meat[j].name)
            {
                (*order).selected_goods[i].ordered.price = meat[j].price;
                cout << "price: " << (*order).selected_goods[i].ordered.price << endl;
            }
        }
        for (int j = 0; j < VEGETABLES_FRUITS_CATEGORY_lIST; j++)
        {


            if ((*order).selected_goods[i].ordered.name == veg_fruit[j].name)
            {
                (*order).selected_goods[i].ordered.price = veg_fruit[j].price;
                cout << "price: " << (*order).selected_goods[i].ordered.price << endl;
            }

        }

    }
    cout << endl;
    Show_menu_of_options(customer, (*order));
}
// Function to calculate and display the total price of the order
void viewTotalPrice(Customer customer, Order* order)
{
    double totalPrice = 0.0;

    // Iterate through the selected goods in the order and calculate the total price
    for (int i = 0; i < 15; ++i) {
        // Check if the ordered product is valid (non-empty code indicates a valid product)
        if (!(*order).selected_goods[i].ordered.name.empty()) {
            totalPrice += (*order).selected_goods[i].ordered.price * (*order).selected_goods[i].quantity;
        }
    }
    (*order).t_price = totalPrice;
    // Display the total price to the customer
    cout << "Total Price for the order: " << (*order).t_price << endl;
    cout << endl;
    Show_menu_of_options(customer, (*order));
}
void Logout()
{
    cout << " Logout succesfull! " << endl;
    system("cls");
    main();
}