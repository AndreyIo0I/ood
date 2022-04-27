import {EditorView} from '../view/EditorView'
import {Canvas} from '../domain/Canvas'
import {CanvasVM} from './CanvasVM'
import {ToolbarVM} from './ToolbarVM'
import {CanvasSaver} from '../common/CanvasSaver'

class EditorVM {
	private model: Canvas
	private view: EditorView
	private canvasVM: CanvasVM
	private toolbarVM: ToolbarVM

	constructor() {
		this.setModel(new Canvas())
	}

	private setModel(canvas: Canvas) {
		this.model = canvas
		this.view = new EditorView()

		this.canvasVM = new CanvasVM(this.model, this.view.getCanvas())
		this.toolbarVM = new ToolbarVM(this.model, this.view.getToolbar())

		this.toolbarVM.getOnSaveSignal().add(() => {
			CanvasSaver.save(this.model)
		})

		this.toolbarVM.getOnUploadSignal().add(file => {
			this.view.remove()
			this.setModel(CanvasSaver.upload(file))
		})

		this.view.render(document.body)
	}
}

export {
	EditorVM,
}