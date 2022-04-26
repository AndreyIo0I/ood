import {Signal} from '../common/Signal'
import {Frame} from '../common/Frame'

abstract class ShapeView {
	protected element: SVGElement
	protected frame: Frame = {left: 0, top: 0, width: 0, height: 0}
	protected onClickSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	protected onMouseDownSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	protected onMouseUpSignal: Signal<MouseEvent> = new Signal<MouseEvent>()

	protected initSignals() {
		this.element.addEventListener('click', event => {
			if (event.target === this.element)
				this.onClickSignal.dispatch(event)
		})
		this.element.addEventListener('mousedown', event => {
			if (event.target === this.element)
				this.onMouseDownSignal.dispatch(event)
		})
	}

	getOnClickSignal(): Signal<MouseEvent> {
		return this.onClickSignal
	}

	getOnMouseDownSignal(): Signal<MouseEvent> {
		return this.onMouseDownSignal
	}

	getOnMouseUpSignal(): Signal<MouseEvent> {
		return this.onMouseUpSignal
	}

	setFrame(frame: Frame): void {
		this.frame = frame
	}

	setPosition(left: number, top: number): void {
		this.setFrame({
			...this.frame,
			left,
			top,
		})
	}

	getElement(): Element {
		return this.element
	}

	remove() {
		this.onClickSignal.removeAll()
		this.onMouseDownSignal.removeAll()
		this.onMouseUpSignal.removeAll()
		this.getElement().remove()
	}

	render(parent: Element): void {
		parent.appendChild(this.getElement())
	}
}

export {
	ShapeView,
}