import {CanvasView} from './CanvasView'
import {ToolbarView} from './ToolbarView'

class EditorView {
	private readonly element: HTMLElement
	private readonly canvas: CanvasView
	private readonly toolbar: ToolbarView

	constructor() {
		this.element = document.createElement('div')
		this.element.classList.add('editor')

		this.canvas = new CanvasView(800, 600)

		this.toolbar = new ToolbarView()
	}

	getElement(): HTMLElement {
		return this.element
	}

	getToolbar(): ToolbarView {
		return this.toolbar
	}

	getCanvas(): CanvasView {
		return this.canvas
	}

	render(parent: HTMLElement) {
		parent.appendChild(this.getElement())

		this.toolbar.render(this.getElement())
		this.canvas.render(this.getElement())
	}

	remove() {
		this.getElement().remove()
	}
}

export {
	EditorView,
}