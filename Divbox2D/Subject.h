#pragma once
#include <list>
#include <string>
#include "ISubject.h"

class Subject : public ISubject
{
private:
	std::list<IObserver*> listObserverer;
	std::string message;
public:

	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;

	void CreateMessage(std::string _message = "Empty");
	void HowManyObserver();

};

