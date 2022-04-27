import {ShapeView} from './ShapeView'
import {View} from './View'

class CanvasView extends View<SVGSVGElement> {
	//todo лишние поля
	private width: number
	private height: number
	private shapes: Array<ShapeView> = []

	constructor(width: number, height: number) {
		super(document.createElementNS('http://www.w3.org/2000/svg', 'svg'))
		this.element.classList.add('canvas')
		this.setWidth(width)
		this.setHeight(height)
	}

	addShape(shape: ShapeView): void {
		this.shapes.push(shape)
		shape.render(this.getElement())
	}

	deleteShape(shape: ShapeView): void {
		this.shapes = this.shapes.filter(v => v !== shape)
		shape.remove()
	}

	setWidth(width: number): void {
		this.width = width
		this.element.style.width = `${width}px`
	}

	setHeight(height: number): void {
		this.height = height
		this.element.style.height = `${height}px`
	}
}

export {
	CanvasView,
}