import {ButtonView} from './ButtonView'
import {Signal} from '../common/Signal'
import {ShapeType} from '../common/ShapeType'

class ToolbarView {
	private readonly element: HTMLElement
	private buttons: Array<ButtonView> = []
	private addShapeSignal: Signal<ShapeType> = new Signal<ShapeType>()

	constructor() {
		this.element = document.createElement('div')
		this.element.classList.add('toolbar')

		this.addButton(() => this.addShapeSignal.dispatch('rectangle'), 'rectangle-button')
		this.addButton(() => this.addShapeSignal.dispatch('triangle'), 'triangle-button')
		this.addButton(() => this.addShapeSignal.dispatch('ellipse'), 'ellipse-button')
	}

	getAddShapeSignal() {
		return this.addShapeSignal
	}

	getElement(): HTMLElement {
		return this.element
	}

	render(parent: HTMLElement) {
		parent.appendChild(this.getElement())

		this.buttons.forEach(button => button.render(this.getElement()))
	}

	private addButton(onClick: () => void, className: string) {
		this.buttons.push(new ButtonView(onClick, className))
	}
}

export {
	ToolbarView,
}