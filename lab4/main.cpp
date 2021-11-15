
#include <CRectangle.h>
#include <memory>
#include <CShapeFactory.h>
#include <CDesigner.h>
#include <CPainter.h>
#include <CSvgCanvas.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	try
	{
		CShapeFactory factory;
		CDesigner designer(factory);

		CPictureDraft picDraft = designer.CreateDraft(cin);

		CSvgCanvas canvas;

		CPainter painter;
		painter.DrawPicture(picDraft, canvas);

		ofstream outFile("my.svg", ios::out);

		canvas.Print(outFile);
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}