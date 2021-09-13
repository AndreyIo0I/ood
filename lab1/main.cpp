#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>

using namespace std;

//---------------------------------------------------------------------
void DanceWaltz() {
	cout << "I'm Dancing waltz" << endl;
}

void DanceMinuet() {
	cout << "I'm Dancing minuet" << endl;
}
//---------------------------------------------------------------------
class FlyWithWings
{
public:
	void operator()()
	{
		cout << "I'm flying with wings " << ++m_count << endl;
	}

private:
	int m_count = 0;
};

function<void()> MakeFlyWithWings()
{
	int flightCount = 0;
	return [flightCount] () mutable {
		cout << "I'm flying with wings " << ++flightCount;
	};
}

//---------------------------------------------------------------------
void QuackBehavior() {
	cout << "Quack Quack!!!" << endl;
}
void SqueakBehavior() {
	cout << "Squeek!!!" << endl;
}
//---------------------------------------------------------------------
class Duck
{
public:
	Duck(function<void()> flyBehavior,
		 function<void()> quackBehavior,
		 function<void()> danceBehavior)
		: m_danceBehavior(move(danceBehavior))
		, m_quackBehavior(move(quackBehavior))
	{
		assert(m_quackBehavior);
		SetFlyBehavior(move(flyBehavior));
	}
	void Quack() const
	{
		m_quackBehavior();
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Fly()
	{
		m_flyBehavior();
	}
	virtual void Dance()
	{
		m_danceBehavior();
	}
	void SetFlyBehavior(function<void()> flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = move(flyBehavior);
	}
	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	function<void()> m_flyBehavior;
	function<void()> m_quackBehavior;
	function<void()> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings(), QuackBehavior, DanceWaltz)
	{
	}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};

class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyWithWings(), QuackBehavior, DanceMinuet)
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};

class DecoyDuck : public Duck
{
public:
	DecoyDuck()
		: Duck([](){}, [](){}, [](){})
	{
	}
	void Display() const override
	{
		cout << "I'm decoy duck" << endl;
	}
	void Dance() override {}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck([](){}, SqueakBehavior, [](){})
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
	void Dance() override {}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck([](){}, QuackBehavior, [](){})
	{
	}
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
	void Dance() override {}
};
//---------------------------------------------------------------------
void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck& duck)
{
	DrawDuck(duck);
	duck.Quack();
	duck.Fly();
	duck.Dance();
	cout << endl;
}

int main()
{
	MallardDuck mallardDuck;
	PlayWithDuck(mallardDuck);
	PlayWithDuck(mallardDuck);

	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);

	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);

	DecoyDuck decoyDuck;
	PlayWithDuck(decoyDuck);

	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	modelDuck.SetFlyBehavior(FlyWithWings());
	PlayWithDuck(modelDuck);
}
