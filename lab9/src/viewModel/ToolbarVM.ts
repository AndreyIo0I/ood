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
			const newShapeFrame = {left: this.model.getWidth() / 2 - 50, top: this.model.getHeight() / 2  - 50, width: 100, height: 100}
			this.model.insertShape(new Shape(type, newShapeFrame))
		})
	}
}

export {
	ToolbarVM,
}