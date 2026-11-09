
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
};

const string FILE_NAME = "inventory.txt";

// Load products from file
vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file(FILE_NAME);

    Product p;

    while (file >> p.id
                >> quoted(p.name)
                >> p.quantity
                >> p.price) {
        products.push_back(p);
    }

    file.close();
    return products;
}

// Save products to file
void saveProducts(const vector<Product>& products) {
    ofstream file(FILE_NAME);

    for (const auto& p : products) {
        file << p.id << " "
             << quoted(p.name) << " "
             << p.quantity << " "
             << p.price << "\n";
    }

    file.close();
}

// Add product
void addProduct(vector<Product>& products) {
    Product p;

    cout << "Enter Product ID: ";
    if (!(cin >> p.id)) {
        cout << "Invalid ID!\n";
        return;
    }

    for (const auto& item : products) {
        if (item.id == p.id) {
            cout << "Product ID already exists!\n";
            return;
        }
    }

    cout << "Enter Product Name: ";
    cin >> ws;
    getline(cin, p.name);

    cout << "Enter Quantity: ";
    if (!(cin >> p.quantity) || p.quantity < 0) {
        cout << "Invalid quantity!\n";
        return;
    }

    cout << "Enter Price: ";
    if (!(cin >> p.price) || p.price < 0) {
        cout << "Invalid price!\n";
        return;
    }

    products.push_back(p);
    saveProducts(products);

    cout << "Product added successfully!\n";
}

// Display products
void viewProducts(const vector<Product>& products) {
    if (products.empty()) {
        cout << "Inventory is empty!\n";
        return;
    }

    cout << "\n========== INVENTORY ==========\n";

    cout << left << setw(10) << "ID"
         << setw(20) << "NAME"
         << setw(12) << "QUANTITY"
         << "PRICE\n";

    for (const auto& p : products) {
        cout << left << setw(10) << p.id
             << setw(20) << p.name
             << setw(12) << p.quantity
             << "Rs. " << fixed << setprecision(2)
             << p.price << "\n";
    }
}

// Search product
void searchProduct(const vector<Product>& products) {
    int id;

    cout << "Enter Product ID: ";
    if (!(cin >> id)) {
        cout << "Invalid ID!\n";
        return;
    }

    for (const auto& p : products) {
        if (p.id == id) {
            cout << "\nProduct Found!\n";
            cout << "Name: " << p.name << "\n";
            cout << "Quantity: " << p.quantity << "\n";
            cout << "Price: Rs. " << p.price << "\n";
            return;
        }
    }

    cout << "Product not found!\n";
}

// Update stock
void updateStock(vector<Product>& products) {
    int id, quantity;

    cout << "Enter Product ID: ";
    if (!(cin >> id)) {
        cout << "Invalid ID!\n";
        return;
    }

    for (auto& p : products) {
        if (p.id == id) {
            cout << "Enter new quantity: ";

            if (!(cin >> quantity) || quantity < 0) {
                cout << "Invalid quantity!\n";
                return;
            }

            p.quantity = quantity;
            saveProducts(products);

            cout << "Stock updated successfully!\n";
            return;
        }
    }

    cout << "Product not found!\n";
}

// Main function
int main() {
    vector<Product> products = loadProducts();
    int choice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Stock\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            return 1;
        }

        switch (choice) {
            case 1:
                addProduct(products);
                break;

            case 2:
                viewProducts(products);
                break;

            case 3:
                searchProduct(products);
                break;

            case 4:
                updateStock(products);
                break;

            case 5:
                saveProducts(products);
                cout << "Inventory saved. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
