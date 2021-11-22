#define CATCH_CONFIG_MAIN

#include <app.h>
#include "catch.hpp"

TEST_CASE("Test CModernRendererAdapter")
{
	std::ostringstream output;
	modern_graphics_lib::CModernGraphicsRenderer renderer(output);

	SECTION("create and delete adapter")
	{
		{
			app::CModernRendererAdapter adaptedRenderer(renderer);
		}
		REQUIRE(output.str() == "<draw>\n"
								"</draw>\n");
	}

	SECTION("interacting with CModernGraphicsRenderer as with ICanvas via adapter")
	{
		{
			app::CModernRendererAdapter adaptedRenderer(renderer);
			adaptedRenderer.MoveTo(0, 1);
			adaptedRenderer.LineTo(3, 4);
			adaptedRenderer.MoveTo(-7, 3000);
			adaptedRenderer.LineTo(0, 0);
		}
		REQUIRE(output.str() == "<draw>\n"
							    "  <line fromX=\"0\" fromY=\"1\" toX=\"3\" toY=\"4\"/>\n"
								"  <line fromX=\"-7\" fromY=\"3000\" toX=\"0\" toY=\"0\"/>\n"
							    "</draw>\n");
	}
}
