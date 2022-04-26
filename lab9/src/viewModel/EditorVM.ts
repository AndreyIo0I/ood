import {EditorView} from '../view/EditorView'
import {Canvas} from '../domain/Canvas'
import {CanvasVM} from './CanvasVM'
import {ToolbarVM} from './ToolbarVM'

class EditorVM {
	private model: Canvas
	private view: EditorView
	private canvasVM: CanvasVM
	private toolbarVM: ToolbarVM

	constructor(canvasModel: Canvas, view: EditorView) {
		this.model = canvasModel
		this.view = view

		this.canvasVM = new CanvasVM(canvasModel, this.view.getCanvas())
		this.toolbarVM = new ToolbarVM(canvasModel, this.view.getToolbar())
	}
}

export {
	EditorVM,
}