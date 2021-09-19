#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "Observer.h"

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
	explicit CObserver(CTestObservable & observable)
	:m_observable(&observable)
	{
	}

	void Update(bool const& data) override
	{
		m_observable->RemoveObserver(*this);
	}

private:
	CTestObservable* m_observable;
};

SCENARIO("Observer removes themself from update fn")
{
	CTestObservable observable;
	CObserver observer1(observable);
	CObserver observer2(observable);

	observable.RegisterObserver(observer1);
	observable.RegisterObserver(observer2);

	observable.SetMeasurements(true);
	observable.SetMeasurements(false);
}