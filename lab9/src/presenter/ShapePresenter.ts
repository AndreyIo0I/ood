import {Shape} from '../domain/Shape'
import {ShapeView} from '../view/ShapeView'
import {WindowSignals} from '../view/WindowSignals'
import {CanvasPresenter} from './CanvasPresenter'

class ShapePresenter {
	private readonly windowView = new WindowSignals()
	private readonly model: Shape
	private readonly view: ShapeView
	private readonly canvasPresenter: CanvasPresenter

	constructor(canvasPresenter: CanvasPresenter, model: Shape, view: ShapeView) {
		this.canvasPresenter = canvasPresenter
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
		this.canvasPresenter.getView().getOnMouseMoveSignal().add(onMouseMove)
		this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasPresenter.getView().getOnMouseMoveSignal().remove(onMouseMove))
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
	ShapePresenter,
}