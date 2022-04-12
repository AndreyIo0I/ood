#include <fstream>
#include <memory>
#include "CSlide.h"
#include "CSvgCanvas.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "CTriangle.h"
#include "CGroupShape.h"

using namespace std;

int main()
{
	CSlide slide(800, 600);
	slide.SetBackgroundColor(0x8888FF);

	auto land = make_shared<CRectangle>(0, 300, 800, 600);
	land->GetFillStyle().SetColor(0x336644);
	slide.InsertShape(land);

	auto sun = make_shared<CEllipse>(600, 100, 50, 50);
	sun->GetFillStyle().SetColor(0xFFFF00);
	sun->GetOutlineStyle().SetColor(0xFFAA00);
	slide.InsertShape(sun);

	auto hill = make_shared<CTriangle>(800, 280, 800, 300, 500, 300);
	hill->GetFillStyle().SetColor(0x336644);
	slide.InsertShape(hill);

	auto walls = make_shared<CRectangle>(200, 200, 400, 400);
	walls->GetFillStyle().SetColor(0xCA5541);

	auto window = make_shared<CRectangle>(260, 260, 340, 340);
	window->GetFillStyle().SetColor(0x99AAEE);

	auto roof = make_shared<CTriangle>(140, 200, 460, 200, 300, 120);
	roof->GetFillStyle().SetColor(0x444444);

	auto house = make_shared<CGroupShape>();
	house->InsertShape(walls);
	house->InsertShape(window);
	house->InsertShape(roof);
	house->SetFrame({60, 120, 400, 320});
	slide.InsertShape(house);

	ofstream output("picture.svg");
	CSvgCanvas canvas(output, 800, 600);
	slide.Draw(canvas);
}
