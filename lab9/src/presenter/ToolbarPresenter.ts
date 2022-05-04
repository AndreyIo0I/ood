import {Canvas} from '../domain/Canvas'
import {ToolbarView} from '../view/ToolbarView'
import {Shape} from '../domain/Shape'
import {ShapeType} from '../common/ShapeType'

class ToolbarPresenter {
	private model: Canvas
	private view: ToolbarView

	constructor(model: Canvas, view: ToolbarView) {
		this.model = model
		this.view = view

		this.view.getAddShapeSignal().add(type => this.addShape(type))
	}

	private addShape(type: ShapeType) {
		const shapeSize = 100
		const newShapeFrame = {
			left: (this.model.getWidth() - shapeSize) / 2,
			top: (this.model.getHeight() - shapeSize) / 2  - 50,
			width: shapeSize,
			height: shapeSize,
		}
		this.model.insertShape(new Shape(type, newShapeFrame, this.model.getWidth(), this.model.getHeight()))
	}

	getOnSaveSignal() {
		return this.view.getOnSaveSignal()
	}

	getOnUploadSignal() {
		return this.view.getOnUploadSignal()
	}
}

export {
	ToolbarPresenter,
}