import {Signal} from '../common/Signal'

class WindowSignals {
	public onMouseMoveSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	public onMouseUpSignal: Signal<MouseEvent> = new Signal<MouseEvent>()
	public onKeyDownSignal: Signal<KeyboardEvent> = new Signal<KeyboardEvent>()

	constructor() {
		window.addEventListener('mousemove', event => this.onMouseMoveSignal.dispatch(event))
		window.addEventListener('keydown', event => this.onKeyDownSignal.dispatch(event))
		window.addEventListener('mouseup', event => this.onMouseUpSignal.dispatch(event))
	}
}

export {
	WindowSignals,
}