import {EditorView} from '../view/EditorView'
import {Canvas} from '../domain/Canvas'
import {CanvasPresenter} from './CanvasPresenter'
import {ToolbarPresenter} from './ToolbarPresenter'
import {CanvasSaver} from '../common/CanvasSaver'

class EditorPresenter {
	private model: Canvas
	private view: EditorView
	private canvasPresenter: CanvasPresenter
	private toolbarPresenter: ToolbarPresenter

	constructor() {
		this.setModel(new Canvas())
	}

	private setModel(canvas: Canvas) {
		this.model = canvas
		this.view = new EditorView()

		this.canvasPresenter = new CanvasPresenter(this.model, this.view.getCanvas())
		this.toolbarPresenter = new ToolbarPresenter(this.model, this.view.getToolbar())

		this.toolbarPresenter.getOnSaveSignal().add(() => {
			CanvasSaver.save(this.model)
		})

		this.toolbarPresenter.getOnUploadSignal().add(file => {
			this.view.remove()
			this.setModel(CanvasSaver.upload(file))
		})

		this.view.appendTo(document.body)
	}
}

export {
	EditorPresenter,
}