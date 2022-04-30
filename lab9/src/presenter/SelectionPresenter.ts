import {SelectionView} from '../view/SelectionView'
import {WindowSignals} from '../view/WindowSignals'
import {ShapePresenter} from './ShapePresenter'
import {CanvasPresenter} from './CanvasPresenter'

class SelectionPresenter {
	private readonly windowView: WindowSignals = new WindowSignals()
	private readonly canvasVM: CanvasPresenter
	private readonly selectedShapeVM: ShapePresenter
	private readonly view: SelectionView

	constructor(canvasModel: CanvasPresenter, selectedShapeVM: ShapePresenter, view: SelectionView) {
		this.canvasVM = canvasModel
		this.selectedShapeVM = selectedShapeVM
		this.view = view

		this.windowView.onKeyDownSignal.add(event => this.onKeyDown(event))

		selectedShapeVM.getModel().getOnFrameChangedSignal().add(frame => view.setFrame(frame))

		this.view.getPoints()[0].getOnMouseDownSignal().add(() => {
			const onMouseMove = (moveEvent: MouseEvent) => {
				const currentFrame = selectedShapeVM.getModel().getFrame()
				selectedShapeVM.getModel().setFrame({
					left: currentFrame.left + moveEvent.movementX,
					top: currentFrame.top + moveEvent.movementY,
					width: currentFrame.width - moveEvent.movementX,
					height: currentFrame.height - moveEvent.movementY,
				})
			}
			this.canvasVM.getView().getOnMouseMoveSignal().add(onMouseMove)
			this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasVM.getView().getOnMouseMoveSignal().remove(onMouseMove))
		})
		this.view.getPoints()[1].getOnMouseDownSignal().add(() => {
			const onMouseMove = (moveEvent: MouseEvent) => {
				const currentFrame = selectedShapeVM.getModel().getFrame()
				selectedShapeVM.getModel().setFrame({
					left: currentFrame.left,
					top: currentFrame.top + moveEvent.movementY,
					width: currentFrame.width + moveEvent.movementX,
					height: currentFrame.height - moveEvent.movementY,
				})
			}
			this.canvasVM.getView().getOnMouseMoveSignal().add(onMouseMove)
			this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasVM.getView().getOnMouseMoveSignal().remove(onMouseMove))
		})
		this.view.getPoints()[2].getOnMouseDownSignal().add(() => {
			const onMouseMove = (moveEvent: MouseEvent) => {
				const currentFrame = selectedShapeVM.getModel().getFrame()
				selectedShapeVM.getModel().setFrame({
					left: currentFrame.left + moveEvent.movementX,
					top: currentFrame.top,
					width: currentFrame.width - moveEvent.movementX,
					height: currentFrame.height + moveEvent.movementY,
				})
			}
			this.canvasVM.getView().getOnMouseMoveSignal().add(onMouseMove)
			this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasVM.getView().getOnMouseMoveSignal().remove(onMouseMove))
		})
		this.view.getPoints()[3].getOnMouseDownSignal().add(() => {
			const onMouseMove = (moveEvent: MouseEvent) => {
				const currentFrame = selectedShapeVM.getModel().getFrame()
				selectedShapeVM.getModel().setFrame({
					left: currentFrame.left,
					top: currentFrame.top,
					width: currentFrame.width + moveEvent.movementX,
					height: currentFrame.height + moveEvent.movementY,
				})
			}
			this.canvasVM.getView().getOnMouseMoveSignal().add(onMouseMove)
			this.windowView.onMouseUpSignal.addCallOnce(() => this.canvasVM.getView().getOnMouseMoveSignal().remove(onMouseMove))
		})
	}

	getView() {
		return this.view
	}

	private onKeyDown(event: KeyboardEvent): void {
		if (event.code === 'Delete')
			this.canvasVM.getModel().deleteShape(this.selectedShapeVM.getModel())
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