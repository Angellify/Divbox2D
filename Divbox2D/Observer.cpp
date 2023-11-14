#include "Utils.h"
#include "Observer.h"

int Observer::staticNumber = 0;

Observer::Observer(Subject& _subject) : subject(_subject)
{
	this->subject.Attach(this);
	std::cout << "Hi, I'm an observer" << ++Observer::staticNumber << "\".\n";
	this->number = Observer::staticNumber;
}

Observer::~Observer()
{
	std::cout << "Observer " << this->number << " goodbye" << '\n';
}

void Observer::Update(const std::string& _messageFromSubject)
{
	messageFromSubject = _messageFromSubject;
	PrintInfo();
}

void Observer::RemoveMeFromTheList()
{
	subject.Detach(this);
	std::cout << "Observer \"" << number << "\" removed from the list.\n";
}

void Observer::PrintInfo()
{
	std::cout << "Observer \"" << this->number << "\": a new message is available --> " << this->messageFromSubject << "\n";
}
