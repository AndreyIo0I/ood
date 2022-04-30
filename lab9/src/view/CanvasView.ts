import {ShapeView} from './ShapeView'
import {View} from './View'

class CanvasView extends View<SVGSVGElement> {
	constructor(width: number, height: number) {
		super(document.createElementNS('http://www.w3.org/2000/svg', 'svg'))
		this.element.classList.add('canvas')
		this.setWidth(width)
		this.setHeight(height)
	}

	addShape(shape: ShapeView): void {
		shape.render(this.getElement())
	}

	setWidth(width: number): void {
		this.element.style.width = `${width}px`
	}

	setHeight(height: number): void {
		this.element.style.height = `${height}px`
	}
}

export {
	CanvasView,
}