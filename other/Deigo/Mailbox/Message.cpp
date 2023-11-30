/*
 * Message.cpp
 * Implementation of the Message class.
 *  Created on: Oct 7, 2019
 *      Author: itemesva
 */

#include "Message.h"
#include <iostream>
using namespace std;

//default constructor.
Message::Message(){
	sender = "";
	recipient = "";
	message = "";
	stamp = Time();   //there is no time stamp yet.
}

Message::Message(string s, string r){
	sender = s;
	recipient = r;
	message = "";
	stamp = Time();   //set the time of this Message to the current time (now).
}

Message::Message(string s, string r, string m){
	sender = s;
	recipient = r;
	message = m;
	stamp = Time();   //set the time of this Message to the current time (now).
}

Message::Message(string s, string r, string m, Time& t){
	sender = s;
	recipient = r;
	message = "";
	stamp = t;
}

void Message::append(string m){
	//complete this code.
    message = message + m;
}

void Message::print(){
	//complete this code.
	//Call the to_string function here.
	//Tip: use the scope resolution operator "::" when you call the Message to_string function,
	//e.g. Message::to_string(). If you don't tell the compiler you want to use the Message to_string function
	//it will try to call the std to_string function which will give a compilation error.
    string out = Message::to_string();
    cout << out << endl;
}

string Message::to_string(){
	string theMessage = "";
	//finish formatting and building theMessage string appropriately before returning it.
    theMessage = "From: " + sender + "\n" + "To: " + recipient + "\n\n" + message + "\n\n" + stamp.to_string();
	return theMessage;
}


void Message::setTime(Time& t){
	//complete this code.
    stamp = t;
}
