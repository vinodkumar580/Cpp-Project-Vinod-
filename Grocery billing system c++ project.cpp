#include <iostream>
using namespace std;

const int MAX = 20;

// Function to display the grocery items
void showItems(string names[], double prices[], int n) {
    cout << "\n---- Available Grocery Items ----\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << names[i] << " - Rs. " << prices[i] << endl;
    }
    cout << "--------------------------------\n";
}

// Function to add items to cart
void addToCart(int cartIndex[], int quantity[], int &cartSize) {
    int itemNumber, qty;

    cout << "Enter item number: ";
    cin >> itemNumber;
    cout << "Enter quantity: ";
    cin >> qty;

    // Store item index (itemNumber-1) and quantity
    cartIndex[cartSize] = itemNumber - 1;
    quantity[cartSize] = qty;
    cartSize++;

    cout << "Item added to cart!\n";
}

// Function to generate the bill
void generateBill(string names[], double prices[], int cartIndex[],
                  int quantity[], int cartSize) {

    double total = 0;

    cout << "\n\n========== BILL RECEIPT ==========\n";
    cout << "Item\tQty\tPrice\tAmount\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < cartSize; i++) {
        int index = cartIndex[i];
        double amount = prices[index] * quantity[i];

        cout << names[index] << "\t"
             << quantity[i] << "\t"
             << prices[index] << "\t"
             << amount << endl;

        total += amount;
    }

    cout << "----------------------------------\n";
    cout << "Total Amount: Rs. " << total << endl;

    double discount = 0;
    if (total >= 1000)
        discount = total * 0.10;  // 10% discount
    else if (total >= 500)
        discount = total * 0.05;  // 5% discount

    cout << "Discount: Rs. " << discount << endl;
    cout << "Amount to Pay: Rs. " << total - discount << endl;
    cout << "==================================\n";
}

int main() {
    // Pre-defined grocery items
    string names[MAX] = {
        "Milk", "Bread", "Eggs", "Sugar", "Rice",
        "Tea", "Oil", "Salt", "Flour", "Soap"
    };

    double prices[MAX] = {
        150, 80, 200, 120, 250,
        90, 350, 30, 180, 100
    };

    int n = 10; // Number of available items

    int cartIndex[MAX];  
    int quantity[MAX];   
    int cartSize = 0;    

    int choice;

    do {
        cout << "\n---- Grocery Billing System ----\n";
        cout << "1. Show Items\n";
        cout << "2. Add to Cart\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            showItems(names, prices, n);
        }
        else if (choice == 2) {
            showItems(names, prices, n);
            addToCart(cartIndex, quantity, cartSize);
        }
        else if (choice == 3) {
            if (cartSize == 0)
                cout << "Cart is empty! Add items first.\n";
            else
                generateBill(names, prices, cartIndex, quantity, cartSize);
        }

    } while (choice != 4);

    cout << "Thank you for shopping!\n";

    return 0;
}
