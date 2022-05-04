import {Canvas} from '../domain/Canvas'
import {save} from './save'
import {Shape} from '../domain/Shape'
import {ShapeType} from './ShapeType'
import {Frame} from './Frame'

type CanvasData = {
	shapes: Array<ShapeData>,
	width: number,
	height: number,
}

type ShapeData = {
	type: ShapeType,
	frame: Frame,
}

class CanvasSaver {
	static save(canvas: Canvas): void {
		save(CanvasSaver.serializeCanvas(canvas), 'doc')
	}

	static upload(file: string): Canvas {
		const data: CanvasData = JSON.parse(file)
		const canvas = new Canvas(data.width, data.height)

		data.shapes.forEach(shapeData => {
			const shape = new Shape(shapeData.type, shapeData.frame, canvas.getWidth(), canvas.getHeight())
			canvas.insertShape(shape)
		})

		return canvas
	}

	private static serializeCanvas(canvas: Canvas): string {
		return JSON.stringify({
			shapes: canvas.getShapes().map(shape => ({
				type: shape.getType(),
				frame: shape.getFrame(),
			})),
			width: canvas.getWidth(),
			height: canvas.getHeight(),
		})
	}
}

export {
	CanvasSaver,
}