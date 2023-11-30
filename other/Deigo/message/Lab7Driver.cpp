//============================================================================
// Name        : Ivan Temesvari
// This program will test the Message class functionality.
//============================================================================

#include "Message.h"
#include <iostream>
using namespace std;
int main(){
	Message newMessage;   //call the default constructor; instantiate/create a Message object
	newMessage.print();
	cout << endl;
	Message my_message = Message("Jim", "Bob");
	my_message.append("Hello buddy! I miss you!");
	my_message.print();
	cout << endl;
	Time changed(5,45,30);  //5:45:30 am
	my_message.setTime(changed);
	my_message.print();
	return 0;
}