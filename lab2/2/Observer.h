#pragma once

#include <set>
#include <functional>

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer) override
	{
		m_observers.insert(&observer);
	}

	void NotifyObservers() override
	{
		m_notifyingObservers = true;
		T data = GetChangedData();
		for (auto & observer : m_observers)
		{
			observer->Update(data);
		}
		EraseObservers();
		m_notifyingObservers = false;
	}

	void RemoveObserver(ObserverType & observer) override
	{
		if (m_notifyingObservers)
		{
			m_observersToErase.insert(&observer);
		}
		else
		{
			m_observers.erase(&observer);
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	void EraseObservers()
	{
		for (auto & observer : m_observersToErase)
		{
			m_observers.erase(observer);
		}
		m_observersToErase.clear();
	}

	std::set<ObserverType *> m_observers, m_observersToErase;
	bool m_notifyingObservers = false;
};
