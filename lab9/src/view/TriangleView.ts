import {Frame} from '../common/Frame'
import {ShapeView} from './ShapeView'

class TriangleView extends ShapeView {
	constructor(frame: Frame) {
		super(document.createElementNS('http://www.w3.org/2000/svg', 'polygon'))
		this.element.setAttribute('fill', 'blue')
		this.setFrame(frame)
	}

	setFrame(frame: Frame) {
		super.setFrame(frame)
		const {left, top, height, width} = frame
		const x1 = left + width / 2
		const y1 = top
		const x2 = left
		const y2 = top + height
		const x3 = left + width
		const y3 = top + height
		this.element.setAttribute('points', `${x1} ${y1}, ${x2} ${y2}, ${x3} ${y3}`)
	}
}

export {
	TriangleView,
}