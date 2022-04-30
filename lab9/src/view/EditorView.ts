import {CanvasView} from './CanvasView'
import {ToolbarView} from './ToolbarView'
import {View} from './View'

class EditorView extends View<HTMLElement> {
	private readonly canvas: CanvasView
	private readonly toolbar: ToolbarView

	constructor() {
		super(document.createElement('div'))
		this.element.classList.add('editor')

		this.canvas = new CanvasView(800, 600)
		this.toolbar = new ToolbarView()
	}

	getToolbar(): ToolbarView {
		return this.toolbar
	}

	getCanvas(): CanvasView {
		return this.canvas
	}

	appendTo(parent: HTMLElement) {
		super.appendTo(parent)

		this.toolbar.appendTo(this.getElement())
		this.canvas.appendTo(this.getElement())
	}
}

export {
	EditorView,
}