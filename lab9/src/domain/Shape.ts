import {Frame} from '../common/Frame'
import {Signal} from '../common/Signal'
import {ShapeType} from '../common/ShapeType'
import {generateUUID} from '../common/generateUUID'
import {Position} from '../common/Position'

class Shape {
	private static readonly minSize: number = 20
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
		if (frame.height >= Shape.minSize && frame.width >= Shape.minSize) {
			this.frame = frame
			this.onFrameChangedSignal.dispatch(this.frame)
		}
	}

	setPosition({left, top}: Position): void {
		this.setFrame({
			left,
			top,
			width: this.frame.width,
			height: this.frame.height,
		})
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