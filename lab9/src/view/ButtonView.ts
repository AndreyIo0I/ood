import {View} from './View'

class ButtonView extends View<HTMLElement> {
	constructor(onClick: () => void, className: string = '', text: string = '') {
		super(document.createElement('div'))
		this.addRemovable(this.getOnClickSignal().add(() => onClick()))
		this.element.classList.add('button')
		if (className)
			this.element.classList.add(className)
		this.element.textContent = text
	}
}

export {
	ButtonView,
}