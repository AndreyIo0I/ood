import {Canvas} from '../domain/Canvas'
import {CanvasView} from '../view/CanvasView'
import {ShapeViewFactory} from '../view/ShapeViewFactory'
import {ShapePresenter} from './ShapePresenter'
import {SelectionPresenter} from './SelectionPresenter'
import {Shape} from '../domain/Shape'
import {SelectionView} from '../view/SelectionView'

class CanvasPresenter {
	private readonly canvasModel: Canvas
	private readonly canvasView: CanvasView
	private shapesPresenter: Array<ShapePresenter> = []
	private selectedShape?: Shape = null
	private selectionPresenter?: SelectionPresenter

	constructor(canvasModel: Canvas, canvasView: CanvasView) {
		this.canvasModel = canvasModel
		this.canvasView = canvasView

		this.canvasModel.getShapes().forEach(shapeModel => this.addShape(shapeModel))
		this.canvasModel.getOnShapeInsertedSignal().add(shapeModel => this.addShape(shapeModel))

		this.canvasModel.getOnShapeDeletedSignal().add(shapeModel => {
			const shapePresenter = this.shapesPresenter.find(presenter => presenter.getModel() === shapeModel)
			shapePresenter.remove()
			this.removeSelection()
		})

		this.canvasView.getOnClickSignal().add(() => this.removeSelection())
	}

	private addShape(shapeModel: Shape) {
		const shapeView = ShapeViewFactory.createShape(shapeModel.getType(), shapeModel.getFrame())
		const shapePresenter = new ShapePresenter(this, shapeModel, shapeView)
		this.shapesPresenter.push(shapePresenter)
		this.canvasView.addShape(shapeView)

		shapeView.getOnMouseDownSignal().add(() => {
			this.removeSelection()
			this.selectedShape = shapeModel
			const selectionView = new SelectionView(shapeModel.getFrame())
			this.selectionPresenter = new SelectionPresenter(this, shapePresenter, selectionView)
			selectionView.appendTo(this.canvasView.getElement())
		})

		shapeModel.getOnFrameChangedSignal().add(frame => shapeView.setFrame(frame))
	}

	getView() {
		return this.canvasView
	}

	getModel() {
		return this.canvasModel
	}

	private removeSelection() {
		if (this.selectionPresenter) {
			this.selectionPresenter.remove()
			this.selectionPresenter = null
		}
	}
}

export {
	CanvasPresenter,
}