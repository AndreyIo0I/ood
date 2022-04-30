import {ButtonView} from './ButtonView'
import {Signal} from '../common/Signal'
import {ShapeType} from '../common/ShapeType'
import {upload} from '../common/upload'
import {View} from './View'

class ToolbarView extends View<HTMLElement> {
	private addShapeSignal: Signal<ShapeType> = new Signal<ShapeType>()
	private onSaveSignal: Signal<void> = new Signal<void>()
	private onUploadSignal: Signal<string> = new Signal<string>()

	constructor() {
		super(document.createElement('div'))
		this.element.classList.add('toolbar')

		this.addButton(() => this.onSaveSignal.dispatch(), '', 'Save')
		this.addButton(() => {
			upload(value => this.onUploadSignal.dispatch(value))
		}, '', 'Upload')
		this.addButton(() => this.addShapeSignal.dispatch('rectangle'), 'rectangle-button')
		this.addButton(() => this.addShapeSignal.dispatch('triangle'), 'triangle-button')
		this.addButton(() => this.addShapeSignal.dispatch('ellipse'), 'ellipse-button')
	}

	getAddShapeSignal(): Signal<ShapeType> {
		return this.addShapeSignal
	}

	getOnSaveSignal(): Signal<void> {
		return this.onSaveSignal
	}

	getOnUploadSignal(): Signal<string> {
		return this.onUploadSignal
	}

	getElement(): HTMLElement {
		return this.element
	}

	private addButton(onClick: () => void, className: string, text: string = '') {
		const button = new ButtonView(onClick, className, text)
		button.appendTo(this.getElement())
	}
}

export {
	ToolbarView,
}