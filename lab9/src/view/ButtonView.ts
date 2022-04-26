
class ButtonView {
	private readonly element: HTMLElement

	constructor(onClick: () => void, className: string = '', text: string = '') {
		this.element = document.createElement('div')
		this.element.addEventListener('click', () => onClick())
		this.element.classList.add('button')
		if (className)
			this.element.classList.add(className)
		this.element.textContent = text
	}

	getElement(): HTMLElement {
		return this.element
	}

	render(parent: HTMLElement) {
		parent.appendChild(this.getElement())
	}
}

export {
	ButtonView,
}