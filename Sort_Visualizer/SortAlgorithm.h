#pragma once
#include <vector>
#include <list>
#include "Observer.h"

class SortAlgorithm : public Subject
{
public:

	virtual void sort(std::vector<int>& array) = 0;

	void attach(Observer* observer) override;
	void detach(Observer* observer) override;
	void notify() const override;

private:
	std::list<Observer*> observers;

};

inline void SortAlgorithm::attach(Observer* observer) { observers.push_back(observer); }
inline void SortAlgorithm::detach(Observer* observer) { observers.remove(observer); }
inline void SortAlgorithm::notify() const
{
	for (auto& observer : observers) { observer->update(); }
}
