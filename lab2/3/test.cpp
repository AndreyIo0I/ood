#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "Observer.h"
#include <vector>

using namespace std;

vector<int> order;

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
	: m_observable(&observable)
	, m_id(id)
	{
	}

	void Update(bool const& data) override
	{
		order.push_back(m_id);
		m_observable->RemoveObserver(*this);
	}

private:
	CTestObservable* m_observable;
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

	observable.RegisterObserver(observer1, 2);
	observable.RegisterObserver(observer2, 3);

	observable.SetMeasurements(true);
	CHECK((order[0] == 2 && order[1] == 1));
}