import {Shape} from '../domain/Shape'
import {ShapeView} from '../view/ShapeView'
import {WindowSignals} from '../view/WindowSignals'
import {CanvasVM} from './CanvasVM'

class ShapeVM {
	private readonly windowView = new WindowSignals()
	private readonly model: Shape
	private readonly view: ShapeView
	private readonly canvasVM: CanvasVM

	constructor(canvasModel: CanvasVM, model: Shape, view: ShapeView) {
		this.canvasVM = canvasModel
		this.model = model
		this.view = view

		model.getOnFrameChangedSignal().add(frame => view.setFrame(frame))

		this.view.getOnMouseDownSignal().add(event => this.moveShape(event))
	}

	moveShape(event: MouseEvent) {
		const x = event.offsetX - this.model.getFrame().left
		const y = event.offsetY - this.model.getFrame().top
		const onMouseMove = (moveEvent: MouseEvent) => {
			this.model.setPosition({left: moveEvent.offsetX - x, top: moveEvent.offsetY - y})
		}
		this.canvasVM.getView().getOnMouseMoveSignal().add(onMouseMove)
		this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasVM.getView().getOnMouseMoveSignal().remove(onMouseMove))
	}

	getView(): ShapeView {
		return this.view
	}

	getModel(): Shape {
		return this.model
	}

	remove() {
		this.view.remove()
	}
}

export {
	ShapeVM,
}