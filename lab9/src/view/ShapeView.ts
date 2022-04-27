import {Frame} from '../common/Frame'
import {View} from './View'

abstract class ShapeView extends View<SVGElement> {
	protected frame: Frame = {left: 0, top: 0, width: 0, height: 0}

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
}

export {
	ShapeView,
}