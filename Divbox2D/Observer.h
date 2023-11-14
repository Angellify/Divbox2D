#pragma once
#include <string>
#include <iostream>
#include "Subject.h"
#include "IObserver.h"
class Observer : public IObserver
{
private:
	std::string messageFromSubject;
	Subject& subject;
	static int staticNumber;
	int number;
public:
	Observer(Subject& _subject);
	virtual ~Observer();

	void Update(const std::string& _messageFromSubject) override;

	void PrintInfo();
	void RemoveMeFromTheList();

	

};


