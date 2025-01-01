#include <iostream>
#include <string>
using namespace std;

// Define the structure to store product information
struct Product
{
    string name;
    double unitPrice;
    int stock;
    int productID;
};

// Function prototypes
void addProduct(Product products[], int &count);
void buyProduct(Product products[], int count, Product purchases[], int &purchaseCount);
void editProduct(Product products[], int count);
void printBill(Product purchases[], int purchaseCount);

int main()
{
    const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    Product purchases[MAX_PRODUCTS];
    int productCount = 0, purchaseCount = 0;

    int choice;
    do
    {
        // Display the menu
        cout << "\n===== ChaseUp Shopping Mall =====\n";
        cout << "1. Add New Product\n";
        cout << "2. Buy Existing Product\n";
        cout << "3. Edit Existing Product Details\n";
        cout << "4. Print Bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addProduct(products, productCount);
            break;
        case 2:
            buyProduct(products, productCount, purchases, purchaseCount);
            break;
        case 3:
            editProduct(products, productCount);
            break;
        case 4:
            printBill(purchases, purchaseCount);
            break;
        case 5:
            cout << "Exiting the application. Thank you for using ChaseUp Shopping Mall!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// Function to add a new product
void addProduct(Product products[], int &count)
{
    cout << "\nEnter details for the new product:\n";
    cout << "Product Name: ";
    cin.ignore();
    getline(cin, products[count].name);
    cout << "Unit Price: ";
    cin >> products[count].unitPrice;
    cout << "Stock: ";
    cin >> products[count].stock;
    cout << "Product ID: ";
    cin >> products[count].productID;

    count++;
    cout << "Product added successfully!\n";
}

// Function to buy an existing product
void buyProduct(Product products[], int count, Product purchases[], int &purchaseCount)
{
    int id, quantity;
    cout << "\nEnter the Product ID to buy: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (products[i].productID == id)
        {
            cout << "Product Found: " << products[i].name << "\n";
            cout << "Available Stock: " << products[i].stock << "\n";
            cout << "Enter quantity to buy: ";
            cin >> quantity;

            if (quantity <= products[i].stock)
            {
                double totalCost = quantity * products[i].unitPrice;
                products[i].stock -= quantity;

                // Record the purchase
                purchases[purchaseCount] = products[i];
                purchases[purchaseCount].stock = quantity; // Store purchased quantity
                purchaseCount++;

                cout << "Purchase successful! Total cost: Rs." << totalCost << "\n";
            }
            else
            {
                cout << "Insufficient stock available.\n";
            }
            return;
        }
    }
    cout << "Product with ID " << id << " not found.\n";
}

// Function to edit product details
void editProduct(Product products[], int count)
{
    int id;
    cout << "\nEnter the Product ID to edit: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (products[i].productID == id)
        {
            cout << "Product Found: " << products[i].name << "\n";
            cout << "Enter new details:\n";
            cout << "New Product Name: ";
            cin.ignore();
            getline(cin, products[i].name);
            cout << "New Unit Price: ";
            cin >> products[i].unitPrice;
            cout << "New Stock: ";
            cin >> products[i].stock;

            cout << "Product details updated successfully!\n";
            return;
        }
    }
    cout << "Product with ID " << id << " not found.\n";
}

// Function to print the bill
void printBill(Product purchases[], int purchaseCount)
{
    if (purchaseCount == 0)
    {
        cout << "\nNo purchases made yet.\n";
        return;
    }

    cout << "\n===== Purchase Bill =====\n";
    cout << "Name\t\t\t || Quantity\t || Unit Price\t || Total Cost\n";
    double grandTotal = 0;

    for (int i = 0; i < purchaseCount; i++)
    {
        double totalCost = purchases[i].unitPrice * purchases[i].stock;
        grandTotal += totalCost;
        cout << purchases[i].name << "\t\t\t" << purchases[i].stock << "\t"
             << purchases[i].unitPrice << "\t" << totalCost << "\n";
    }

    cout << "----------------------------------------\n";
    cout << "Grand Total: Rs." << grandTotal << "\n";
}
