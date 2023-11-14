#include "Utils.h"
#include "Subject.h"

void Subject::Attach(IObserver* observer)
{
	listObserverer.push_back(observer);
}

void Subject::Detach(IObserver* observer)
{
	listObserverer.remove(observer);
}

void Subject::Notify()
{
	std::list<IObserver*>::iterator it = listObserverer.begin();
	HowManyObserver();
	while (it != listObserverer.end())
	{
		(*it)->Update(message);
		++it;
	}
}



void Subject::CreateMessage(std::string _message)
{
	this->message = _message;
	Notify();
}

void Subject::HowManyObserver() {
	std::cout << "There are " << listObserverer.size() << " observers in the list.\n";
}
