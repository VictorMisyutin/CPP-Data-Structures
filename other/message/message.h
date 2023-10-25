//Ivan Temesvari
//March 12th, 2014
//Lab 7

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "ccc_time.h"
using namespace std;

class Message{
	public:
		Message(); //default constructor
		Message(string s, string r); //constructor
		Message(string s, string r, string m);  //another variation of a constructor.
		Message(string s, string r, string m, Time& t);  //another variation of a constructor.

		void append(string m);  //mutator
		string to_string(); //convert the Message into a string
		void print();  //use to_string()
		void setTime(Time& t);  //mutator


	private:  //data members
		string recipient;
		string sender;
		string message;
		Time stamp;
};
	
#endif