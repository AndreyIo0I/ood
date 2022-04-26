import {Frame} from '../common/Frame'
import {ShapeView} from './ShapeView'

class RectangleView extends ShapeView {
	constructor(frame: Frame) {
		super()
		this.element = document.createElementNS('http://www.w3.org/2000/svg', 'rect')
		this.element.setAttribute('fill', 'green')
		this.initSignals()
		this.setFrame(frame)
	}

	setFrame(frame: Frame) {
		super.setFrame(frame)
		this.element.setAttribute('x', frame.left.toString())
		this.element.setAttribute('y', frame.top.toString())
		this.element.setAttribute('width', frame.width.toString())
		this.element.setAttribute('height', frame.height.toString())
	}
}

export {
	RectangleView,
}