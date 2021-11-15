#define CATCH_CONFIG_MAIN

#include <CDesigner.h>
#include <CShapeFactory.h>
#include "catch.hpp"

using namespace std;

class CMockShape1: public CShape
{
public:
	CMockShape1()
		: CShape(Color::Black)
	{
	}

	void Draw(ICanvas& canvas) const override {}
};

class CMockShape2: public CShape
{
public:
	CMockShape2()
		: CShape(Color::Black)
	{
	}

	void Draw(ICanvas& canvas) const override {}
};

class CMockFactory: public IShapeFactory
{
public:
	std::unique_ptr<CShape> CreateShape(const std::string& description) override
	{
		if (description == "1")
			return make_unique<CMockShape1>();
		else if (description == "2")
			return make_unique<CMockShape2>();
		else
			throw exception("unhandled mock type");
	}
};

TEST_CASE("Using Designer")
{
	CMockFactory factory;
	CDesigner designer(factory);
	SECTION("to the end of input")
	{
//		istringstream input("2\n1\n");
//		auto draft = designer.CreateDraft(input);
//		CHECK(draft.GetShapeCount() == 2);
	}
}
