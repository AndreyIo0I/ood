#define CATCH_CONFIG_MAIN

#include <GumBallMachineWithState.h>
#include "catch.hpp"
#include <string>

TEST_CASE("GumballMachine tests")
{
	std::string header = "\nMighty Gumball, Inc.\nC++-enabled Standing Gumball Model #2016 (with state)\n";
	with_state::CGumballMachine m(3);

	SECTION("correct start state")
	{
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("unchanged after crank turning without quarter")
	{
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("unchanged after quarter ejecting without quarter")
	{
		m.EjectQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("is waiting for turn of crank after quarter inserting")
	{
		m.InsertQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Machine is waiting for turn of crank\n");
	}

	SECTION("-gumball after crank turning with quarter inside")
	{
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Machine is waiting for quarter\n");
	}

	SECTION("ejecting quarter")
	{
		m.InsertQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
									   "Machine is waiting for turn of crank\n");
		m.EjectQuarter();
		CHECK(m.ToString() == header + "Inventory: 3 gumballs\n"
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
									   "Machine is sold out\n");

		m.InsertQuarter();
		m.TurnCrank();
		CHECK(m.ToString() == header + "Inventory: 0 gumballs\n"
									   "Machine is sold out\n");
	}

	SECTION("sold out from creation")
	{
		with_state::CGumballMachine m0(0);
		CHECK(m0.ToString() == header + "Inventory: 0 gumballs\n"
									   "Machine is sold out\n");
	}
}
