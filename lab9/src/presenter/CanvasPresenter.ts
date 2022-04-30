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
	private shapesVM: Array<ShapePresenter> = []
	private selectedShape?: Shape = null
	private selectionVM: SelectionPresenter

	constructor(canvasModel: Canvas, canvasView: CanvasView) {
		this.canvasModel = canvasModel
		this.canvasView = canvasView

		this.canvasModel.getShapes().forEach(shapeModel => {
			this.addShape(shapeModel)
		})

		this.canvasModel.getOnShapeInsertedSignal().add(shapeModel => {
			this.addShape(shapeModel)
		})

		this.canvasModel.getOnShapeDeletedSignal().add(shapeModel => {
			const shapeVM = this.shapesVM.find(vm => vm.getModel() === shapeModel)
			shapeVM.remove()
			this.removeSelection()
		})

		this.canvasView.getOnClickSignal().add(() => {
			this.removeSelection()
		})
	}

	private addShape(shapeModel: Shape) {
		const shapeView = ShapeViewFactory.createShape(shapeModel.getType(), shapeModel.getFrame())
		const shapeVM = new ShapePresenter(this, shapeModel, shapeView)
		this.shapesVM.push(shapeVM)
		this.canvasView .addShape(shapeView)

		shapeView.getOnMouseDownSignal().add(() => {
			this.removeSelection()
			this.selectedShape = shapeModel
			const selectionView = new SelectionView(shapeModel.getFrame())
			this.selectionVM = new SelectionPresenter(this, shapeVM, selectionView)
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

	removeSelection() {
		if (this.selectionVM) {
			this.selectionVM.remove()
			this.selectionVM = null
		}
	}
}

export {
	CanvasPresenter,
}