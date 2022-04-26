import {ShapeType} from '../common/ShapeType'
import {TriangleView} from './TriangleView'
import {Frame} from '../common/Frame'
import {EllipseView} from './EllipseView'
import {RectangleView} from './RectangleView'
import {ShapeView} from './ShapeView'

class ShapeViewFactory {
	static createShape(type: ShapeType, frame: Frame): ShapeView {
		switch (type) {
			case 'triangle':
				return new TriangleView(frame)
			case 'rectangle':
				return new RectangleView(frame)
			case 'ellipse':
				return new EllipseView(frame)
		}
	}
}

export {
	ShapeViewFactory,
}