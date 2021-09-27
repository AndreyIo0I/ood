#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "Observer.h"
#include <vector>

using namespace std;

vector<int> order;
vector<int> observableOrder;

class CTestObservable : public CObservable<bool>
{
public:
	void SetMeasurements(bool value)
	{
		m_value = value;
		NotifyObservers();
	}
protected:
	bool GetChangedData()const override
	{
		return m_value;
	}
private:
	bool m_value = false;
};

class CObserver: public IObserver<bool>
{
public:
	explicit CObserver(CTestObservable & observable, int id = 0)
	: m_observable1(&observable)
	, m_observable2(&observable)
	, m_id(id)
	{
	}

	explicit CObserver(CTestObservable & observable1, CTestObservable & observable2, int id = 0)
		: m_observable1(&observable1)
		, m_observable2(&observable2)
		, m_id(id)
	{
	}

	void Update(IObservable<bool>* observable, bool const& data) override
	{
		order.push_back(m_id);
		if (observable == m_observable1)
		{
			observableOrder.push_back(1);
			m_observable1->RemoveObserver(*this);
		}
		else if (observable == m_observable2)
		{
			observableOrder.push_back(2);
			m_observable1->RemoveObserver(*this);
		}
	}

private:
	CTestObservable *m_observable1, *m_observable2;
	int m_id = 0;
};

TEST_CASE("Observer removes themself from update fn")
{
	CTestObservable observable;
	CObserver observer1(observable);
	CObserver observer2(observable);

	observable.RegisterObserver(observer1);
	observable.RegisterObserver(observer2);

	CHECK_NOTHROW(observable.SetMeasurements(true));
}

TEST_CASE("Use observers with priority")
{
	CTestObservable observable;
	CObserver observer1(observable, 1);
	CObserver observer2(observable, 2);

	observable.RegisterObserver(observer1);
	observable.RegisterObserver(observer2);

	observable.SetMeasurements(true);
	CHECK((order[0] == 2 && order[1] == 1));
}

TEST_CASE("Use observers with different observables") //todo глянуть наблюдение за несколькими в лекции
{
	CTestObservable observable1, observable2;
	CObserver observer(observable1, observable2, 1);

	observable1.RegisterObserver(observer);
	observable2.RegisterObserver(observer);

	observable2.SetMeasurements(true);
	observable1.SetMeasurements(false);

	CHECK((observableOrder[0] == 2 && observableOrder[1] == 1));
}