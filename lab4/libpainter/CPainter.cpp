
#include "CPainter.h"

void CPainter::DrawPicture(CPictureDraft& draft, ICanvas& canvas) const
{
	int n = draft.GetShapeCount();
	for (int i = 0; i < n; ++i)
	{
		draft.GetShape(i).Draw(canvas);
	}
}
