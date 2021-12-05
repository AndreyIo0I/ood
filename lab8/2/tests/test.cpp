#define CATCH_CONFIG_MAIN

#include <GumBallMachineWithState.h>
#include "catch.hpp"
#include <string>
#include <NaiveGumBallMachine.h>

template <typename GumballMachineType>
void TestGumballMachine(std::string& header)
{
	GumballMachineType m(3);

	SECTION("correct start state")
	{
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("unchanged after crank turning without quarter")
	{
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("unchanged after quarter ejecting without quarter")
	{
		m.EjectQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("is waiting for turn of crank after quarter inserting")
	{
		m.InsertQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 1\n"
									   "Machine is waiting for turn of crank\n");
	}

	SECTION("-gumball after crank turning with quarter inside")
	{
		m.InsertQuarter();
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 2 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("5 quarters limit")
	{
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 5\n"
									   "Machine is waiting for turn of crank\n");

		m.InsertQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 5\n"
									   "Machine is waiting for turn of crank\n");
	}

	SECTION("some quarters usage")
	{
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.TurnCrank();
		m.TurnCrank();
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 0 gumballs\n"
									   "Quarters: 1\n"
									   "Machine is sold out\n");
	}

	SECTION("ejecting quarter")
	{
		m.InsertQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 1\n"
									   "Machine is waiting for turn of crank\n");
		m.EjectQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("sold out")
	{
		m.InsertQuarter();
		m.TurnCrank();
		m.InsertQuarter();
		m.TurnCrank();
		m.InsertQuarter();
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 0 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is sold out\n");

		m.InsertQuarter();
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 0 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is sold out\n");
	}

	SECTION("sold out from creation")
	{
		GumballMachineType m0(0);
		CHECK(m0.ToString() == header + "Inventory: 0 gumballs\n"
										"Quarters: 0\n"
										"Machine is sold out\n");
	}

	SECTION("ejecting quarters when sold out")
	{
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.InsertQuarter();
		m.TurnCrank();
		m.TurnCrank();
		m.TurnCrank();

		m.EjectQuarter();
		CHECK(m.ToString() == header + "Inventory: 0 gumballs\n"
									   "Quarters: 0\n"
									   "Machine is sold out\n");
	}
}

TEST_CASE("GumballMachine with state tests")
{
	std::string header = "\nMighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\n";

	TestGumballMachine<with_state::CGumballMachine>(header);
}

TEST_CASE("naive GumballMachine tests")
{
	std::string header = "\nMighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016\n";

	TestGumballMachine<naive::CGumballMachine>(header);
}
