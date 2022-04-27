import {ButtonView} from './ButtonView'
import {Signal} from '../common/Signal'
import {ShapeType} from '../common/ShapeType'
import {upload} from '../common/upload'

class ToolbarView {
	private readonly element: HTMLElement
	private buttons: Array<ButtonView> = []
	private addShapeSignal: Signal<ShapeType> = new Signal<ShapeType>()
	private onSaveSignal: Signal<void> = new Signal<void>()
	private onUploadSignal: Signal<string> = new Signal<string>()

	constructor() {
		this.element = document.createElement('div')
		this.element.classList.add('toolbar')

		this.addButton(() => this.onSaveSignal.dispatch(), '', 'Save')
		this.addButton(() => {
			upload(value => this.onUploadSignal.dispatch(value))
		}, '', 'Upload')
		this.addButton(() => this.addShapeSignal.dispatch('rectangle'), 'rectangle-button')
		this.addButton(() => this.addShapeSignal.dispatch('triangle'), 'triangle-button')
		this.addButton(() => this.addShapeSignal.dispatch('ellipse'), 'ellipse-button')
	}

	getAddShapeSignal() {
		return this.addShapeSignal
	}

	getOnSaveSignal() {
		return this.onSaveSignal
	}

	getOnUploadSignal() {
		return this.onUploadSignal
	}

	getElement(): HTMLElement {
		return this.element
	}

	render(parent: HTMLElement) {
		parent.appendChild(this.getElement())

		this.buttons.forEach(button => button.render(this.getElement()))
	}

	private addButton(onClick: () => void, className: string, text: string = '') {
		this.buttons.push(new ButtonView(onClick, className, text))
	}
}

export {
	ToolbarView,
}