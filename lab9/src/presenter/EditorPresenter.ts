import {EditorView} from '../view/EditorView'
import {Canvas} from '../domain/Canvas'
import {CanvasPresenter} from './CanvasPresenter'
import {ToolbarPresenter} from './ToolbarPresenter'
import {CanvasSaver} from '../common/CanvasSaver'

class EditorPresenter {
	private model: Canvas
	private view: EditorView
	private canvasVM: CanvasPresenter
	private toolbarVM: ToolbarPresenter

	constructor() {
		this.setModel(new Canvas())
	}

	private setModel(canvas: Canvas) {
		this.model = canvas
		this.view = new EditorView()

		this.canvasVM = new CanvasPresenter(this.model, this.view.getCanvas())
		this.toolbarVM = new ToolbarPresenter(this.model, this.view.getToolbar())

		this.toolbarVM.getOnSaveSignal().add(() => {
			CanvasSaver.save(this.model)
		})

		this.toolbarVM.getOnUploadSignal().add(file => {
			this.view.remove()
			this.setModel(CanvasSaver.upload(file))
		})

		this.view.appendTo(document.body)
	}
}

export {
	EditorPresenter,
}