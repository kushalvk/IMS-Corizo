#include <iostream>
#include <fstream>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    float price;
    Product* next;
};

Product* head = NULL;

void addProduct() {
    Product* p = new Product();
    cout << "Enter Product ID: ";
    cin >> p->id;
    cout << "Enter Product Name: ";
    cin >> p->name;
    cout << "Enter Quantity: ";
    cin >> p->quantity;
    cout << "Enter Price: ";
    cin >> p->price;

    p->next = head;
    head = p;
    cout << "Product Added Successfully\n";
}

void displayProducts() {
    Product* temp = head;
    cout << "\nID\tName\tQty\tPrice\n";
    while (temp) {
        cout << temp->id << "\t" << temp->name << "\t" << temp->quantity << "\t" << temp->price << endl;
        temp = temp->next;
    }
}

void searchProduct() {
    int id;
    cout << "Enter Product ID to Search: ";
    cin >> id;
    Product* temp = head;
    while (temp) {
        if (temp->id == id) {
            cout << "Product Found: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Product Not Found\n";
}

void updateProduct() {
    int id;
    cout << "Enter Product ID to Update: ";
    cin >> id;
    Product* temp = head;
    while (temp) {
        if (temp->id == id) {
            cout << "Enter New Quantity: ";
            cin >> temp->quantity;
            cout << "Enter New Price: ";
            cin >> temp->price;
            cout << "Product Updated\n";
            return;
        }
        temp = temp->next;
    }
}

void deleteProduct() {
    int id;
    cout << "Enter Product ID to Delete: ";
    cin >> id;

    Product *temp = head, *prev = NULL;

    while (temp) {
        if (temp->id == id) {
            if (!prev)
                head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            cout << "Product Deleted\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void saveToFile() {
    ofstream file("inventory.txt");
    Product* temp = head;
    while (temp) {
        file << temp->id << " " << temp->name << " " << temp->quantity << " " << temp->price << endl;
        temp = temp->next;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("inventory.txt");
    while (!file.eof()) {
        Product* p = new Product();
        file >> p->id >> p->name >> p->quantity >> p->price;
        p->next = head;
        head = p;
    }
    file.close();
}

int main() {
    loadFromFile();
    int choice;
    do {
        cout << "\n1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit\nChoice: ";
        cin >> choice;

        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
        }
    } while(choice != 6);

    saveToFile();
    return 0;
}
