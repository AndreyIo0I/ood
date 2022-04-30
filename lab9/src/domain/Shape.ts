import {Frame} from '../common/Frame'
import {Signal} from '../common/Signal'
import {ShapeType} from '../common/ShapeType'
import {Position} from '../common/Position'

class Shape {
	private static readonly minSize: number = 20
	private frame: Frame
	private readonly type: ShapeType
	private readonly canvasWidth: number
	private readonly canvasHeight: number
	private onFrameChangedSignal: Signal<Frame> = new Signal<Frame>()

	constructor(type: ShapeType, frame: Frame, canvasWidth: number, canvasHeight: number) {
		this.type = type
		this.frame = frame
		this.canvasWidth = canvasWidth
		this.canvasHeight = canvasHeight
	}

	getFrame(): Readonly<Frame> {
		return this.frame
	}

	setFrame(frame: Frame): void {
		if (frame.height >= Shape.minSize && frame.width >= Shape.minSize) {
			this.frame = frame
			if (frame.left < 0)
				this.frame.left = 0
			if (frame.top < 0)
				this.frame.top = 0
			if (frame.left + frame.width > this.canvasWidth)
				this.frame.left = this.canvasWidth - frame.width
			if (frame.top + frame.height > this.canvasHeight)
				this.frame.top = this.canvasHeight - frame.height
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

	// todo удалить
	remove() {
		this.onFrameChangedSignal.removeAll()
	}
}

export {
	Shape,
}