#pragma once
#include <cstdint>
#include <format>
#include "shape_drawing_lib.h"
#include "graphics_lib.h"
#include "modern_graphics_lib.h"

// Пространство имен приложения (доступно для модификации)
namespace app
{
	void PaintPicture(shape_drawing_lib::CCanvasPainter & painter)
	{
		using namespace shape_drawing_lib;

		CTriangle triangle({ 10, 15 }, { 100, 200 }, { 150, 250 });
		CRectangle rectangle({ 30, 40 }, 18, 24);

		painter.Draw(rectangle);
		painter.Draw(triangle);
	}

	void PaintPictureOnCanvas()
	{
		graphics_lib::CCanvas simpleCanvas;
		shape_drawing_lib::CCanvasPainter painter(simpleCanvas);
		PaintPicture(painter);
	}

	class CModernRendererAdapter: public graphics_lib::ICanvas
	{
	public:
		CModernRendererAdapter(modern_graphics_lib::CModernGraphicsRenderer & modernRenderer)
			: m_modernRenderer(modernRenderer)
			, m_startPoint({0, 0})
		{
		}

		void MoveTo(int x, int y) override
		{
			m_startPoint = {x, y};
		}

		void LineTo(int x, int y) override
		{
			m_modernRenderer.DrawLine(m_startPoint, {x, y});
			MoveTo(x, y);
		}

	private:
		modern_graphics_lib::CModernGraphicsRenderer & m_modernRenderer;
		modern_graphics_lib::CPoint m_startPoint;
	};

	void PaintPictureOnModernGraphicsRenderer()
	{
		modern_graphics_lib::CModernGraphicsRenderer renderer(std::cout);

		CModernRendererAdapter adaptedRenderer(renderer);
		shape_drawing_lib::CCanvasPainter painter(adaptedRenderer);
		renderer.BeginDraw();
		PaintPicture(painter);
		renderer.EndDraw();
	}
}
