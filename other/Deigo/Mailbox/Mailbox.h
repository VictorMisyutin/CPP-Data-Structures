/*
 * Mailbox.h
 *
 *  Created on: Oct 29, 2018
 *      Author: itemesva
 */

#ifndef MAILBOX_H_
#define MAILBOX_H_

#include "Message.h" //this
#include <vector>
#include <iostream>

using namespace std;
class Mailbox{
	public:
		Mailbox();   //default constructor
		void add_message(Message m);
		Message get_message(int i) const;  //const means we cannot change any of the data members inside this function
		void remove_message(int i);
		void print();


	private:   //data members
		int messageCount;
		vector<Message> inbox;
};

Mailbox::Mailbox(){
	inbox.clear();
    messageCount=0;
}

void Mailbox::add_message(Message m){
	inbox.push_back(m);
	messageCount += 1;
}

Message Mailbox::get_message(int i) const{
	return inbox[i];
}

void Mailbox::remove_message(int i){
	if (i == 0){
	inbox.erase (inbox.begin());
	}
	else{
		inbox.erase (inbox.begin()+i-1);
	}
}

void Mailbox::print(){
	cout << "Mailbox: " << endl;
    for (int i = 0; i < inbox.size(); i++){
		cout << "Message " << i+1 << endl;
    	inbox[i].print();
		cout << endl;
    }

}

#endif /* MAILBOX_H_ */
