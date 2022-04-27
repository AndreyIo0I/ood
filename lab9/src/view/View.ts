import {Signal} from '../common/Signal'
import {createFnRemovableSubscribe} from './createFnRemovableSubscribe'

abstract class View<TElement extends Element> {
	protected readonly element: TElement
	protected removables: Array<() => void> = []
	protected onClickSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	protected onMouseDownSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	private onMouseMoveSignal: Signal<MouseEvent> = new Signal<MouseEvent>()

	protected constructor(element: TElement) {
		this.element = element
		this.initSignals()
	}

	protected initSignals() {
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

	addRemovable(removable: () => void) {
		this.removables.push(removable)
	}

	addRemovableListener<T extends Event>(element: TElement, type: string, fn: (event: T) => void): void {
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

	remove() {
		this.removables.forEach(remove => remove())
		this.getElement().remove()
	}

	render(parent: Element): void {
		parent.appendChild(this.getElement())
	}
}

export {
	View,
}