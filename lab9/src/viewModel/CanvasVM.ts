import {Canvas} from '../domain/Canvas'
import {CanvasView} from '../view/CanvasView'
import {ShapeViewFactory} from '../view/ShapeViewFactory'
import {ShapeVM} from './ShapeVM'
import {SelectionVM} from './SelectionVM'
import {Shape} from '../domain/Shape'
import {SelectionView} from '../view/SelectionView'

class CanvasVM {
	private readonly canvasModel: Canvas
	private readonly canvasView: CanvasView
	private shapesVM: Array<ShapeVM> = []
	private selectedShape?: Shape = null
	private selectionVM: SelectionVM

	constructor(canvasModel: Canvas, canvasView: CanvasView) {
		this.canvasModel = canvasModel
		this.canvasView = canvasView

		this.canvasModel.getOnShapeInsertedSignal().add(shapeModel => {
			const shapeView = ShapeViewFactory.createShape(shapeModel.getType(), shapeModel.getFrame())
			const shapeVM = new ShapeVM(this, shapeModel, shapeView)
			this.shapesVM.push(shapeVM)
			canvasView.addShape(shapeView)

			shapeView.getOnClickSignal().add(() => {
				this.removeSelection()
				this.selectedShape = shapeModel
				const selectionView = new SelectionView(shapeModel.getFrame())
				this.selectionVM = new SelectionVM(this, shapeVM, selectionView)
				selectionView.render(this.canvasView.getElement())
			})

			shapeModel.getOnFrameChangedSignal().add(frame => shapeView.setFrame(frame))
		})

		this.canvasModel.onShapeDeletedSignal().add(shapeModel => {
			const shapeVM = this.shapesVM.find(vm => vm.getModel() === shapeModel)
			shapeVM.remove()
			this.removeSelection()
		})

		this.canvasView.getOnClickSignal().add(() => {
			this.removeSelection()
		})
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
	CanvasVM,
}