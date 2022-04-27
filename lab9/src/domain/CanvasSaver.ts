import {Canvas} from './Canvas'
import {save} from '../common/save'
import {Shape} from './Shape'
import {ShapeType} from '../common/ShapeType'
import {Frame} from '../common/Frame'

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

	static serializeCanvas(canvas: Canvas): string {
		return JSON.stringify({
			shapes: canvas.getShapes().map(shape => ({
				type: shape.getType(),
				frame: shape.getFrame(),
			})),
			width: canvas.getWidth(),
			height: canvas.getHeight(),
		})
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
}

export {
	CanvasSaver,
}