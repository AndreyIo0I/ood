import {SelectionView} from '../view/SelectionView'
import {WindowSignals} from '../view/WindowSignals'
import {ShapePresenter} from './ShapePresenter'
import {CanvasPresenter} from './CanvasPresenter'
import {RectangleView} from '../view/RectangleView'
import {Frame} from '../common/Frame'

class SelectionPresenter {
	private readonly windowView: WindowSignals = new WindowSignals()
	private readonly canvasPresenter: CanvasPresenter
	private readonly selectedShapePresenter: ShapePresenter
	private readonly view: SelectionView

	constructor(canvasPresenter: CanvasPresenter, selectedShapePresenter: ShapePresenter, view: SelectionView) {
		this.canvasPresenter = canvasPresenter
		this.selectedShapePresenter = selectedShapePresenter
		this.view = view

		this.windowView.onKeyDownSignal.add(event => this.onKeyDown(event))

		selectedShapePresenter.getModel().getOnFrameChangedSignal().add(frame => view.setFrame(frame))

		this.movePoint(this.view.getPoints()[0], (initialFrame, moveEvent) => ({
			left: moveEvent.offsetX,
			top: moveEvent.offsetY,
			width: initialFrame.width + initialFrame.left - moveEvent.offsetX,
			height: initialFrame.height + initialFrame.top - moveEvent.offsetY,
		}))
		this.movePoint(this.view.getPoints()[1], (initialFrame, moveEvent) => ({
			left: initialFrame.left,
			top: moveEvent.offsetY,
			width: moveEvent.offsetX - initialFrame.left,
			height: initialFrame.height + initialFrame.top - moveEvent.offsetY,
		}))
		this.movePoint(this.view.getPoints()[2], (initialFrame, moveEvent) => ({
			left: moveEvent.offsetX,
			top: initialFrame.top,
			width: initialFrame.left + initialFrame.width - moveEvent.offsetX,
			height: moveEvent.offsetY - initialFrame.top,
		}))
		this.movePoint(this.view.getPoints()[3], (initialFrame, moveEvent) => ({
			left: initialFrame.left,
			top: initialFrame.top,
			width: moveEvent.offsetX - initialFrame.left,
			height: moveEvent.offsetY - initialFrame.top,
		}))
	}

	private movePoint(point: RectangleView, getNewFrame: (initialFrame: Frame, moveEvent: MouseEvent) => Frame) {
		point.getOnMouseDownSignal().add(() => {
			const initialFrame = this.selectedShapePresenter.getModel().getFrame()
			const onMouseMove = (moveEvent: MouseEvent) => this.selectedShapePresenter.getModel().setFrame(getNewFrame(initialFrame, moveEvent))

			this.canvasPresenter.getView().getOnMouseMoveSignal().add(onMouseMove)
			this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasPresenter.getView().getOnMouseMoveSignal().remove(onMouseMove))
		})
	}

	getView() {
		return this.view
	}

	private onKeyDown(event: KeyboardEvent): void {
		if (event.code === 'Delete')
			this.canvasPresenter.getModel().deleteShape(this.selectedShapePresenter.getModel())
	}

	remove(): void {
		this.windowView.onMouseMoveSignal.removeAll()
		this.windowView.onKeyDownSignal.removeAll()
		this.view.remove()
	}
}

export {
	SelectionPresenter,
}