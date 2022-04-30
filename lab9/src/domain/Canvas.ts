import {Shape} from './Shape'
import {Signal} from '../common/Signal'

class Canvas {
	private readonly width
	private readonly height
	private shapes: Array<Shape> = []
	private onShapeInsertedSignal: Signal<Shape> = new Signal<Shape>()
	private shapeDeletedSignal: Signal<Shape> = new Signal<Shape>()

	constructor(width: number = 800, height: number = 600) {
		this.width = width
		this.height = height
	}

	getWidth(): number {
		return this.width
	}

	getHeight(): number {
		return this.height
	}

	getShapes(): ReadonlyArray<Shape> {
		return this.shapes
	}

	insertShape(shape: Shape, index: number = this.shapes.length): void {
		if (!this.shapes.includes(shape)) {
			this.shapes.splice(index, 0, shape)
			this.onShapeInsertedSignal.dispatch(shape)
		}
	}

	getOnShapeInsertedSignal(): Signal<Shape> {
		return this.onShapeInsertedSignal
	}

	deleteShape(shape: Shape): void {
		this.shapes = this.shapes.filter(v => v !== shape)
		this.shapeDeletedSignal.dispatch(shape)
	}
// todo привести к одному стилю название
	onShapeDeletedSignal(): Signal<Shape> {
		return this.shapeDeletedSignal
	}
}

export {
	Canvas,
}