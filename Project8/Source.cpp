#include<iostream>
#include <fstream>
using namespace std;

class card {
	string brand;
	string owner;
	int phonenumber;
	string address;
	string sphere;
public:
	card() = default;
	card(string b, string o, int p, string a, string s) :brand(b), owner(o), phonenumber(p), address(a), sphere(s) {}
	string getbrand() {
		return brand;
	}
	string getowner() {
		return owner;
	}
	string getaddress() {
		return address;
	}
	string getsphere() {
		return sphere;
	}
	int getphonenumber() {
		return phonenumber;
	}
	void setbrand(string b) {
		brand = b;
	}
	void setowner(string b) {
		owner = b;
	}
	void setphonenumber(int p) {
		phonenumber = p;
	}
	void setaddress(string b) {
		address = b;
	}
	void setsphere(string b) {
		sphere = b;
	}
	void print() {
		cout << "brand: " << brand << "\towner: " << owner << "\tphonenumber" << phonenumber << "\taddress: " << address << "\tsphere: " << sphere << endl;
	}
};
class notes {
	card* arr;
	int size;
	
public:
	notes() {
		size =1;
		arr = new card[1];
	}
	notes(int s):size(s){
		arr = new card[size];
	}
	void filler() {
		string temp;
		int temp1;
		for (int i = 0;i < size;i++) {
			cout << "enter brand: ";
			cin >> temp;
			arr[i].setbrand(temp);
			cin.ignore();
			cout << "enter owner: ";
			cin >> temp;
			arr[i].setowner(temp);
			cin.ignore();
			cout << "enter phonenumber: ";
			cin >> temp1;
			arr[i].setphonenumber(temp1);
			cin.ignore();
			cout << "enter address: ";
			cin >> temp;
			arr[i].setaddress(temp);
			cin.ignore();
			cout << "enter sphere: ";
			cin >> temp;
			arr[i].setsphere(temp);
			cin.ignore();
		}
		tofile();
	}
	void searchbrand(string n) {
		for (int i = 0;i < size;i++) {
			if (arr[i].getbrand() == n) {
				arr[i].print();
			}
		}
	}
	void searchowner(string n) {
		for (int i = 0;i < size;i++) {
			if (arr[i].getowner() == n) {
				arr[i].print();
			}
		}
	}
	void searchphonenumber(int n) {
		for (int i = 0;i < size;i++) {
			if (arr[i].getphonenumber() == n) {
				arr[i].print();
			}
		}
	}
	void searchsphere(string n) {
		for (int i = 0;i < size;i++) {
			if (arr[i].getsphere() == n) {
				arr[i].print();
			}
		}
	}
	void printall() {
		for (int i = 0;i < size;i++) {
			arr[i].print();
		}
	}
	void tofile() {
		ofstream out("Text.txt", ios::trunc);
		if (out.is_open())
		{
			for (int i = 0;i < size;i++) {
				out << arr[i].getbrand() << ' ' << arr[i].getowner() << ' ' << arr[i].getphonenumber() << ' ' << arr[i].getaddress() << ' ' << arr[i].getsphere() << '\n';
			}

			out.close();
		}
		else
		{
			cout << "Could not open the file" << endl;
		}
	}
};

int main() {
	notes obj(2);
	obj.filler();

}