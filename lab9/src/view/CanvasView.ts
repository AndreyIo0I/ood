import {ShapeView} from './ShapeView'
import {Signal} from '../common/Signal'

class CanvasView {
	private width: number
	private height: number
	private shapes: Array<ShapeView> = []
	private readonly element: SVGElement
	private onClickSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	private onMouseMoveSignal: Signal<MouseEvent> = new Signal<MouseEvent>()

	constructor(width: number, height: number) {
		this.element = document.createElementNS('http://www.w3.org/2000/svg', 'svg')
		this.element.classList.add('canvas')
		this.setWidth(width)
		this.setHeight(height)
		this.element.addEventListener('mousemove', event => this.onMouseMoveSignal.dispatch(event))
		this.element.addEventListener('click', event => event.target === this.getElement() && this.onClickSignal.dispatch(event))
	}

	getOnMouseMoveSignal() {
		return this.onMouseMoveSignal
	}

	getOnClickSignal() {
		return this.onClickSignal
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

	getElement(): SVGElement {
		return this.element
	}

	render(parent: Element): void {
		parent.appendChild(this.getElement())
	}
}

export {
	CanvasView,
}