import {Frame} from '../common/Frame'
import {ShapeView} from './ShapeView'

class EllipseView extends ShapeView {
	constructor(frame: Frame) {
		super()
		this.element = document.createElementNS('http://www.w3.org/2000/svg', 'ellipse')
		this.element.setAttribute('fill', 'red')
		this.initSignals()
		this.setFrame(frame)
	}

	setFrame(frame: Frame) {
		super.setFrame(frame)
		this.element.setAttribute('cx', (frame.left + frame.width / 2).toString())
		this.element.setAttribute('cy', (frame.top + frame.height / 2).toString())
		this.element.setAttribute('rx', (frame.width / 2).toString())
		this.element.setAttribute('ry', (frame.height / 2).toString())
	}
}

export {
	EllipseView,
}