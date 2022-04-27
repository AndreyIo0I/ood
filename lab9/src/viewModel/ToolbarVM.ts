import {Canvas} from '../domain/Canvas'
import {ToolbarView} from '../view/ToolbarView'
import {Shape} from '../domain/Shape'

class ToolbarVM {
	private model: Canvas
	private view: ToolbarView

	constructor(model: Canvas, view: ToolbarView) {
		this.model = model
		this.view = view

		this.view.getAddShapeSignal().add(type => {
			const shapeSize = 100
			const newShapeFrame = {
				left: (this.model.getWidth() - shapeSize) / 2,
				top: (this.model.getHeight() - shapeSize) / 2  - 50,
				width: shapeSize,
				height: shapeSize,
			}
			this.model.insertShape(new Shape(type, newShapeFrame, model.getWidth(), model.getHeight()))
		})
	}

	getOnSaveSignal() {
		return this.view.getOnSaveSignal()
	}

	getOnUploadSignal() {
		return this.view.getOnUploadSignal()
	}
}

export {
	ToolbarVM,
}