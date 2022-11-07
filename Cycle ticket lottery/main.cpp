#include "iostream"
#include "fstream"
#include "implementation.h"
using namespace std;
using namespace Records;

int interface();
void buy_ticket(Implement& im);
void displayCustomerData(Implement& im);
int main(){
    Implement implement;
    bool done = false;
    while (!done){
        int section = interface();
        switch (section) {
            case 1:
                buy_ticket(implement);
                break;
            case 2:
                cout << "Cannot use still now"<<endl;// display lucky number to choice for customer
                break;
            case 3:
                displayCustomerData(implement);
                break;
            case 4:
                done = true;
                break;
            default:
                break;
        }
    }
    return 0;
}
int interface(){
    int section=0;
    cout << "##**WELCOME TO OUR CYCLE TICKET LOTTERY**##"<<endl;
    cout << "==========================================="<<endl;
    cout << "1) BUY THE TICKET"<<endl;
    cout << "2) LIST OF TICKET TO BUY"<<endl;
    cout << "3) DISPLAY THE CUSTOMER DATA (ONLY ADMIN CAN ACCESS)"<<endl;
    cout << "4) Quit"<<endl;
    cout <<"-> : ";
    cin >> section;
    return section;
}
void buy_ticket(Implement& im){
    int lucky_number=0;
    string name;
    string ph_number;
    string address;
    cout << "Enter Lucky Number : ";
    cin >> lucky_number;
    if (lucky_number>=100 && lucky_number < 1000){
        int result = im.checkUserT(lucky_number);
        if (result == 0 ){
            cout << "Enter name : "; // cannot supply full name with space for now
            cin >> name;
            cout << "Enter phone number : ";
            cin >> ph_number;
            cout << "Enter your address : ";
            cin >> address;
            im.customerDataFile(lucky_number,name,ph_number,address);
        }else if (result == -1){
            cout << "Sorry, your lucky number is already exit\n"<<endl;
        }
    }else{
        cout << " Invalid lucky number!\n"<<endl;
    }
}
void displayCustomerData(Implement& im){
    string inPassword;
    cout <<"Enter password to access all data of customers : ";
    cin >> inPassword;
    if (inPassword == im.setPassword()){
        im.lotteryCustomerData();
    }else {
        cout << "Cannot access!\n"<<endl;
    }
}