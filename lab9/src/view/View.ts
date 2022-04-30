import {Signal} from '../common/Signal'
import {createFnRemovableSubscribe} from './createFnRemovableSubscribe'

abstract class View<TElement extends Element> {
	protected readonly element: TElement
	private removables: Array<() => void> = []
	private onClickSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	private onMouseDownSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	private onMouseMoveSignal: Signal<MouseEvent> = new Signal<MouseEvent>()

	protected constructor(element: TElement) {
		this.element = element
		this.initSignals()
	}

	private initSignals() {
		this.addRemovable(() => this.onClickSignal.removeAll())
		this.addRemovable(() => this.onMouseDownSignal.removeAll())
		this.addRemovable(() => this.onMouseMoveSignal.removeAll())
		this.addRemovableListener(this.element, 'click', (event: MouseEvent) => {
			if (event.target === this.element)
				this.onClickSignal.dispatch(event)
		})
		this.addRemovableListener(this.element, 'mousedown', (event: MouseEvent) => {
			if (event.target === this.element)
				this.onMouseDownSignal.dispatch(event)
		})
		this.addRemovableListener(this.element, 'mousemove', (event: MouseEvent) => {
				this.onMouseMoveSignal.dispatch(event)
		})
	}

	protected addRemovable(removable: () => void) {
		this.removables.push(removable)
	}

	protected addRemovableListener<T extends Event>(element: TElement, type: string, fn: (event: T) => void): void {
		this.addRemovable(createFnRemovableSubscribe(element, type, fn))
	}

	getOnClickSignal(): Signal<MouseEvent> {
		return this.onClickSignal
	}

	getOnMouseDownSignal(): Signal<MouseEvent> {
		return this.onMouseDownSignal
	}

	getOnMouseMoveSignal(): Signal<MouseEvent> {
		return this.onMouseMoveSignal
	}

	getElement(): TElement {
		return this.element
	}

	remove(): void {
		this.removables.forEach(remove => remove())
		this.getElement().remove()
	}

	appendTo(parent: Element): void {
		parent.appendChild(this.getElement())
	}
}

export {
	View,
}