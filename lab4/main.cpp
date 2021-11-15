
#include <CRectangle.h>
#include <CShapeFactory.h>
#include <CDesigner.h>
#include <CPainter.h>
#include <CSvgCanvas.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	CShapeFactory factory;
	CDesigner designer(factory);

	CPictureDraft draft = designer.CreateDraft(cin);

	CSvgCanvas canvas;

	CPainter painter;
	painter.DrawPicture(draft, canvas);

	ofstream outFile("my.svg", ios::out);

	canvas.Print(outFile);
	return 0;
}