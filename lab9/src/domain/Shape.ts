import {Frame} from '../common/Frame'
import {Signal} from '../common/Signal'
import {ShapeType} from '../common/ShapeType'
import {generateUUID} from '../common/generateUUID'
import {Position} from '../common/Position'

class Shape {
	private frame: Frame
	private readonly id: string
	private readonly type: ShapeType
	private onFrameChangedSignal: Signal<Frame> = new Signal<Frame>()

	constructor(type: ShapeType, frame: Frame) {
		this.type = type
		this.frame = frame
		this.id = generateUUID()
	}

	getFrame(): Frame {
		return this.frame
	}

	setFrame(frame: Frame): void {
		this.frame = frame
		this.onFrameChangedSignal.dispatch(this.frame)
	}

	setPosition({left, top}: Position): void {
		this.frame.left = left
		this.frame.top = top
		this.onFrameChangedSignal.dispatch(this.frame)
	}

	getOnFrameChangedSignal(): Signal<Frame> {
		return this.onFrameChangedSignal
	}

	getType(): ShapeType {
		return this.type
	}

	getId(): string {
		return this.id
	}

	remove() {
		this.onFrameChangedSignal.removeAll()
	}
}

export {
	Shape,
}